//libreria tokens.h
#include "string.h"

typedef enum {
  TT_INT,
  TT_FLOAT,
  TT_PLUS,
  TT_MINUS,
  TT_MUL,
  TT_DIV,
  TT_LPAREN,
  TT_RPAREN
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
void tokenList_free(TokenList *t);
void tokenList_show(TokenList t);
