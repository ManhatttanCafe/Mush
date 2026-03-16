

#include <stdio.h>
typedef enum{
   CARACTER_DESCONOCIDO,
}Tipo_Error;

typedef struct {
    Tipo_Error tipo;
}Error;

Error error_init(Tipo_Error tipo){
    Error tmp;
    tmp.tipo = tipo;
    return tmp;
}
const char* error_as_string(Tipo_Error t){
   char* tmp;
   switch (t) {
     case CARACTER_DESCONOCIDO : tmp = "CARACTER DESCONOCIDO";

     default: tmp = "ERROR DESCONOCIDO";
   }
   return tmp;
}

void Error_show(Error e){
    printf("Error %s\n", error_as_string(e.tipo));
}

