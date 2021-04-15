#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"


float suma(float numero1, float numero2)
{

	float sumaRetorno;
    sumaRetorno = numero1 + numero2;

    return sumaRetorno;

}

float resta(float numero1, float numero2)
{

	float restaRetorno;
    restaRetorno = numero1 - numero2;

    return restaRetorno;

}

float division(float numero1, float numero2)
{
    float divisionRetorno;

    divisionRetorno = numero1 / numero2;

    return divisionRetorno;

}

float multiplicacion(float numero1, float numero2)
{

	float multiplicacionRetorno;
    multiplicacionRetorno = numero1 * numero2;

    return multiplicacionRetorno;

}

int factorizacion(float numero)
{
	int factorialRetorno = 1;
    int i;

    i = numero;

    if(numero-i == 0)
    {
       for(i = 1; i <= numero; i++)
       {
         factorialRetorno = factorialRetorno * i;
       }
    }
    else
    {
    	factorialRetorno = -1;
    }

    return factorialRetorno;

}

void mostrarResultados(float respuestaSuma, int validacionSuma, float respuestaResta, int validacionResta, float respuestaDivision, int validacionDivision, float respuestaMultiplicacion, int validacionMultiplicacion, int respuestaFactorialUno, int validacionFactorialUno, int respuestaFactorialDos, int validacionFactorialDos)
{

	mostrarSuma(respuestaSuma, validacionSuma);
	mostrarResta(respuestaResta, validacionResta);
	mostrarDivision(respuestaDivision, validacionDivision);
	mostrarMultiplicacion(respuestaMultiplicacion, validacionMultiplicacion);
	mostrarFactorialUno(respuestaFactorialUno, validacionFactorialUno);
	mostrarFactorialUno(respuestaFactorialDos, validacionFactorialDos);
}

void mostrarSuma(float respuestaSuma, int validacionSuma)
{
	if(validacionSuma == 1)
	{
		printf ("\nSUMA DE LOS OPERANDOS: %.2f", respuestaSuma);
	}
	else
	{
		printf ("\nSUMA DE LOS OPERANDOS: SUMA FALLIDA O NO REALIZADA.");
	}

}

void mostrarResta(float respuestaResta, int validacionResta)
{
	if(validacionResta == 1)
	{
		printf("\nRESTA DE LOS OPERANDOS: %.2f", respuestaResta);
	}
	else
	{
		printf ("\nRESTA DE LOS OPERANDOS: RESTA FALLIDA O NO REALIZADA.");
	}

}

void mostrarDivision(float respuestaDivision, int validacionDivision)
{
	if(validacionDivision == 1)
	{
		printf("\nDIVISION DE LOS OPERANDOS: %.2f", respuestaDivision);
	}
	else
	{
		printf("\nDIVISION DE LOS OPERANDOS: DIVISION FALLIDA O NO REALIZADA.");
	}

}

void mostrarMultiplicacion(float respuestaMultiplicacion, int validacionMultiplicacion)
{
	if(validacionMultiplicacion == 1)
	{
		printf("\nMULTIPLICACION DE LOS OPERANDOS: %.2f", respuestaMultiplicacion);
	}
	else
	{
		printf("\nMULTIPLICACION DE LOS OPERANDOS: MULTIPLICACION FALLIDA O NO REALIZADA.");
	}
}

void mostrarFactorialUno(int respuestaFactorialUno, int validacionFactorialUno)
{
	if(validacionFactorialUno == 1)
		{
			printf("\nFACTORIAL DEL OPERANDO A: %d", respuestaFactorialUno);
		}
		else
		{
			printf("\nFACTORIAL DEL OPERANDO A: FACTORIZACION FALLIDA O NO REALIZADA");
		}
}

void mostrarFactorialDos(int respuestaFactorialDos, int validacionFactorialDos)
{
	if(validacionFactorialDos == 1)
			{
				printf("\nFACTORIAL DEL OPERANDO B: %d", respuestaFactorialDos);
			}
			else
			{
				printf("\nFACTORIAL DEL OPERANDO B: FACTORIZACION FALLIDA O NO REALIZADA");
			}
}
