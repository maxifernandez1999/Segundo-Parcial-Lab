#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "input.h"
#include "Aerolineas.h"
#include "Pilotos.h"
#include "controller.h"
int main()
{
    //CAMBIAR LINKEDLIST
    //CORREGIR FUNCIONES FILTER
    int opcion;
    int ret;
    int entero;
    int ret2;
    LinkedList* myList;
    LinkedList* myListBach;
    LinkedList* myListKerry;
    LinkedList* myListRommel;
    LinkedList* myListCoonts;
    LinkedList* myListAlexLifeson1;
    LinkedList* myListAuxPortugal;
    LinkedList* myListPilotos;
    LinkedList* myListVuelosCortos;
    LinkedList* myListPortugal;
    LinkedList* myListAlexLifeson;
    myListPilotos = ll_newLinkedList();

    LinkedList* AlexLifeson;
    myList = ll_newLinkedList();
    do
    {
        printf("***********AEROLINEAS***********\n");
        printf("1. Cargar Archivos\n");
        printf("2. Imprimir vuelos\n");
        printf("3. Cantidad de pasajeros\n");
        printf("4. Cantidad de pasajeros a Irlanda\n");
        printf("5. Filtrar vuelos cortos\n");
        printf("6. Listar vuelos a Portugal\n");
        printf("7. Filtrar a Alex Lifeson\n");
        printf("8. Filtrar la lista de pilotos por nombre\n");
        printf("9. Filtrar la lista de pilotos por nombre con sus vuelos\n");
        printf("10. Filtrar alex Lifeson destino Alemania\n");
        printf("11. Mostrar pilotos\n");
        printf("12. Salir");
        opcion = getInt("Ingrese una opcion\n","Error, reingrese una opcion\n",1,12);
        system("cls");
        switch(opcion)
        {
            case 1:
                controller_FernandezLoadArchive("Vuelos.csv",myList);
                controller_FernandezLoadArchivePiloto("Pilotos.csv",myListPilotos);
                //AddPiloto(myListPilotos,10);
            break;
            case 2:
                //controller_FernandezWritePiloto("Pilotos.csv",myListPilotos);
                ShowAirlinesByNamePilots(myList,myListPilotos);
            break;
            case 3:
                ret = ll_count(myList,getCantPasajeros);
                printf("El total de pasajeros es de: %d\n",ret);
            break;
            case 4:
                ret2 = ll_count(myList,getCantPasajerosIrlanda);
                printf("El total de pasajeros a Irlanda es de: %d\n", ret2);
            break;
            case 5:
                myListVuelosCortos = ll_filter(myList,filtrarVuelosCortos);
                ShowAirlinesByNamePilots(myListVuelosCortos,myListPilotos);
                controller_FernandezSaveArchive("VueloCortos.csv",myListVuelosCortos);
            break;
            case 6:
                myListPortugal = ll_filter(myList,filtrarPortugal);
                ShowAirlinesByNamePilots(myListPortugal,myListPilotos);
            break;
            case 7:
                myListAlexLifeson = ll_filter(myList,filtrarNOAlexLifeson);
                ShowAirlinesByNamePilots(myListAlexLifeson,myListPilotos);
            break;
            case 8:
                AlexLifeson = ll_filter(myListPilotos,filtrarAlexLifesonArchivoPilotos);
                ShowPilotos(AlexLifeson);
            break;
            case 9:
                printf("Menu vuelo\n");
                entero = getInt("1. Lifeson\n 2. Bach\n 3. Kerry\n 4. Rommel\n 5. Coonts\n","Error ingrese opcion correcta\n",1,5);
                switch(entero)
                {
                    case 1:
                        myListAlexLifeson1 = ll_filter(myList,filtrarAlexLifeson);
                        printf("Alex Lifeson\n");
                        ShowAirlinesByNamePilots(myListAlexLifeson1,myListPilotos);
                        controller_FernandezSaveArchive("VueloLifeson.csv",myListAlexLifeson1);
                    break;
                    case 2:
                        myListBach = ll_filter(myList,filtrarRichardBach);
                        printf("Alex Bach\n");
                        ShowAirlinesByNamePilots(myListBach,myListPilotos);
                        controller_FernandezSaveArchive("VueloBach.csv",myListBach);
                    break;
                    case 3:
                        myListKerry = ll_filter(myList,filtrarJohnKerry);
                        printf("Alex Kerry\n");
                        ShowAirlinesByNamePilots(myListKerry,myListPilotos);
                        controller_FernandezSaveArchive("VueloKerry.csv",myListKerry);
                    break;
                    case 4:
                        myListRommel = ll_filter(myList,filtrarErwinRommel);
                        printf("Alex Rommel\n");
                        ShowAirlinesByNamePilots(myListRommel,myListPilotos);
                        controller_FernandezSaveArchive("VueloRommel.csv",myListRommel);
                    break;
                    case 5:
                        myListCoonts = ll_filter(myList,filtrarStephenCoonts);
                        printf("Alex Coonts\n");
                        ShowAirlinesByNamePilots(myListCoonts,myListPilotos);
                        controller_FernandezSaveArchive("VueloCoonts.csv",myListCoonts);
                    break;
                }
            break;
                case 10:
                    myListAuxPortugal = ll_filter_parametro(myList,filtrarAlexLifeson,"Alemania");
                    ShowAirlinesByNamePilots(myListAuxPortugal,myListPilotos);
                break;
                case 11:
                    ShowPilotos(myListPilotos);
                break;
            default:
            break;
        }
    }while(opcion != 12);

    return 0;
}
