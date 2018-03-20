#ifndef flex_h
#define flex_h

#include <stdio.h>

extern char *yytext;
extern int yylen;

extern FILE *yyin, *yyout;

int yylex();
int flex_input();


#endif  // flex_h
