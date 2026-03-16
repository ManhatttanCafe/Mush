#include <stdio.h>
#include "string.h"
int main(void){
   while(1){
      printf("mush > ");
      String fuente = str_input();
      printf("%s\n", fuente.data);
      str_free(&fuente);
   }
   return 0;
}
