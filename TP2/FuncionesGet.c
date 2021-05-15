#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "FuncionesGet.h"

#define MAX 1000

char getChar (char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}

int getInt (char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);
    return auxiliarInt;
}

float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}

int esNumerico (char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", mensaje);
    gets(input);
}

int getStringLetras(char mensaje[], char input[])
{
    char auxiliar[256];
    getString(mensaje, auxiliar);
    if(esSoloLetras(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }

    return 0;
}

int getStringNumeros(char mensaje[], char input[])
{
    char auxiliar[256];
    getString(mensaje, auxiliar);
    if(esNumerico(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }

    return 0;
}

int getAlfaNumerico(char mensaje[], char input[])
{
    char auxiliar[256];
    getString(mensaje, auxiliar);
    if(esAlfaNumerico(auxiliar))
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}


