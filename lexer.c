#include "tokens.h"
#include <ctype.h>
#include "error.h"
//Tengo que simplificar lexer_make_token.
typedef struct {
   String fuente;
   int pos;
   char char_actual;
}Lexer;

void lexer_advance(Lexer *l){
   l->pos += 1;
   if(l->pos < l->fuente.len){
      l->char_actual = l->fuente.data[l->pos];
   }else{
      l->char_actual = '\0';
   }
}

Lexer lexer_init(String fuente){
   Lexer tmp;
   tmp.fuente = fuente;
   tmp.pos = -1;
   tmp.char_actual = '\0';
   lexer_advance(&tmp);
   return tmp;
}

Token lexer_make_number(Lexer *l){
      Token tmp;
      String numero = str_init(16);
      int puntos = 0;
      while(l->char_actual != '\0' && ( isdigit(l->char_actual) || l->char_actual == '.' )){
            if(l->char_actual == '.'){
                if(puntos == 1){
                     break;
                }
                puntos += 1;
            }
            str_push(&numero, l->char_actual);
            lexer_advance(l);
      }
      if(puntos == 0){
            tmp = token_init(TT_INT, str_clone(numero));
      }else{
            tmp = token_init(TT_FLOAT, str_clone(numero));
      }
      str_free(&numero);
      return tmp;
}

TokenList lexer_make_tokens(Lexer *l){
      TokenList tmp_tl = tokenList_init(16);
      String tmp_cadena = str_init(16);
      while(l->char_actual != '\0'){
            if(isspace(l->char_actual)){
                  lexer_advance(l);
            }
            else if(isdigit(l->char_actual)){
                  tokenList_push(&tmp_tl, lexer_make_number(l));
            }
            else if(l->char_actual == '+'){
                  str_push(&tmp_cadena, l->char_actual);
                  tokenList_push(&tmp_tl, token_init(TT_PLUS,str_clone(tmp_cadena)));
                  str_clear(&tmp_cadena);
                  lexer_advance(l);
            }
            else if(l->char_actual == '-'){
                  str_push(&tmp_cadena, l->char_actual);
                  tokenList_push(&tmp_tl, token_init(TT_MINUS,str_clone(tmp_cadena)));
                  str_clear(&tmp_cadena);
                  lexer_advance(l);
            }
            else if(l->char_actual == '*'){
                  str_push(&tmp_cadena, l->char_actual);
                  tokenList_push(&tmp_tl, token_init(TT_MUL,str_clone(tmp_cadena)));
                  str_clear(&tmp_cadena);
                  lexer_advance(l);
            }
            else if(l->char_actual == '/'){
                  str_push(&tmp_cadena, l->char_actual);
                  tokenList_push(&tmp_tl, token_init(TT_DIV,str_clone(tmp_cadena)));
                  str_clear(&tmp_cadena);
                  lexer_advance(l);
            }
            else if(l->char_actual == '('){
                  str_push(&tmp_cadena, l->char_actual);
                  tokenList_push(&tmp_tl, token_init(TT_LPAREN,str_clone(tmp_cadena)));
                  str_clear(&tmp_cadena);
                  lexer_advance(l);
            }
            else if(l->char_actual == ')'){
                  str_push(&tmp_cadena, l->char_actual);
                  tokenList_push(&tmp_tl, token_init(TT_RPAREN,str_clone(tmp_cadena)));
                  str_clear(&tmp_cadena);
                  lexer_advance(l);
            }


            else{
                  Error error404 = error_init(CARACTER_DESCONOCIDO);
                  error_show(error404); 
            }

      }
      return tl;
}
