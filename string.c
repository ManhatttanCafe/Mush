//string.c implementacion
#include "string.h"
String str_init(int cap){
  if(cap < 1) cap = 1;
  String s;
  s.cap = cap;
  s.len = 0;
  s.data = malloc(cap);
  s.data[0] = '\0'; //esto no cuenta en el conteo de len
  return s;
}

void str_push(String *s,char c){
  if(s->len + 1 >= s->cap){ //+ 1 para contar el terminador  
     s->cap *= 2; //duplicamos la capacidad para no llamar a realloc cada vez.
     char *tmp = realloc(s->data, s->cap);
     if(!tmp){
         perror("realloc");
         exit(1);
     }
     s->data = tmp;
  }
  s->data[s->len] = c;
  s->len++;
  s->data[s->len] = '\0';
}

String str_input(){
  String s = str_init(16);
  int c;
  while((c = getchar()) != '\n' && c != EOF){
      str_push(&s, c);
  }
  return s;
}

void str_free(String *s){
   free(s->data);
   s->len = 0;
   s->cap = 0;
   s->data = NULL;
}

void str_clear(String *s){
   s->len = 0;
   s->data[0] = '\0';
}

String str_clone(String s){
   String tmp;
   tmp.cap = s.cap;
   tmp.len = s.len;
   tmp.data = malloc(s.cap);
   if(!tmp.data){
      perror("malloc");
      exit(1);
   }
   memcpy(tmp.data, s.data, s.len + 1);
   return tmp;
}
