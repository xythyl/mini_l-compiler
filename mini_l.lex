/*
  CS152 Winter 2017
  Project Phase 3

  Matthew Lauhakamin
  mlauh001@ucr.edu

  Melinda Pho
  mpho001@ucr.edu
*/

%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "y.tab.h"
  int currLine = 1;
  int currPos = 1;
%}

DIGIT   [0-9]
ID      [a-z][a-z0-9\_]*

%%

"function"    {currPos += yyleng; return FUNCTION;}
"beginparams" {currPos += yyleng; return BEGIN_PARAMS;}
"endparams"   {currPos += yyleng; return END_PARAMS;}
"beginlocals" {currPos += yyleng; return BEGIN_LOCALS;}
"endlocals"   {currPos += yyleng; return END_LOCALS;}
"beginbody"   {currPos += yyleng; return BEGIN_BODY;}
"endbody"     {currPos += yyleng; return END_BODY;}
"integer"     {currPos += yyleng; return INTEGER;}
"array"       {currPos += yyleng; return ARRAY;}
"of"          {currPos += yyleng; return OF;}
"if"          {currPos += yyleng; return IF;}
"then"        {currPos += yyleng; return THEN;}
"endif"       {currPos += yyleng; return ENDIF;}
"else"        {currPos += yyleng; return ELSE;}
"while"       {currPos += yyleng; return WHILE;}
"do"          {currPos += yyleng; return DO;}
"beginloop"   {currPos += yyleng; return BEGINLOOP;}
"endloop"     {currPos += yyleng; return ENDLOOP;}
"continue"    {currPos += yyleng; return CONTINUE;}
"read"        {currPos += yyleng; return READ;}
"write"       {currPos += yyleng; return WRITE;}
"and"         {currPos += yyleng; return AND;}
"or"          {currPos += yyleng; return OR;}
"not"         {currPos += yyleng; return NOT;}
"true"        {currPos += yyleng; return TRUE;}
"false"       {currPos += yyleng; return FALSE;}
"return"      {currPos += yyleng; return RETURN;}

"-"           {currPos += yyleng; return SUB;}
"+"           {currPos += yyleng; return ADD;}
"*"           {currPos += yyleng; return MULT;}
"/"           {currPos += yyleng; return DIV;}
"%"           {currPos += yyleng; return MOD;}

"=="          {currPos += yyleng; return EQ;}
"<>"          {currPos += yyleng; return NEQ;}
"<"           {currPos += yyleng; return LT;}
">"           {currPos += yyleng; return GT;}
"<="          {currPos += yyleng; return LTE;}
">="          {currPos += yyleng; return GTE;}

{ID}\_ {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an undederscore\n", currLine, currPos, yytext); exit(1);}
{DIGIT}+{ID} {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); exit(1);}

{DIGIT}+      {currPos += yyleng; yylval.num_val = atoi(yytext); return NUMBER;}
{ID}          {currPos += yyleng; yylval.ident_str = strdup(yytext); return IDENT;}

";"           {currPos += yyleng; return SEMICOLON;}
":"           {currPos += yyleng; return COLON;}
","           {currPos += yyleng; return COMMA;}
"("           {currPos += yyleng; return L_PAREN;}
")"           {currPos += yyleng; return R_PAREN;}
"["           {currPos += yyleng; return L_SQUARE_BRACKET;}
"]"           {currPos += yyleng; return R_SQUARE_BRACKET;}
":="          {currPos += yyleng; return ASSIGN;}

"##".*        {currPos += yyleng;}


[ \t ]+       {/* ignore spaces and tabs*/ currPos += yyleng;}

"\n"          {currLine++; currPos = 1;}

.             {printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}

%%

/*int main(int argc, char ** argv)
{
  yylex();
}*/
