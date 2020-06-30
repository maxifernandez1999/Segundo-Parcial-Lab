#include "LinkedList.h"
#include "controller.h"
#ifndef pilotos_H_INCLUDED
#define pilotos_H_INCLUDED
typedef struct{
    int id;
    char nombre[51];
}ePiloto;
int AddPiloto(LinkedList* List, int len);
void ShowPilotos(LinkedList* ListPiloto);
ePiloto* Piloto_new();
ePiloto* Piloto_newParametros(char* idPilotoStr, char* nombrePilotoStr);
int ReadFileAsTextPiloto(FILE* Archivo, LinkedList* list);
int filtrarAlexLifesonArchivoPilotos(void* element);
#endif // Pilotos_H_INCLUDED

