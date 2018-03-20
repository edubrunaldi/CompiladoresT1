#include <stdio.h>
#include <lex.yy.h>
#include <tokens.h>


// Ver tokens.h
// Exemplo de uso: TOKEN_NAMES[TOKEN_SOMA] == "SOMA"
const char *TOKEN_NAMES[] = {
#define X(token) #token,
    TOKEN_LIST
#undef X
};


// Se chegar no fim do arquivo e nao encontrar o */, retorna TOKEN_EOF
// Vou perguntar pro professor se eh pra dar erro nesse caso
void process_comment(void) {
    while(1) {
        char ch = input();
        if(ch == EOF) {
            unput(ch);
            break;
        } else if(ch == '*') {
            ch = input();
            if(ch == EOF) {
                unput(ch);
            }
            if(ch == '/' || ch == EOF) {
                break;
            }
        }
    }
}


int main(int argc, char **argv)
{
    if(argc < 2) {
        fprintf(stderr, "Erro: nome do arquivo nao foi especificado\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo '%s'\n", argv[1]);
        return 2;
    }

    FILE *output = fopen("relatorio.txt", "w");
    if(output == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir 'relatorio.txt'\n");
        fclose(yyin);
        return 3;
    }

    int total_errors = 0;

    while(1) {
        int token = yylex();
        // TODO tirar esse printf na submissao final
        printf("%s %s\n", yytext, TOKEN_NAMES[token]);

        if(token == TOKEN_EOF) {
            break;
        }

        if(token == TOKEN_ERRO) {
            total_errors += 1;
        }

        if(token != TOKEN_COMMENT) {
            fprintf(output, "%s %s\n", yytext, TOKEN_NAMES[token]);
        }
    }

    fprintf(output, "%d erro(s) encontrado(s)\n", total_errors);

    fclose(yyin);
    fclose(output);
    return 0;

    (void) input;
    (void) yyunput;
}
