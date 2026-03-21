#include "string.h"

typedef enum {
  TT_INT,
  TT_FLOAT,
  TT_PLUS,
  TT_MINUS,
  TT_MUL,
  TT_DIV,
  TT_LPAREN,
  TT_RPAREN,
  TT_NIL
}TokenType;

typedef struct{
  TokenType tipo;
  String valor;
}Token;

Token token_init(TokenType tipo, String valor);
void token_free(Token *t);
Token token_clone(Token t);
void token_clear(Token *t);
