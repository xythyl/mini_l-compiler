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
  #include <string.h>
  #include <fstream>
  #include <sstream>
  #include <map>
  #include <stack>
  #include <vector>

  using namespace std;

  //#define YYDEBUG 1
  //#define YYPRINT(file, type, value) yyprint (file, type value)
  //yydebug = 1;
  enum symbol_type {INT, INTARRAY, FUNC};
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

  struct func {
    string name;
    symbol_type type;

  };

  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *message);
  extern int currLine;
  extern int currPos;

  stack<string> prog_name;
  stack < map < string, Sym > > symbol_table_stack;
  stack<string> ident_stack;
  stack<string> var_stack;
  stack<string> comp_stack;
  stack<string> index_stack;
  stack<string> reverse_stack;
  stack<int> size_stack;
  stack<int> label_stack;
  stack<int> loop_stack;
  stack<int> predicate_stack;

  vector<string> functions;
  vector<string> vars;
  
  void add_symbol(Sym sym);
  void check_symbol(string name);
  bool find_symbol(string name);
  void print_declarations();
  string make_temp();
  string make_temp();
  char* make_temp2();
  map<string, Sym> symbol_table;
  map<string, func> func_table;

  ostringstream milhouse;

  int temp_cnt = 0;
  int label_cnt = 0;
  
%}

%union{
  char* ident_str;
  int num_val;

  struct attributes {
    char name[255];
    char index[255];
    int type; //0 = int, 1 = int array, 2 = function
    int val;
    int size_attr;
  } attr;
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

//%type<ident_str> comma_ident
//%type<ident_str> declaration

%type<attr> var term_minus expression term declaration statement
%type<ident_str> comp

%%

start: program 
     ;

program: 
       | function program 
       ;

function: FUNCTION IDENT {milhouse << "func " << string($2) << endl;} SEMICOLON BEGIN_PARAMS declaration_block END_PARAMS  BEGIN_LOCALS declaration_block END_LOCALS {print_declarations();} BEGIN_BODY statement SEMICOLON statement_block END_BODY {
            milhouse << "endfunc\n";
            symbol_table.clear();
        }
        ;

declaration_block:  
                 | declaration SEMICOLON declaration_block 
                 ;

statement_block: 
               | statement SEMICOLON statement_block 
               ;
declaration: IDENT comma_ident COLON INTEGER {
               Sym sym(0,0,$1,INT); 
               add_symbol(sym);
             }
           | IDENT comma_ident COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
               ident_stack.push($1);
               //Sym sym(0,$6,$1,INTARRAY);
               //add_symbol(sym);
               while(!ident_stack.empty()) {
                 string temp = ident_stack.top();
                 Sym sym(0,$6,temp,INTARRAY);
                 add_symbol(sym);
                 ident_stack.pop(); 
               }
             }
           ;

comma_ident: 
            | COMMA IDENT comma_ident {
               //Sym sym(0,0,$2,INT);
               //add_symbol(sym);
               ident_stack.push($2);
             }
           ;

/*
declaration: IDENT comma_int {
               Sym sym(0,0,$1,INT); 
               add_symbol(sym);
             }
           | IDENT comma_array L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
               Sym sym(0,$4,$1,INTARRAY);
               add_symbol(sym);
             }
           ;


comma_array: comma_array_loop COLON ARRAY
           ;

comma_int: comma_int_loop COLON INTEGER
         ;

comma_int_loop:   
        | COMMA IDENT comma_int_loop {
            Sym sym(0,0,$2,INT); 
            add_symbol(sym);
          }
       ;

comma_array_loop:   
        | COMMA IDENT comma_array_loop{
            Sym sym(0,0,$2,INTARRAY);
            add_symbol(sym);
          }
        ;
        */
/*
dec_block:  
         | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF 
         ;
*/

