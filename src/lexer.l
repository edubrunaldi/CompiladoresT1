%{
    #include <tokens.h>
    void process_comment(void);
%}

%%
<<EOF>> { return TOKEN_EOF; }
"main" {return TOKEN_MAIN; }
"else" { return TOKEN_ELSE; }
"if" { return TOKEN_IF; }
"int" { return TOKEN_INT; }
"return" { return TOKEN_RETURN; }
"void" { return TOKEN_VOID; }
"while" { return TOKEN_WHILE; }
"input" { return TOKEN_INPUT; }
"output" { return TOKEN_OUTPUT; }
"+" { return TOKEN_SOMA; }
"-" { return TOKEN_SUB; }
"*" { return TOKEN_MUL; }
"/" { return TOKEN_DIV; }
"<" { return TOKEN_MENOR; }
"<=" { return TOKEN_MEIGUAL; }
">" { return TOKEN_MAIOR; }
">=" { return TOKEN_MAIGUAL; }
"==" { return TOKEN_IGUAL; }
"!=" { return TOKEN_DIF; }
"=" { return TOKEN_ATRIB; }
";" { return TOKEN_PV; }
"," { return TOKEN_V; }
"(" { return TOKEN_AP; }
")" { return TOKEN_FP; }
"[" { return TOKEN_ACO; }
"]" { return TOKEN_FCO; }
"{" { return TOKEN_ACH; }
"}" { return TOKEN_FCH; }
[a-zA-Z]+ { return TOKEN_ID; }
[0-9]+ { return TOKEN_NUM; }
"/*" { process_comment(); return TOKEN_COMMENT; }
[ \n\t\r]
. { return TOKEN_ERRO; }
%%
