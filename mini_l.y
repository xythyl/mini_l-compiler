/*
    CS152 Phase 3

    Matthew Lauhakamin
    mlauh001@ucr.edu

    Melinda Pho
    mpho001@ucr.edu
*/

%{
  #define YY_NO_UNPUT
  #include <iostream>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string>
  #include <fstream>
  #include <sstream>
  #include <map>
  #include <stack>
  #include <vector>

  using namespace std;

  //#define YYDEBUG 1
  //#define YYPRINT(file, type, value) yyprint (file, type value)
  //yydebug = 1;

  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *message);
  extern int currLine;
  extern int currPos;

  string prog_name;

  stack<string> ident_stack;
  stack<string> var_stack;
  stack<string> comp_stack;
  stack<string> index_stack;
  stack<string> reverse_stack;
  stack<int> size_stack;
  stack<int> label_stack;
  stack<int> loop_stack;
  stack<int> predicate_stack;

  enum symbol_type {INT, INTARRAY};
  enum CONTEXT {READING, WRITING};

  struct Sym {
    int val;
    int size;
    string name;
    symbol_type type; 
    Sym():val(0),size(0),name(),type() {}
    Sym(int v, int s, string n, symbol_type t) 
    :val(v), size(s), name(n), type(t)
    {}
  };

  void add_symbol(Sym sym);
  void check_symbol(string name);
  map<string, Sym> symbol_table;

  ostringstream milhouse;
%}

%union{
  char* ident_str;
  int num_val;
}

%error-verbose
%debug
%start start
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY
%token END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP
%token CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN NUMBER IDENT

%token SUB ADD MULT DIV MOD

%token EQ NEQ LT GT LTE GTE

%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN

%type <ident_str> IDENT
%type <num_val> NUMBER

%right ASSIGN
%left OR
%left AND
%right NOT
%right UMINUS
%left ADD SUB
%left MULT DIV
%left L_SQUARE_BRACKET R_SQUARE_BRACKET
%left L_PAREN R_PAREN

%type<ident_str> var

%%

start: program 
     ;

program: 
       | function program 
       ;

function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declaration_block END_PARAMS BEGIN_LOCALS declaration_block END_LOCALS BEGIN_BODY statement SEMICOLON statement_block END_BODY {
            prog_name = string($2);
        }
        ;

declaration_block:  
                 | declaration SEMICOLON declaration_block 
                 ;

statement_block: 
               | statement SEMICOLON statement_block 
               ;

declaration: IDENT comma_ident_int COLON INTEGER {
               Sym sym(0,0,$1,INT); 
               add_symbol(sym);
             }
           | IDENT comma_ident_int_array COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
               Sym sym(0,$6,$1,INTARRAY);
               add_symbol(sym);
             }
           ;

comma_ident_int:   
        | COMMA IDENT comma_ident_int {
            Sym sym(0,0,$2,INT); 
            add_symbol(sym);
          }
       ;

comma_ident_int_array:   
        | COMMA IDENT comma_ident_int_array{
            /* FIX NUMBER */
            Sym sym(0,0,$2,INTARRAY);
            add_symbol(sym);
          }
        ;

/*
dec_block:  
         | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF 
         ;
*/

statement: var ASSIGN expression 
         | IF bool_exp THEN statement SEMICOLON statement_block else_block ENDIF 
         | WHILE bool_exp BEGINLOOP statement SEMICOLON statement_block ENDLOOP 
         | DO BEGINLOOP statement SEMICOLON statement_block ENDLOOP WHILE bool_exp 
         | READ var var_block 
         | WRITE var var_block 
         | CONTINUE 
         | RETURN expression 
         ;

else_block: 
          | ELSE statement SEMICOLON statement_block 
          ;

var_block:  
         | COMMA var var_block 
         ;

bool_exp: relation_and_expr rel_or 
        ;

rel_or: OR relation_and_expr rel_or 
      | 
      ;

relation_and_expr: relation_expr rel_and 
                 ;

rel_and: AND relation_and_expr 
       | 
       ;

relation_expr: rel_expr 
             | NOT rel_expr 
             ;

rel_expr: expression comp expression 
        | TRUE 
        | FALSE 
        | L_PAREN bool_exp R_PAREN 
        ;

comp: EQ 
    | NEQ 
    | LT 
    | GT 
    | LTE 
    | GTE 
    ;

expression: multiplicative_expr mult_expr 
          ;

mult_expr: ADD multiplicative_expr mult_expr 
         | SUB multiplicative_expr mult_expr 
         | 
         ;

multiplicative_expr: term mult_expr_term 
                   ;

mult_expr_term: MULT term mult_expr_term
              | DIV term mult_expr_term
              | MOD term mult_expr_term
              | 
              ;

term: SUB term_minus 
    | term_minus 
    | IDENT L_PAREN exp_comma_block R_PAREN 
    ;

term_minus: var 
          | NUMBER 
          | L_PAREN expression R_PAREN 
          ;

exp_comma_block: expression exp_comma_block2 
               |  
               ;

exp_comma_block2: 
                | COMMA expression exp_comma_block2 
                ;

var: IDENT {
       check_symbol($1);
       if(symbol_table[$1].type == INTARRAY) {
         yyerror("Symbol is of type int array");
       }
       else {
         $$ = $1;
         var_stack.push($1);
       }
     }
   | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
       check_symbol($1);
       if(symbol_table[$1].type == INT) {
         yyerror("Symbol is of type int");
       }
       else {
         $$ = $1;
       }
   }
   /* IDENT var_2 */
   ;
/*
var_2:  
     | L_SQUARE_BRACKET expression R_SQUARE_BRACKET 
     ;
*/
/*
ident: IDENT 
     ;

number: NUMBER
      ;
*/

%%

int main (int argc, char **argv) {
  if (argc > 1) {
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
      printf("syntax: %s filename\n", argv[0]);
    }
  }
  yyparse();
  ofstream file;
  file.open("mil_code.mil");
  file << milhouse.str();
  file.close();
  return 0;
}

void yyerror(const char *message) {
  printf("Syntax error on line %d: \"%s\" \n", currLine, message);
}

void yyerror(string message) {
  cout << "Syntax error on line " << currLine << ": " << message << endl;
}

void add_symbol(Sym s) {
  if(symbol_table.find(s.name) == symbol_table.end()) {
    symbol_table[s.name] = s;
  }
  else {
    string error = "Symbol already declared: " + s.name;
    yyerror(error);
  }
}

void check_symbol(string name) {
  if(symbol_table.find(name)==symbol_table.end()) {
    string error = "Symbol not declared: " + name;
    yyerror(error);
  }
}
