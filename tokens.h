//libreria tokens.h
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

typedef enum {
   TOK_NADA,
   TOK_NUM,
   TOK_SUMA,
   TOK_RESTA,
   TOK_MUL,
   TOK_DIV,
   TOK_EOF
}TokenType;

typedef struct{
  TokenType tipo;
  String valor;
}Token;

typedef struct{
  Token *data;
  int len;
  int cap; 
}TokenList;

Token token_init(TokenType tipo, String valor);
TokenList tokenList_init(int cap);
void tokenList_push(TokenList *t, Token tok);
void tokenList_add_eof(TokenList *t);
void tokenList_free(TokenList *t);