statement: var ASSIGN expression {
             string a, b, c;
             check_symbol($1.name);
             if (symbol_table[($1.name)].type == INT) { //Check if var is an int
               if (symbol_table[$3.name].type == INT) { //Check if expression is an int   
                 a = make_temp();
                 milhouse << ". " << a << endl;
                 milhouse << "= " << a << ", " << const_cast<char*>($3.name) << endl;
                 milhouse << "= " << const_cast<char*>($1.name) << ", " << a << endl;
               }
               else { //if lhs = int and rhs = int array
                 a = make_temp();
                 b = make_temp();
                 milhouse << ". " << a << endl;
                 milhouse << "= " << a << ", " << const_cast<char*>($3.index) << endl;  
                 milhouse << ". " << b << endl;
                 milhouse << "=[] " << b << ", " << const_cast<char*>($3.name)  << a << endl;
                 milhouse << "= " << const_cast<char*>($1.name) << ", " << b << endl;
               }
               
             }
             else { //Check if var is an int array
               if (symbol_table[$3.name].type == INT) { //Check if expression is an int
                 a = make_temp();
                 b = make_temp();
                 milhouse << ". " << a << endl; 
                 milhouse << "= " << a << ", " << const_cast<char*>($1.index) << endl;
                 milhouse << ". " << b << endl; 
                 milhouse << "= " << b << ", " << const_cast<char*>($3.name) << endl;              
                 milhouse << "[]= " << const_cast<char*>($1.name) << ", " << a << ", " << b << endl;
               }
               else { // int array = int array
                 a = make_temp();
                 b = make_temp();
                 c = make_temp();
                 milhouse << ". " << a << endl;
                 milhouse << "= " << a << ", " << const_cast<char*>($1.index) << endl;
                 milhouse << ". " << b << endl;
                 milhouse << "= " << b << ", " << const_cast<char*>($3.index) << endl;
                 milhouse << ". " << c << endl;
                 milhouse << "=[] " << c << ", " << const_cast<char*>($3.name) << endl;
                 milhouse << "[]= " << const_cast<char*>($1.name) << ", " << a << ", " << c << endl;
               }
            
             } 
           }
         | IF bool_exp THEN statement SEMICOLON statement_block else_block ENDIF 
         | WHILE bool_exp BEGINLOOP statement SEMICOLON statement_block ENDLOOP 
         | DO BEGINLOOP statement SEMICOLON statement_block ENDLOOP WHILE bool_exp 
         | READ var var_block {
             var_stack.push($2.name);
             while (!var_stack.empty()) {
                if ($2.type == 0) {
                    milhouse << ".< " << var_stack.top() << endl;
                    var_stack.pop();
                }
                else {
                    string a = make_temp();
                    milhouse << ". " << a << endl;
                    milhouse << "= " << a << ", " << $2.index << endl;
                    milhouse << ".[]< " << var_stack.top() << ", "  <<  a << endl;
                    var_stack.pop();
                }
             }

          } 
         | WRITE var var_block {
            var_stack.push($2.name);
            while (!var_stack.empty()) {
                if ($2.type == 0) {
                    milhouse << ".> " << var_stack.top() << endl;
                    var_stack.pop();
                }
                else {
                    string a = make_temp();
                    milhouse << ". " << a << endl;
                    milhouse << "= " << a << ", " << $2.index << endl;
                    milhouse << ".[]> " << var_stack.top() << ", "  <<  a << endl;
                    var_stack.pop();
                }
            }
         }
         | CONTINUE 
         | RETURN expression {
             $$.val = $2.val;
          }
         ;

else_block: 
          | ELSE statement SEMICOLON statement_block 
          ;

var_block:  
         | COMMA var var_block {
             // vars.push_back($2.name);
             var_stack.push($2.name);
           } 
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

comp: EQ { $$ = const_cast<char*>("=="); } 
    | NEQ { $$ = const_cast<char*>("!="); }
    | LT { $$ = const_cast<char*>("<"); }
    | GT { $$ = const_cast<char*>(">"); }
    | LTE { $$ = const_cast<char*>("<="); }
    | GTE { $$ = const_cast<char*>(">="); }
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

term: SUB term_minus {
      // making it negative
      // $$.val = $2.val;
      $$.val = $2.val*-1;
      strcpy($$.name,$2.name);
    } 
    | term_minus {
      $$.val = $1.val;
      strcpy($$.name, $1.name);
    } 
    | IDENT L_PAREN exp_comma_block R_PAREN 
    ;

term_minus: var {
              $$.val = $1.val;
              strcpy($$.name,$1.name);
            }
          | NUMBER {
              $$.val = $1;
              $$.type = 3;
              //$$.name = make_temp().c_str();
              strcpy($$.name, make_temp().c_str());
            }
          | L_PAREN expression R_PAREN {
              strcpy($$.name, $2.name);
            }
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
         strcpy($$.name,$1);
         $$.type = 0;
         $$.val = symbol_table[$1].val;
       }
     }
   | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
       check_symbol($1);
       if(symbol_table[$1].type == INT) {
         yyerror("Symbol is of type int");
       }
       else {
         strcpy($$.name, $1);
         $$.type = 1;
         $$.val = symbol_table[$1].val;
         if ($3.type == 3) { //if type is a number
           sprintf($$.index, "%d", $3.val);
         }
         else { //else type is an int, intarray, or function
           strcpy($$.index, $3.name);
         }
       }
   }
   /* IDENT var_2 */
   ;

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
  if (symbol_table.find(s.name) == symbol_table.end()) {
    symbol_table[s.name] = s;
  }
  else {
    string error = "Symbol already declared: " + s.name;
    yyerror(error);
  }
}

bool find_symbol(string name) {
  if (symbol_table.find(name) != symbol_table.end()) {
    return true; 
  }
  else {
    return false;
  }
}

void check_symbol(string name) {
  if(symbol_table.find(name) == symbol_table.end()) {
    string error = "Symbol not declared: " + name;
    yyerror(error);
  }
}

void print_declarations() {
  for(map<string,Sym>::iterator it = symbol_table.begin(); it!=symbol_table.end();++it){
    if (it->second.type == INT) {
      milhouse << ". " << it->second.name << endl;
    }
    else {
      milhouse << ".[] " << it->second.name << ", " << it->second.size << endl;
    }
  }
}

string make_temp() {
  stringstream ss;
  ss << temp_cnt++;
  string temp = "__temp__" + ss.str();
  return temp;
}

string make_label() {
  stringstream ss;
  ss << label_cnt++;
  string temp = "__label__" + ss.str();
  return temp;
}
