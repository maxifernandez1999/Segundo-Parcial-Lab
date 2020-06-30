#include "Pilotos.h"
#include "LinkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int ReadFileAsTextPiloto(FILE* Archivo, LinkedList* list)
{
    ePiloto* piloto;
    char idPiloto[51];
    char nombrePiloto[51];
    int ret;
    int returnValue = -1;
    if(list != NULL && Archivo != NULL)
    {
        fscanf(Archivo,"%[^,],%[^\n]\n",idPiloto,nombrePiloto);
        do
        {
            ret = fscanf(Archivo,"%[^,],%[^\n]\n",idPiloto,nombrePiloto);
            if(ret == 2)
            {
                piloto = Piloto_newParametros(idPiloto,nombrePiloto);
                ll_add(list, piloto);
            }
            else
                break;

        }while(!feof(Archivo));
        returnValue = 0;
        printf("ARCHIVO DE TEXTO LEIDO\n");
    }
    return returnValue;
}
int AddPiloto(LinkedList* ListPiloto, int len)
{
    ePiloto* piloto;
    int returnAux = -1;
    int i;
    char id[10][51] = {"1","2","3","4","5","1","7","8","9","10"};
    char nombre[10][51] = {"Alex Lifeson","Richard Bach","john Kerry","Erwin Rommel","Stephen Coonts","Alex Lifeson","Pepe Sand","Marcelo gallardo","Pity Martinez","Rodrido Mora"};
    if(piloto != NULL)
    {
        for(i = 0; i < len; i++)
        {
            piloto = Piloto_newParametros(id[i],nombre[i]);
            ll_add(ListPiloto,piloto);
        }
        printf("Agregado con exito\n");
        returnAux = 0;
    }
    return returnAux;
}
ePiloto* Piloto_new()
{
    ePiloto* pPiloto;

    pPiloto = (ePiloto*)calloc(sizeof(ePiloto),1);
    if(pPiloto == NULL)
    {
        printf("No hay espacio en memoria\n");
        return 0;
    }
    return pPiloto;
}
ePiloto* Piloto_newParametros(char* idPilotoStr, char* nombrePilotoStr)
{
    ePiloto* pPiloto;
    pPiloto = Piloto_new();
    int idPiloto;
    if(pPiloto != NULL && idPilotoStr != NULL && nombrePilotoStr != NULL)
    {
        idPiloto = atoi(idPilotoStr);
        piloto_setId(pPiloto,idPiloto);
        piloto_setNombre(pPiloto,nombrePilotoStr);
    }

    return pPiloto;
}
void ShowPilotos(LinkedList* ListPiloto)
{
    int len;
    int id;
    char nombre[51];
    ePiloto* piloto;
    if(piloto != NULL && ListPiloto != NULL)
    {
        len = ll_len(ListPiloto);
        for(int i = 0; i < len; i++)
        {
            piloto = Piloto_new();
            piloto = ll_get(ListPiloto,i);
            piloto_getId(piloto,&id);
            piloto_getNombre(piloto,nombre);
            printf("%4d \t%10s\n",id, nombre);
        }
    }
}
int WritePilotos(FILE* Archivo, LinkedList* pArrayList)
{
    int len;
    int i;
    int idVuelo;
    int idPiloto;
    char nombrePiloto[51];
    ePiloto* pElementPiloto;
    len = ll_len(pArrayList);
    if(pArrayList != NULL &&  pElementPiloto != NULL && Archivo != NULL)
    {
        fprintf(Archivo,"idPiloto,nombrePiloto\n");
        for(i = 0; i < len; i++)
        {
            pElementPiloto = ll_get(pArrayList,i);
            piloto_getId(pElementPiloto,&idPiloto);
            piloto_getNombre(pElementPiloto,nombrePiloto);

            fprintf(Archivo,"%d,%s\n",idPiloto,nombrePiloto);

        }
    }
    printf("todo ok\n");
    return 0;
}
int filtrarAlexLifesonArchivoPilotos(void* element)
{
    int returnAux = 0;
    char nombrePiloto[51];
    if(element != NULL)
    {
        element = (ePiloto*)element;
        piloto_getNombre(element,nombrePiloto);
        if(strcasecmp(nombrePiloto,"Alex Lifeson")==0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
