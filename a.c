#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_AGEN 5
#define MAX_CAD 40
 
struct persona {
  char nombre[40];
  unsigned long telf;
struct persona*sig;
};
 
struct persona leer_persona();
void imprimir_persona(struct persona p);
int buscar_persona(struct persona agenda[], int tam, char *nombre, struct persona &p);
int insertar_persona(struct persona agenda[], int tam, struct persona p);
void listar_agenda(struct persona agenda[], int tam);
void inicializar_agenda(struct persona agenda[], int tam);
int borrar_persona(struct persona agenda[], int tam, char *nombre);
 
int menu();
 
int main()
{
  int opcion;
  struct persona agenda[MAX_AGEN], p;
  char nombre[MAX_CAD];
  inicializar_agenda(agenda,MAX_AGEN);
  do{
    system("clear");
    opcion=menu();
    fflush(stdin);
    switch(opcion)
     {
       case 1: p=leer_persona();
               if (insertar_persona(agenda,MAX_AGEN,p)==1)
                 printf("\nContacto insertado con exito");
               else  
                 printf("\nError, el contacto no se ha insertado");
               break;
       case 2: printf("\nIntroduce el nombre a buscar: ");
               gets(nombre);
               if (buscar_persona(agenda,MAX_AGEN,nombre,p)==1)
                 imprimir_persona(p);
               else
                 printf("\nEl contacto no existe");  
               break;
       case 3: listar_agenda(agenda,MAX_AGEN);
               break;
       case 4: printf("\nIntroduce el nombre a borrar: ");
               gets(nombre);
               if (borrar_persona(agenda,MAX_AGEN,nombre)==1)
                 printf("\nContacto borrado con exito");
               else
                 printf("\nError, el contacto no existe");
               break;
       case 5: printf("\n Hasta la vista");
               break;
       default: printf("\n Opcion no valida");
     }
    getch();  
  }while(opcion!=5);
  return 0;
}
 
struct persona leer_persona()
{
  struct persona p;
  printf("vIntroduce nombre: ");
  gets(p.nombre);
  printf("\nIntroduce telefono: ");
  scanf("%lu",&p.telf);
  return p; 
}
 
void imprimir_persona(struct persona p)
{
  printf("\nNombre: %s",p.nombre);
  printf("\nTelefono: %lu",p.telf);  
}
 
int buscar_persona(struct persona agenda[], int tam, char *nombre, struct persona &p)
{
  int i=0,encontrado=-1;
  while(i<tam && encontrado==-1)
   {
    if(strcmp(agenda[i].nombre,nombre)==0)
     {
       encontrado=i;
       p=agenda[i];
     }
    else 
       i++;
   }    
  return encontrado;
}
 
int insertar_persona(struct persona agenda[], int tam, struct persona p)
{
  int exito=0,i=0;
  while(i<tam && exito==0)
   {
     if(agenda[i].nombre[0]=='?')    //if (strcmp(agenda[i].nombre,"")==0)
      {
        agenda[i]=p;
        exito=1; 
      }
     i++; 
   } 
  return exito;
} 
 
void listar_agenda(struct persona agenda[], int tam)
{
  int i,cont=0;
  for(i=0;i<tam;i++)
   {
     if(agenda[i].nombre[0]!='?')
      {
        cont++;
        printf("n");
        imprimir_persona(agenda[i]);
      }  
   }
  if(cont==0)
    printf("n Agenda Vacia"); 
}
    
int menu()
{
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
 
