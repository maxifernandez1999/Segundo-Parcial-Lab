#include "GetSet.h"
#include <string.h>
#include "Aerolineas.h"
#include "Pilotos.h"
eVuelo* Airlines_new()
{
    eVuelo* pVuelo;

    pVuelo = (eVuelo*)calloc(sizeof(eVuelo),1);
    if(pVuelo == NULL)
    {
        printf("No hay espacio en memoria\n");
        return 0;
    }
    return pVuelo;
}

eVuelo* Airlines_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr, char* fechaStr, char* destinoStr, char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr)
{
    eVuelo* pVuelo;
    pVuelo = Airlines_new();
    int idVuelo;
    int idAvion;
    int idPiloto;
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    if(pVuelo != NULL && idVueloStr != NULL && idAvionStr != NULL && idPilotoStr != NULL && fechaStr != NULL && destinoStr != NULL && cantPasajerosStr != NULL && horaDespegueStr != NULL && horaLlegadaStr != NULL)
    {
        idVuelo = atoi(idVueloStr);
        idAvion = atoi(idAvionStr);
        idPiloto = atoi(idPilotoStr);
        cantPasajeros = atoi(cantPasajerosStr);
        horaDespegue = atoi(horaDespegueStr);
        horaLlegada = atoi(horaLlegadaStr);

        vuelo_setIdVuelo(pVuelo,idVuelo);
        vuelo_setIdAvion(pVuelo,idAvion);
        vuelo_setIdPiloto(pVuelo,idPiloto);
        vuelo_setFecha(pVuelo,fechaStr);
        vuelo_setDestino(pVuelo,destinoStr);
        vuelo_setCantPasajeros(pVuelo,cantPasajeros);
        vuelo_sethoraDespegue(pVuelo,horaDespegue);
        vuelo_sethoraLlegada(pVuelo,horaLlegada);
    }
    return pVuelo;
}
int vuelo_setFecha(eVuelo* vuelo,char* fecha)
{
    int ret = 0;
    if(vuelo != NULL && fecha != NULL)
    {
        strcpy(vuelo->fecha , fecha);
        ret = 1;
    }
    return ret;
}

int vuelo_getFecha(eVuelo* vuelo,char* fecha)
{
    int ret = 0;
    if(vuelo != NULL && fecha != NULL)
    {
        strcpy(fecha , vuelo->fecha);
        ret = 1;
    }
    return ret;
}



int vuelo_setDestino(eVuelo* vuelo,char* destino)
{
    int ret = 0;
    if(vuelo != NULL && destino != NULL)
    {
        strcpy(vuelo->destino , destino);
        ret = 1;
    }

    return ret;
}
int vuelo_getDestino(eVuelo* vuelo,char* destino)
{
    int retorno = 0;
    if(vuelo != NULL && destino != NULL)
    {
        strcpy(destino , vuelo->destino);
        retorno = 1;
    }
    return retorno;

}

int vuelo_setIdVuelo(eVuelo* vuelo,int idVuelo)
{
    int ret = 0;
    if(vuelo != NULL)
    {
        vuelo->idVuelo = idVuelo;
        ret = 1;
    }

    return ret;
}
int vuelo_getIdVuelo(eVuelo* vuelo,int* idVuelo)
{
    int retorno = 0;
    if(vuelo != NULL && idVuelo != NULL)
    {
        *idVuelo = vuelo->idVuelo;
        retorno = 1;
    }
    return retorno;
}

int vuelo_setIdPiloto(eVuelo* vuelo,int idPiloto)
{
    int ret = 0;
    if(vuelo != NULL)
    {
        vuelo->idPiloto = idPiloto;
        ret = 1;
    }

    return ret;
}
int vuelo_getIdPiloto(eVuelo* vuelo,int* idPiloto)
{
    int retorno = 0;
    if(vuelo != NULL && idPiloto != NULL)
    {
        *idPiloto = vuelo->idPiloto;
        retorno = 1;
    }
    return retorno;
}
int vuelo_setIdAvion(eVuelo* vuelo,int idAvion)
{
    int ret = 0;
    if(vuelo != NULL)
    {
        vuelo->idAvion = idAvion;
        ret = 1;
    }

    return ret;
}
int vuelo_getIdAvion(eVuelo* vuelo,int* idAvion)
{
    int retorno = 0;
    if(vuelo != NULL && idAvion != NULL)
    {
        *idAvion = vuelo->idAvion;
        retorno = 1;
    }
    return retorno;
}
int vuelo_setCantPasajeros(eVuelo* vuelo,int cantPasajeros)
{
    int ret = 0;
    if(vuelo != NULL)
    {
        vuelo->cantPasajeros = cantPasajeros;
        ret = 1;
    }

    return ret;
}
int vuelo_getCantPasajeros(eVuelo* vuelo,int* cantPasajeros)
{
    int retorno = 0;
    if(vuelo != NULL && cantPasajeros != NULL)
    {
        *cantPasajeros = vuelo->cantPasajeros;
        retorno = 1;
    }
    return retorno;
}
int vuelo_sethoraDespegue(eVuelo* vuelo,int horaDespegue)
{
    int ret = 0;
    if(vuelo != NULL)
    {
        vuelo->horaDespegue = horaDespegue;
        ret = 1;
    }

    return ret;
}
int vuelo_gethoraDespegue(eVuelo* vuelo,int* horaDespegue)
{
    int retorno = 0;
    if(vuelo != NULL && horaDespegue != NULL)
    {
        *horaDespegue = vuelo->horaDespegue;
        retorno = 1;
    }
    return retorno;
}
int vuelo_sethoraLlegada(eVuelo* vuelo,int horaLlegada)
{
    int ret = 0;
    if(vuelo != NULL)
    {
        vuelo->horaLlegada = horaLlegada;
        ret = 1;
    }

    return ret;
}
int vuelo_gethoraLlegada(eVuelo* vuelo,int* horaLlegada)
{
    int retorno = 0;
    if(vuelo != NULL && horaLlegada != NULL)
    {
        *horaLlegada = vuelo->horaLlegada;
        retorno = 1;
    }
    return retorno;
}
int piloto_getNombre(ePiloto* piloto, char* nombre)
{
    int retorno = 0;
    if(piloto != NULL && nombre != NULL)
    {
        strcpy(nombre , piloto->nombre);
        retorno = 1;
    }
    return retorno;
}
int piloto_setNombre(ePiloto* piloto, char* nombre)
{
    int retorno = 0;
    if(piloto != NULL && nombre != NULL)
    {
        strcpy(piloto->nombre ,nombre);
        retorno = 1;
    }
    return retorno;
}
int piloto_setId(ePiloto* piloto,int id)
{
    int ret = 0;
    if(piloto != NULL)
    {
        piloto->id = id;
        ret = 1;
    }

    return ret;
}
int piloto_getId(ePiloto* piloto,int* id)
{
    int ret = 0;
    if(piloto != NULL)
    {
       *id =  piloto->id;
        ret = 1;
    }

    return ret;
}

