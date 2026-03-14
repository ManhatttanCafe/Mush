//string.h
#include <stdlib.h>

typedef struct{
  int len; //uso
  int cap; //capacidad total
  char *data; //puntero para reservar memoria.
}String;

String str_init(int cap);
void str_push(String *s, char c);
String str_input();
void str_free(String *s);
void str_clear(String *s);
String str_clone(String s);
