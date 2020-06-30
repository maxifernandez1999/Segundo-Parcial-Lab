#include "controller.h"

int controller_FernandezLoadArchive(char* path,LinkedList* List) //se contrala si es nulo
{
    FILE* Archivo;
    int returnAux = -1;
    Archivo = fopen(path,"r");
    if(Archivo != NULL)
    {
        ReadFileAsText(Archivo,List);
    }
    fclose(Archivo);
    returnAux = 0;
    return returnAux;
}
int controller_FernandezLoadArchivePiloto(char* path,LinkedList* List) //se contrala si es nulo
{
    FILE* Archivo;
    int returnAux = -1;
    Archivo = fopen(path,"r");
    if(Archivo != NULL)
    {
        ReadFileAsTextPiloto(Archivo,List);
    }
    fclose(Archivo);
    returnAux = 0;
    return returnAux;
}

int controller_FernandezSaveArchive(char* path,LinkedList* List)
{
    FILE* Archivo;
    int returnAux = -1;
    Archivo = fopen(path,"w");
    if(Archivo != NULL)
    {
        WriteFileAsText(Archivo,List);
    }
    fclose(Archivo);
    returnAux = 0;
    return returnAux;
}
int controller_FernandezSaveArchiveAsName(char* path,LinkedList* List,LinkedList* ListPilotos)
{
    FILE* Archivo;
    int returnAux = -1;
    Archivo = fopen(path,"w");
    if(Archivo != NULL)
    {
        WriteFileAsTextByName(Archivo,List,ListPilotos);
    }
    fclose(Archivo);
    returnAux = 0;
    return returnAux;
}
int controller_FernandezWritePiloto(char* path,LinkedList* List)
{
    FILE* Archivo;
    int returnAux = -1;
    Archivo = fopen(path,"w");
    if(Archivo != NULL)
    {
        WritePilotos(Archivo,List);
    }
    fclose(Archivo);
    returnAux = 0;
    return returnAux;
}
/*void controller_FernandezShowLifeson(LinkedList* myList, LinkedList* myListPilotos)
{
    LinkedList* myListAlexLifeson1;
    myListAlexLifeson1 = ll_filter(myList,filtrarAlexLifeson);
    printf("Alex Lifeson\n");
    ShowAirlinesByNamePilots(myListAlexLifeson1,myListPilotos);
}*/



