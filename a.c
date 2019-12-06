#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_AGEN 5
#define MAX_CAD 40
 
struct persona {
  char nombre[40];
  unsigned long telf;
struct persona*sig;

struct persona Nodo;
Nodo*final;
Nodo*inicio;
struct Persona*iniciar(struct Persona*lista){
lista=(struct -persona*)malloc(sizeof(struct Persona));
}
};
 
struct persona leer_persona();
void imprimir_persona(struct persona p);
int buscar_persona(struct persona agenda[], int tam, char *nombre, struct persona &p);
int insertar_persona(struct persona agenda[], int tam, struct persona p);
void listar_agenda(struct persona agenda[], int tam);
void inicializar_agenda(struct persona agenda[], int tam);
int borrar_persona(struct persona agenda[], int tam, char *nombre);
 
