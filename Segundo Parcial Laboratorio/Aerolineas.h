#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#ifndef aerolineas_H_INCLUDED
#define aerolineas_H_INCLUDED
typedef struct{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[51];
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelo;

int ReadFileAsText(FILE* Archivo,LinkedList*);
void ShowAirlinesByNamePilots(LinkedList* ,LinkedList* ListPiloto);
int getCantPasajeros(void* element);
int filtrarVuelosCortos(void* element);
int filtrarIrlanda(void* element);
int filtrarPortugal(void* element);
int WriteFileAsText(FILE* Archivo, LinkedList* pArrayList);
void ShowAirlines(LinkedList* List);
int filtrarNOAlexLifeson(void* element);
int getCantPasajerosIrlanda(void* element);
int FindPilotsByID(char* nombrePiloto, int idPiloto, LinkedList* ListPiloto);
int filtrarAlexLifeson(void* element);
int filtrarRichardBach(void* element);
int filtrarJohnKerry(void* element);
int filtrarErwinRommel(void* element);
int filtrarStephenCoonts(void* element);
#endif // Aerolineas_H_INCLUDED

