/*
    CS152 Phase 3

    Matthew Lauhakamin
    mlauh001@ucr.edu

    Melinda Pho
    mpho001@ucr.edu
*/

%{
  #include <stdio.h>
  #include <stdlib.h>
  //#define YYDEBUG 1
  //#define YYPRINT(file, type, value) yyprint (file, type value)
  //yydebug = 1;
  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *message);
  extern int currLine;
  extern int currPos;
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

%%

start: program {printf("start - > program\n");}
      ;

program: {printf("program -> epsilon\n");} 
        | function program {printf("program -> function program\n");}
        ;

function: FUNCTION ident SEMICOLON BEGIN_PARAMS declaration_block END_PARAMS BEGIN_LOCALS declaration_block END_LOCALS BEGIN_BODY statement SEMICOLON statement_block END_BODY {printf("function -> FUNCTION ident SEMICOLON BEGIN_PARAMS declaration_block END_PARAMS BEGIN_LOCALS declaration_block END_LOCALS BEGIN_BODY statement SEMICOLON statement_block END_BODY\n");}
            ;

declaration_block:  {printf("declaration_block -> epsilon\n");}
                    | declaration SEMICOLON declaration_block {printf("declaration_block -> declaration SEMICOLON declaration_block\n");}
                    ;

statement_block: {printf("statement_block -> epsilon\n");} 
                | statement SEMICOLON statement_block {printf("statement_block -> statement SEMICOLON statement_block\n");}
                  ;

declaration:  ident comma_id COLON dec_block INTEGER {printf("declaration -> ident comma_id COLON dec_block INTEGER\n");}
            ;

comma_id:   {printf("comma_id -> epsilon\n");}
          | COMMA ident comma_id {printf("comma_id -> COMMA ident comma_id\n");}
          ;

dec_block:  {printf("dec_block -> epsilon\n");}
          | ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF {printf("dec_block -> ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF\n");}
          ;

statement:  var ASSIGN expression {printf("statement -> var ASSIGN expression\n");}
          | IF bool_exp THEN statement SEMICOLON statement_block else_block ENDIF {printf("statement -> IF bool_exp THEN statement SEMICOLON statement_block else_block ENDIF\n");}
          | WHILE bool_exp BEGINLOOP statement SEMICOLON statement_block ENDLOOP {printf("statement -> WHILE bool_exp BEGINLOOP statement SEMICOLON statement_block ENDLOOP\n");}
          | DO BEGINLOOP statement SEMICOLON statement_block ENDLOOP WHILE bool_exp {printf("statement -> DO BEGINLOOP statement SEMICOLON statement_block ENDLOOP WHILE bool_exp\n");}
          | READ var var_block {printf("statement -> READ var var_block\n");}
          | WRITE var var_block {printf("statement -> WRITE var var_block\n");}
          | CONTINUE {printf("statement -> CONTINUE\n");}
          | RETURN expression {printf("statement -> RETURN expression\n");}
          ;

else_block: {printf("else_block -> epsilon\n");}
          | ELSE statement SEMICOLON statement_block {printf("else_block -> ELSE statement SEMICOLON statement_block\n");}
          ;

var_block:  {printf("var_block -> epsilon\n");}
            | COMMA var var_block {printf("var_block -> COMMA var var_block\n");}
            ;

bool_exp:   relation_and_expr rel_or {printf("bool_expr -> relation_and_expr rel_or\n");} 
          ;

rel_or:  OR relation_and_expr rel_or {printf("rel_or -> OR relation_and_expr rel_or\n");}
        | {printf("rel_or -> epsilon\n");}
        ;

relation_and_expr:  relation_expr rel_and {printf("relation_and_expr -> relation_expr rel_and\n");}
                  ;

rel_and:  AND relation_and_expr {printf("rel_and -> AND relation_and_expr\n");}
        | {printf("rel_and -> epsilon\n");}
        ;

relation_expr:  rel_expr {printf("relation_expr -> rel_expr\n");}
              | NOT rel_expr {printf("relation_expr -> NOT rel_expr\n");}
              ;

rel_expr:   expression comp expression {printf("rel_expr -> expression comp expression\n");}
          | TRUE {printf("relation_expr -> TRUE\n");}
          | FALSE {printf("relation_expr -> FALSE\n");}
          | L_PAREN bool_exp R_PAREN {printf("rel_expr -> L_PAREN bool_exp R_PAREN\n");}
          ;

comp: EQ {printf("comp -> EQ\n");} 
    | NEQ {printf("comp -> NEQ\n");} 
    | LT {printf("comp -> LT\n");} 
    | GT {printf("comp -> GT\n");} 
    | LTE {printf("comp -> LTE\n");} 
    | GTE {printf("comp -> GTE\n");}
     ;

expression: multiplicative_expr mult_expr {printf("expression -> multiplicative_expr mult_expr\n");}
          ;

mult_expr:  ADD multiplicative_expr mult_expr {printf("mult_expr -> ADD multiplicative_expr mult_expr\n");}
          | SUB multiplicative_expr mult_expr {printf("mult_expr -> SUB multiplicative_expr mult_expr\n");}
          | {printf("mult_expr -> epsilon\n");}
          ;

multiplicative_expr:  term mult_expr_term {printf("muliplicative_expr -> term mult_expr_term\n");} 
                    ;

mult_expr_term:   MULT term mult_expr_term{printf("mult_expr_term -> MULT term mult_expr_term\n");}
                | DIV term mult_expr_term{printf("mult_expr_term -> DIV term mult_expr_term\n");}
                | MOD term mult_expr_term{printf("mult_expr_term -> MOD term mult_expr_term\n");}
                | {printf("mult_expr_term -> epsilon\n");}
                ;

term:   SUB term_minus {printf("term -> SUB term_minus\n");} 
     |  term_minus {printf("term -> term_minus\n");} 
     |  ident L_PAREN exp_comma_block R_PAREN {printf("term -> ident L_PAREN exp_comma_block R_PAREN\n");}
     ;

term_minus:   var {printf("term_minus -> var\n");} 
           |  number {printf("term_minus -> number\n");} 
           |  L_PAREN expression R_PAREN {printf("term_minus -> L_PAREN expression R_PAREN\n");} 
           ;

exp_comma_block: expression exp_comma_block2 {printf("exp_comma_block -> expression exp_comma_block2\n");}
                 |  {printf("exp_comma_block -> epsilon\n");}
                 ;

exp_comma_block2: {printf("exp_comma_block2 -> epsilon\n");}
                | COMMA expression exp_comma_block2 {printf("exp_comma_block2 -> COMMA expression exp_comma_block2\n");}
                ;

var:  ident var_2 {printf("var -> ident var_2\n");}
   ;

var_2:  {printf("var_2 -> epsilon\n");}
      | L_SQUARE_BRACKET expression R_SQUARE_BRACKET {printf("var_2 -> L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
      ;

ident: IDENT {printf("ident -> IDENT %s\n", $1);}
     ;

number: NUMBER {printf("number -> NUMBER %d\n", $1);}
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
  return 0;
}

void yyerror(const char *message) {
  printf("Syntax error on line %d: \"%s\" \n", currLine, message);
}
