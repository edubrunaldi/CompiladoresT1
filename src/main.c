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
    //Verifica os argumentos passados.
    if(argc < 2) {
        fprintf(stderr, "Erro: nome do arquivo nao foi especificado\n");
        return 1;
    }

    //Abre o programa a ser analisado.
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo '%s'\n", argv[1]);
        return 2;
    }

    //Cria o arquivo de saida.
    FILE *output = fopen("relatorio.txt", "w");
    if(output == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir 'relatorio.txt'\n");
        fclose(yyin);
        return 3;
    }

    //Este arquivo é criado afim de guardar temporariamente o resultado do analisador
    //lexico de modo que seja possivel imprimir o numero de erros na primeira linha
    //do arquivo de saida.
    FILE *buffer = fopen("buffer.txt", "w");
    if(output == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir 'buffer.txt'\n");
        fclose(yyin);
        return 4;
    }

    int total_errors = 0;

    //Para cada token identificado, uma saida correspondente 
    //eh escrita para o arquivo temporario.
    while(1) {
        int token = yylex();

        //Se o programa sendo lido acabou, a leitura é finalizada.
        if(token == TOKEN_EOF) {
            break;
        }

        //Se foi encontrado um erro, soma-se a variavel de erros.
        if(token == TOKEN_ERRO) {
            total_errors += 1;
        }

        //Se a token identificada é MAIN ou VOID, o output eh
        //diferenciado. Para o resto, imprime-se a token e seu tipo.
        if(token == TOKEN_MAIN || token == TOKEN_VOID){
            fprintf(buffer, "%s Palavra-chave\n", yytext);
        }else if(token != TOKEN_COMMENT) {
            fprintf(buffer, "%s %s\n", yytext, TOKEN_NAMES[token]);
        }  
    }

    //Salva o arquivo temporario com as tokens identificadas.
    fclose(buffer);

    //No arquivo de saida, imprime-se o numero de erros.
    fprintf(output, "%d erro(s) encontrado(s)\n", total_errors);

    //Abre novamente o arquivo temporario para ser escrito no arquivo de saida.
    buffer = fopen("buffer.txt", "r");
    if(output == NULL) return 4;

    //Le do buffer e escreve no arquivo de saida.
    char c;
    while ((c = fgetc(buffer)) != EOF) {
         fprintf(output, "%c", (char) c);
    }

    fclose(yyin);
    fclose(output);
    fclose(buffer);

    //Remove o arquivo temporario.
    remove("buffer.txt");

    return 0;

    (void) input;
    (void) yyunput;
}
