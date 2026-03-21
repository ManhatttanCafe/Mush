#include "token.h"

Token token_init(TokenType tipo, const String valor){
    Token tmp;
    tmp.tipo = tipo;
    tmp.valor = str_clone(valor); //se clona el valor para evitar double free.
    return tmp;
}

void token_free(Token *t){
    if(!t){
        return;
    }
    str_free(&t->valor);
}

Token token_clone(Token t){
    Token tmp;
    tmp.tipo = t.tipo;
    tmp.valor = str_clone(t.valor);
    return tmp;
}

void token_clear(Token *t){
    if(!t){
        return;
    }
    str_clear(&t->valor);
    t->tipo = TT_NIL;
}
