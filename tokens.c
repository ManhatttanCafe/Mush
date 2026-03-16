#include "tokens.h"
#include <string.h>


Token token_init(TokenType tipo, String valor){
   Token t;
   t.tipo = tipo;
   t.valor = valor;
   return t; 
}

TokenList tokenList_init(int cap){
   if(cap < 1) cap = 1; //por si un pendejo pone 0
   TokenList t;
   t.cap = cap;
   t.len = 0;
   t.data = malloc(cap * sizeof(Token));
   if(!t.data){
      perror("malloc");
      exit(1);
   }
   return t;
}

void tokenList_push(TokenList *t, Token tok){
   if(t->len >= t->cap){
      t->cap *= 2;
      Token *tmp = realloc(t->data, t->cap * sizeof(Token));
      if(!tmp){
         perror("realloc");
         exit(1);
      }
      t->data = tmp;
   }
   t->data[t->len] = tok;
   t->len++;
}


void tokenList_free(TokenList *t){
   for(int i = 0; i < t->len; i++){
       str_free(&t->data[i].valor);
   }
   free(t->data);
}

TokenList tokenList_clone(TokenList t){
      TokenList tmp;
      tmp.cap = t.cap;
      tmp.len = t.len;
      tmp.data = malloc(t.cap * sizeof(Token));
      if(!tmp.data){
            perror("malloc");
            exit(1);
      }
      memcpy(tmp.data, t.data, t.len); //corregir
      return tmp;
}

