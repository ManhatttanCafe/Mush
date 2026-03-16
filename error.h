#include <stdio.h>
typedef enum{
   CARACTER_DESCONOCIDO,
}Tipo_Error;

typedef struct {
    Tipo_Error tipo;
}Error;

Error error_init(Tipo_Error tipo);
const char* error_as_string(Tipo_Error t);
void error_show(Error e);
