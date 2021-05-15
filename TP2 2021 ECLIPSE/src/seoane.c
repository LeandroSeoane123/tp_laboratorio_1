#include "seoane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getInt (char* mensaje, int* entero)
{
    printf(mensaje);
    scanf("%d", entero);
}

void getFloat (char* mensaje, float* flotante)
{
    printf(mensaje);
    scanf("%f", flotante);
}

void getString(char* mensaje, char* cadena)
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);
}

void getChar (char* mensaje, char* caracter)
{
    printf(mensaje);
    fflush(stdin);
    scanf("%c", caracter);
}

void validarMenu (int opcion, int opcionMenor, int opcionMayor)
{
    if(opcion <opcionMenor || opcion >opcionMayor)
    {
        puts("\nLa opcion ingresada es incorrecta.");
    }
}

void limpiarPantalla ()
{
    fflush(stdin);
    getchar();
    system("cls");
}


