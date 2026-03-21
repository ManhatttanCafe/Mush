//string.c implementacion
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String str_init(int cap){
  if(cap < 1) cap = 1; //verificar que la capacidad sea almenos 1
  String s;
  s.cap = cap;
  s.len = 0;
  s.data = malloc(cap);
  if(!s.data){
        perror("malloc");
        exit(1);
  }
  s.data[0] = '\0'; 
  return s;
}

void str_push(String *s,char c){
  if(s->len + 1 >= s->cap){   
     s->cap *= 2; 
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
   if(s->data){
         s->len = 0;
         s->data[0] = '\0';
   }
}


String str_clone(String s){
   String tmp;
   tmp.len = s.len;
   tmp.cap = s.len + 1;
   tmp.data = malloc(tmp.cap);
   if(!tmp.data){
      perror("malloc");
      exit(1);
   }
   memcpy(tmp.data, s.data, s.len + 1);
   return tmp;
}


String str_from(const char *tstr){
      int len = strlen(tstr);
      String s = str_init(len + 1);
      memcpy(s.data, tstr, len + 1);
      s.len = len;
      return s;
}


int str_compare(String a, String b){
      if(a.len != b.len){
            return 0; 
      }else{
            return memcmp(a.data, b.data, a.len) == 0; 
      }
}


void str_reserve(String *s, int new_superior_cap){
      if(s->cap >= new_superior_cap){
            return;
      }
      char *tmp = realloc(s->data, new_superior_cap);
      if(!tmp){
            perror("realloc");
            exit(1);
      }
      s->data = tmp;
      s->cap = new_superior_cap;
}
