#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona {
  char nombre[40];
  unsigned long telf;
  struct persona *sig;
};

struct persona * agregar (struct persona *l1, char newnombre[], unsigned long newtel);
struct persona * eliminarUltimo (struct persona *l1);
void mostrarContactos (struct persona *l1);

int main (){
  struct persona * agenda;
  agenda = agregar(agenda, "Pedro", 5511223344);
  agenda = agregar(agenda, "Juan", 5500223344);
  agenda = agregar(agenda, "JosÃ©", 5599223344);
  agenda = agregar(agenda, "Ignacio", 5566223344);
  mostrarContactos(agenda);
  return 0;
}

struct persona * agregar (struct persona *l1, char newnombre[], unsigned long newtel){
  if (l1 == NULL){
    l1 = (struct persona *)malloc (sizeof(struct persona));
    strcpy(l1->nombre, newnombre);
    l1->telf = newtel;
    l1->sig=NULL;
    return l1;
  } else{
      struct persona *tmp=l1;
      while (tmp->sig!=NULL){
        tmp= tmp->sig;
        }
      struct persona *new;
      new = (struct persona *) malloc (sizeof(struct persona));
      strcpy(new->nombre, newnombre);
      new ->telf = newtel;
      new->sig= NULL;
      tmp->sig=new;
      return l1;
    }
}

void mostrarContactos (struct persona *l1){
  struct persona *tmp;
  tmp=l1;
  while (tmp!=NULL){
    printf ("Nombre: %s\n", tmp->nombre);
    printf("Telefono: %ld\n\n",tmp->telf);
    tmp=tmp->sig;
  }
}

int menu()
{
  
int buscar*persona(struct persona agenda[], int tam, char *nombre, struct persona &p)
{
  int i=0,encontrado=-1;
  while(i<tam && encontrado==-1)
   {
    if(strcmp(agenda[i]->nombre,nombre)==0)
     {
       encontrado=i;
       p=agenda[i];
     }
    else 
       i++;
   }    
  return encontrado;
}
  int opcion;
  printf("\nn1. Insertar contacto");
  printf("\nn2. Buscar Contacto");
  printf("\nn3. Listar Agenda");
  printf("\nn4. Borrar contacto");
  printf("\nn5. Salir");
  printf("\n nnIntroduce opcion: ");
  scanf("%d",&opcion);
  return opcion;
}
 int borrar*persona(struct persona agenda[], int tam, char *nombre)
{
  int exito=0,posicion;
  struct persona p;
  posicion=buscar_persona(agenda,tam,nombre,p);
  if(posicion!=-1)
   {
     exito=1;
     agenda[posicion]->nombre[0]='?';
   } 
  return exito;
}

