#include "Aerolineas.h"
eVuelo* Airlines_new();
eVuelo* Airlines_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr, char* fechaStr, char* destinoStr, char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr);
int vuelo_setFecha(eVuelo* vuelo,char* fecha);
int vuelo_getFecha(eVuelo* vuelo,char* fecha);
int vuelo_setDestino(eVuelo* vuelo,char* destino);
int vuelo_getDestino(eVuelo* vuelo,char* destino);
int vuelo_setIdVuelo(eVuelo* vuelo,int idVuelo);
int vuelo_getIdVuelo(eVuelo* vuelo,int* idVuelo);
int vuelo_setIdPiloto(eVuelo* vuelo,int idPiloto);
int vuelo_getIdPiloto(eVuelo* vuelo,int* idPiloto);
int vuelo_setIdAvion(eVuelo* vuelo,int idAvion);
