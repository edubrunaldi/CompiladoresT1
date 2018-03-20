#ifndef TOKENS_H
#define TOKENS_H

// Copiados da especificacao do trabalho
// Os 3 ultimos ultimos sao p/ uso interno
#define TOKEN_LIST \
    X(SOMA) \
    X(SUB) \
    X(MUL) \
    X(DIV) \
    X(MENOR) \
    X(MEIGUAL) \
    X(MAIOR) \
    X(MAIGUAL) \
    X(IGUAL) \
    X(DIF) \
    X(ATRIB) \
    X(PV) \
    X(V) \
    X(AP) \
    X(FP) \
    X(ACO) \
    X(FCO) \
    X(ACH) \
    X(FCH) \
    X(ID) \
    X(NUM) \
    X(ERRO) \
    X(EOF) \
    X(COMMENT)


// As constantes em si vao ter "TOKEN_" na frente do nome,
// pra evitar que tenha conflito de nome de variavel.
// Por exemplo: TOKEN_SOMA, TOKEN_ID, TOKEN_NUM
enum Tokens {
#define X(token) TOKEN_ ## token,
    TOKEN_LIST
#undef X
};

// Strings p/ printar na tela. Definido em main.c
extern const char *TOKEN_NAMES[];

#endif  // TOKENS_H
