#include "agenda.h"

int opc;
struct persona *agenda;
char newnombre[40];
unsigned long newtel;


int main(){
  
  do{
    printf("*********AGENDA********* \n");
    printf("1. Agregar Contacto\n");
    printf("2. Mostrar Contactos\n");
    printf("Elija una opción: ");
    scanf("%d", &opc);

    switch (opc){
    case 1:
      printf("Nombre: ");
      scanf("%s", newnombre);
      printf("\nTeléfono: ");
      scanf("%ld", &newtel);
      agenda = agregar(agenda, newnombre, newtel);
      printf("\n¡Agregado con éxito!\n");
      break;

    case 2:
      printf("\nContactos: \n");
      mostrarContactos(agenda);

    default:
      break;
    }
  } while (opc!=0);

  return 0;
}