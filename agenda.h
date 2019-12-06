#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona {
  char nombre[40];
  unsigned long telf;
  struct persona *sig;
};

struct persona * agregar (struct persona *l1, char newnombre[], unsigned long newtel);
void mostrarContactos (struct persona *l1);
