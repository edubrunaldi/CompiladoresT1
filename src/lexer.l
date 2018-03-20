%{
    #include <tokens.h>
    void process_comment(void);
%}

%%
<<EOF>> { return TOKEN_EOF; }
[a-zA-Z]+ { return TOKEN_ID; }
[0-9]+ { return TOKEN_NUM; }
"/*" { process_comment(); return TOKEN_COMMENT; }
[ \n\t\r]
. { return TOKEN_ERRO; }
%%
