#ifndef STRING_H
#define STRING_H
/*
  Invariantes:
    - data siempre tiene un nulo-terminador '\0' al final del contenido.
    - len no incluye el caracter nulo y representa la longitud de uso de char* data.
    - cap indica cuanta memoria reservada existe en char *data, incluyendo un espacio para \0.
*/
typedef struct{
  int len; 
  int cap;
  char *data;
}String;
/*
  str_init : funcion que toma una capacidad, esta cantidad se usa para
  saber cuanta memoria reservar en char *data, len se inicia en 0 e
  indica la cantidad de espacios que se esta usando de la capacidad total,
  el primer espacio de data se inicia siempre con un '\0', es decir un terminador
  que indicara el final de la cadena, finalmente retorna un String listo para usar.

  str_input : crea un String temporal para almacenar la entrada de caracteres y
  retornarlos a una variable, usado para aceptar la entrada del usuario.

  str_clone : funcion hecha para clonar un String sin generar una copia superficial,
  se hace una copia profunda, para que char* data, no apunten a la misma direccion
  de memoria, para evitar errores de double free.

  str_from : Se toma como entrada una cadena const char*, y se asocia a un String,
  de esta forma se puede crear cadenas de forma mas comoda y natural.

  str_push : funcion que agrega un caracter a char *data.

  str_clear : funcion que restablece los valores iniciales de un String

  str_free : funcion que libera la memoria de char* data, y vuelve el String invalido (data = NULL, cap = 0, len = 0)

  str_reserve : sirve para reservar mas memoria en char *data y aumentar la capacidad, nunca reduce la capacidad.
*/
String str_init(int cap); 
String str_input();  
String str_clone(String s); 
String str_from(const char *tstr); 
void str_push(String *s, char c); 
void str_clear(String *s); 
void str_free(String *s); 
void str_reserve(String *s, int new_superior_cap); 

#endif
