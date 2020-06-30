#include "Aerolineas.h"
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pilotos.h"
#include <string.h>
#include "GetSet.h"


int ReadFileAsText(FILE* Archivo, LinkedList* list)
{
    eVuelo* vuelo;
    char idVuelo[51];
    char idAvion[51];
    char idPiloto[51];
    char fecha[51];
    char destino[51];
    int ret;
    char cantPasajeros[51];
    char horaDespegue[51];
    char horaLlegada[51];
    int returnValue = -1;
    if(list != NULL && Archivo != NULL)
    {
        fscanf(Archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        do
        {
            ret = fscanf(Archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
            if(ret == 8)
            {
                vuelo = Airlines_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
                ll_add(list, vuelo);
            }
            else
                break;

        }while(!feof(Archivo));
        returnValue = 0;
        printf("ARCHIVO DE TEXTO LEIDO\n");
    }
    return returnValue;
}

void ShowAirlines(LinkedList* List)
{
    int len;
    int i;
    int idVuelo;
    int idPiloto;
    int idAvion;
    char fecha[51];
    char destino[51];
    int horaDespegue;
    int horaLlegada;
    int cantPasajeros;
    eVuelo* pElementVuelo;
    if(pElementVuelo != NULL && List != NULL)
    {
        len = ll_len(List);
        printf("    IDVUELO   IDAVION   IDPILOTO      FECHA           DESTINO    CANTPASJ  HORADESP   HORALLEG\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        for(i = 0; i < len; i++)
        {
            pElementVuelo = Airlines_new();
            pElementVuelo = ll_get(List,i);
            vuelo_getIdVuelo(pElementVuelo,&idVuelo);
            vuelo_getIdAvion(pElementVuelo,&idAvion);
            vuelo_getIdPiloto(pElementVuelo,&idPiloto);
            vuelo_getFecha(pElementVuelo,fecha);
            vuelo_getDestino(pElementVuelo,destino);
            vuelo_getCantPasajeros(pElementVuelo,&cantPasajeros);
            vuelo_gethoraDespegue(pElementVuelo,&horaDespegue);
            vuelo_gethoraLlegada(pElementVuelo,&horaLlegada);

            printf("%8d %8d \t%8d \t%10s \t%10s %8d %8d %8d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        }
    }

}
void ShowAirlinesByNamePilots(LinkedList* List,LinkedList* ListPiloto)
{
    int len;
    int i;
    int j;
    int len2;
    int idVuelo;
    int idPiloto;
    int idAvion;
    char fecha[51];
    char destino[51];
    char nombrePiloto[51];
    int horaDespegue;
    int horaLlegada;
    int cantPasajeros;
    eVuelo* pElementVuelo;
    ePiloto* pElementPiloto;
    if(List != NULL && ListPiloto != NULL)
    {
        len = ll_len(List);
        len2 = ll_len(ListPiloto);
        printf("    IDVUELO   IDAVION   NOMBREPILOTO      FECHA           DESTINO    CANTPASJ  HORADESP   HORALLEG\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        for(i = 0; i < len; i++)
        {
            pElementVuelo = ll_get(List,i);
            vuelo_getIdVuelo(pElementVuelo,&idVuelo);
            vuelo_getIdAvion(pElementVuelo,&idAvion);
            vuelo_getIdPiloto(pElementVuelo,&idPiloto);
            vuelo_getFecha(pElementVuelo,fecha);
            vuelo_getDestino(pElementVuelo,destino);
            vuelo_getCantPasajeros(pElementVuelo,&cantPasajeros);
            vuelo_gethoraDespegue(pElementVuelo,&horaDespegue);
            vuelo_gethoraLlegada(pElementVuelo,&horaLlegada);
            FindPilotsByID(nombrePiloto,idPiloto,ListPiloto);
            printf("%8d %8d \t%10s \t%10s \t%10s %8d %8d %8d\n",idVuelo,idAvion,nombrePiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        }
    }
}
int FindPilotsByID(char* nombrePiloto, int idPiloto, LinkedList* ListPiloto)
{
    int i;
    int id;
    void* pElement;
    int returnAux = -1;
    char nombre[51];
    for(i = 0; i < ll_len(ListPiloto); i++)
    {
        pElement = ll_get(ListPiloto,i);
        piloto_getNombre(pElement,nombre);
        piloto_getId(pElement,&id);
        if(id == idPiloto)
        {
            strcpy(nombrePiloto, nombre);
            returnAux = 0;
        }
    }
    return returnAux;
}
int getCantPasajeros(void* element)
{
    int cantPasajeros;
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_getCantPasajeros(element,&cantPasajeros);
    }
    return cantPasajeros;

}
int getCantPasajerosIrlanda(void* element)
{
    int cantPasajeros = 0;
    eVuelo* vuelo;
    char destino[51];
    if(element != NULL)
    {
        vuelo = (eVuelo*)element; //guardo en un puntero a eVuelo
        vuelo_getDestino(vuelo,destino);
        if(strcasecmp(destino,"Irlanda")==0)
        {
            vuelo_getCantPasajeros(vuelo,&cantPasajeros);
        }
    }
    return cantPasajeros;
}
int filtrarIrlanda(void* element)
{
    int returnAux = 0;
    char destino[51];
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_getDestino(element,destino);
        if(strcasecmp(destino,"Irlanda")==0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int filtrarVuelosCortos(void* element)
{
    int returnAux = 0;
    int horaDespegue;
    int horaLlegada;
    int duracionVuelo;
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_gethoraDespegue(element,&horaDespegue);
        vuelo_gethoraLlegada(element,&horaLlegada);
        duracionVuelo = horaLlegada - horaDespegue;
        if(duracionVuelo < 3)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int filtrarPortugal(void* element)
{
    int returnAux = 0;
    char destino[51];
    if(element != NULL)
    {
        vuelo_getDestino(element,destino);
        if(strcasecmp(destino,"Portugal")==0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int filtrarAlexLifeson(void* element)
{
    int idPiloto;
    int returnAux = 0;
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_getIdPiloto(element,&idPiloto);
        if(idPiloto == 1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int filtrarNOAlexLifeson(void* element)
{
    int idPiloto;
    int returnAux = 0;
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_getIdPiloto(element,&idPiloto);
        if(idPiloto != 1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int filtrarRichardBach(void* element)
{
    int idPiloto;
    int returnAux = 0;
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_getIdPiloto(element,&idPiloto);
        if(idPiloto == 2)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int filtrarJohnKerry(void* element)
{
    int idPiloto;
    int returnAux = 0;
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_getIdPiloto(element,&idPiloto);
        if(idPiloto == 3)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int filtrarErwinRommel(void* element)
{
    int idPiloto;
    int returnAux = 0;
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_getIdPiloto(element,&idPiloto);
        if(idPiloto == 4)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int filtrarStephenCoonts(void* element)
{
    int idPiloto;
    int returnAux = 0;
    if(element != NULL)
    {
        element = (eVuelo*)element;
        vuelo_getIdPiloto(element,&idPiloto);
        if(idPiloto == 5)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int WriteFileAsText(FILE* Archivo, LinkedList* pArrayList)
{
    int len;
    int i;
    int idVuelo;
    int idPiloto;
    int idAvion;
    char fecha[51];
    char destino[51];
    int horaDespegue;
    int horaLlegada;
    int cantPasajeros;
    eVuelo* pElementVuelo;
    len = ll_len(pArrayList);
    if(pArrayList != NULL && Archivo != NULL)
    {
        fprintf(Archivo,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
        for(i = 0; i < len; i++)
        {
            pElementVuelo = ll_get(pArrayList,i);
            vuelo_getIdVuelo(pElementVuelo,&idVuelo);
            vuelo_getIdAvion(pElementVuelo,&idAvion);
            vuelo_getIdPiloto(pElementVuelo,&idPiloto);
            vuelo_getFecha(pElementVuelo,fecha);
            vuelo_getDestino(pElementVuelo,destino);
            vuelo_getCantPasajeros(pElementVuelo,&cantPasajeros);
            vuelo_gethoraDespegue(pElementVuelo,&horaDespegue);
            vuelo_gethoraLlegada(pElementVuelo,&horaLlegada);
            fprintf(Archivo,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        }
    }
    printf("SE HA CREADO UN ARCHIVO\n");
    return 0;
}
int WriteFileAsTextByName(FILE* Archivo, LinkedList* pArrayList,LinkedList* pArrayList2)
{
    int len;
    int len2;
    int i;
    int idVuelo;
    int idPiloto;
    int id;
    int j;
    int idAvion;
    char fecha[51];
    char destino[51];
    char nombrePiloto[51];
    int horaDespegue;
    int horaLlegada;
    int cantPasajeros;
    eVuelo* pElementVuelo;
    ePiloto* pElementPiloto;
    len = ll_len(pArrayList);
    len2 = ll_len(pArrayList2);
    if(pArrayList != NULL && pArrayList2 != NULL && pElementPiloto != NULL && pElementVuelo != NULL && Archivo != NULL)
    {
        fprintf(Archivo,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);//VERIFICAR
        for(i = 0; i < len; i++)
        {

            pElementVuelo = ll_get(pArrayList,i);
            vuelo_getIdVuelo(pElementVuelo,&idVuelo);
            vuelo_getIdAvion(pElementVuelo,&idAvion);
            vuelo_getIdPiloto(pElementVuelo,&idPiloto);
            vuelo_getFecha(pElementVuelo,fecha);
            vuelo_getDestino(pElementVuelo,destino);
            vuelo_getCantPasajeros(pElementVuelo,&cantPasajeros);
            vuelo_gethoraDespegue(pElementVuelo,&horaDespegue);
            vuelo_gethoraLlegada(pElementVuelo,&horaLlegada);
            for(j = 0; j < len2; j++)
            {

                pElementPiloto = ll_get(pArrayList2,j);
                piloto_getId(pElementPiloto,&id);
                piloto_getNombre(pElementPiloto,nombrePiloto);
                if(idPiloto == id)
                {
                    fprintf(Archivo,"%d,%d,%s,%s,%s,%d,%d,%d\n",idVuelo,idAvion,nombrePiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
                }
            }
        }
    }
    printf("todo ok\n");
    return 0;
}
