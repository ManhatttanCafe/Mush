#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokens.h"

TokenList tokenizar(String text) {
    TokenList tl = tokenList_init(16);
    String numero = str_init(16);
    String caracter = str_init(16);
    for(int i = 0; i < text.len; i++){
       if(isdigit(text.data[i])){
          str_push(&numero, text.data[i]);
       }
       else{
          if(numero.len > 0){
             tokenList_push(&tl, token_init(TOK_NUM, str_clone(numero)));
             str_clear(&numero);
          }

          if(isspace(text.data[i])){
             continue;
          }
          else if(text.data[i] == '+'){
              str_push(&caracter, text.data[i]);
              tokenList_push(&tl, token_init(TOK_SUMA, str_clone(caracter)));
              str_clear(&caracter);
          }
          else if(text.data[i] == '-'){
              str_push(&caracter, text.data[i]);
              tokenList_push(&tl, token_init(TOK_RESTA, str_clone(caracter)));
              str_clear(&caracter);
          }
          else if(text.data[i] == '/'){
              str_push(&caracter, text.data[i]);
              tokenList_push(&tl, token_init(TOK_DIV, str_clone(caracter)));
              str_clear(&caracter);
          }
          else if(text.data[i] == '*'){
              str_push(&caracter, text.data[i]);
              tokenList_push(&tl, token_init(TOK_MUL, str_clone(caracter)));
              str_clear(&caracter);
          }else{
             printf("caracter desconocido '%c' \n", text.data[i]);
          }
       }
    }
    if(numero.len > 0){
        tokenList_push(&tl, token_init(TOK_NUM, str_clone(numero)));
    }
    str_free(&numero);
    str_free(&caracter);
    return tl;
}

int parse_and_eval(TokenList lista) {
    int resultado;
    if(lista.len != 3){
       printf("expresion invalida\n");
       return 0;
    }
    int a = atoi(lista.data[0].valor.data);
    char *op = lista.data[1].valor.data;
    int b = atoi(lista.data[2].valor.data);
    if(*op == '+'){
       resultado =  a + b;
    }
    else if(*op == '-'){
       resultado =  a - b;
    }
    else if(*op == '*'){
       resultado = a * b;
    }
    else if(*op == '/'){
       if(b == 0){
          printf("error division por cero\n");
          return 0;
       }
       resultado =  a / b;
    }
    return resultado;
}

int main(){
   while(1){
      printf("interprete > ");
      String pront = str_input();
      TokenList tokens = tokenizar(pront);
      int resultado = 0;
      resultado = parse_and_eval(tokens);
      printf("%d\n", resultado);
      str_free(&pront);
      tokenList_free(&tokens);
   }
   return 0;
}
