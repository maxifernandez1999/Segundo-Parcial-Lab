#include <stdio.h>
#include "input.h"

int getInt(char message[], char errorMessage[], int min, int max)
{
    int option;

    printf("%s", message);
    scanf("%d", &option);
    while(option < min || option > max)
    {
        printf("%s", errorMessage);
        scanf("%d", &option);
    }

    return option;
}
float getFloat(char message[], char errorMessage[], float min, float max)
{
    float number;

    printf("%s", message);
    scanf("%f", &number);
    while(number < min || number > max)
    {
        printf("%s", errorMessage);
        scanf("%f", &number);
    }

    return number;
}
char getCharacter(char message[], char errorMessage[], char min, char max)
{
    char character;

    printf("%s", message);
    fflush(stdin);
    scanf("%c", &character);
    while(character < min || character > max)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%c", &character);
    }

    return character;
}
void getString(char mensaje[], char string[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(string);
}
int getId(int counter)
{
    int acumuladorId = 0;
    acumuladorId+=counter;
    return acumuladorId;
}

