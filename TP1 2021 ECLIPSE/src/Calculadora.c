#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

//LA FUNCION SUMA RECIBIRA LOS DOS NUMEROS INGRESADOS POR EL USUARIO Y LOS SUMARA
int suma(int numero1, int numero2)
{

    int sumaRetorno;
    sumaRetorno = numero1 + numero2;

    return sumaRetorno;

}

//LA FUNCION RESTA RECIBIRA LOS DOS NUMEROS INGRESADOS POR EL USUARIO Y LOS RESTARA
int resta(int numero1, int numero2)
{

    int restaRetorno;
    restaRetorno = numero1 - numero2;

    return restaRetorno;

}

//LA FUNCION DIVISION RECIBIRA LOS DOS NUMEROS INGRESADOS POR EL USUARIO Y LOS DIVIDIRA
float division(float numero1, float numero2)
{
    float divisionRetorno;

    divisionRetorno = numero1 / numero2;

    return divisionRetorno;

}

//LA FUNCION MULTIPLICACION RECIBIRA LOS DOS NUMEROS INGRESADOS POR EL USUARIO Y LOS MULTIPLICARA
int multiplicacion(int numero1, int numero2)
{

    int multiplicacionRetorno;
    multiplicacionRetorno = numero1 * numero2;

    return multiplicacionRetorno;

}

//LA FUNCION FACTORIZACION SE ENCARGARA DE CALCULAR EL FACTORIAL
int factorizacion(int numero)
{
    int factorialRetorno = 1;
    int i;

    if(numero != 0)
    {
    	for(i = 1; i <= numero; i++)
    	    {

    	        factorialRetorno = factorialRetorno * i;

    	    }
    }
    else
    {
    	factorialRetorno = 0;
    }


    return factorialRetorno;

}


//LA FUNCION MOSTRARRESULTADOS RECIBIRA LOS RESULTADOS DE TODAS LAS OPERACIONES MATEMATICAS Y LOS MOSTRARA TODOS LLAMANDO A CADA FUNCION PERZONALIDA PARA  CADA RESULTADO
void mostrarResultados(int respuestaSuma, int validacionSuma, int respuestaResta, int validacionResta, float respuestaDivision, int validacionDivision, int respuestaMultiplicacion, int validacionMultiplicacion, int respuestaFactorialUno, int validacionFactorialUno, int respuestaFactorialDos, int validacionFactorialDos)
{

	mostrarSuma(respuestaSuma, validacionSuma);
	mostrarResta(respuestaResta, validacionResta);
	mostrarDivision(respuestaDivision, validacionDivision);
	mostrarMultiplicacion(respuestaMultiplicacion, validacionMultiplicacion);
	mostrarFactorialUno(respuestaFactorialUno, validacionFactorialUno);
	mostrarFactorialUno(respuestaFactorialDos, validacionFactorialDos);
}

//LA FUNCION MOSTRARA EL RESULTADO DE LA SUMA O INFORMARA QUE LA SUMA FALLO O NO SE REALIZO DEPENDIENDO DEL CASO
void mostrarSuma(int respuestaSuma, int validacionSuma)
{
	if(validacionSuma == 1)
	{
		printf ("\nSUMA DE LOS OPERANDOS: %d", respuestaSuma);
	}
	else
	{
		printf ("\nSUMA DE LOS OPERANDOS: SUMA FALLIDA O NO REALIZADA.");
	}

}

//LA FUNCION MOSTRARA EL RESULTADO DE LA RESTA O INFORMARA QUE LA RESTA FALLO O NO SE REALIZO DEPENDIENDO DEL CASO
void mostrarResta(int respuestaResta, int validacionResta)
{
	if(validacionResta == 1)
	{
		printf("\nRESTA DE LOS OPERANDOS: %d", respuestaResta);
	}
	else
	{
		printf ("\nRESTA DE LOS OPERANDOS: RESTA FALLIDA O NO REALIZADA.");
	}

}

//LA FUNCION MOSTRARA EL RESULTADO DE LA DIVISION O INFORMARA QUE LA DIVISION FALLO O NO SE REALIZO DEPENDIENDO DEL CASO
void mostrarDivision(float respuestaDivision, int validacionDivision)
{
	if(validacionDivision == 1)
	{
		printf("\nDIVISION DE LOS OPERANDOS: %f", respuestaDivision);
	}
	else
	{
		printf("\nDIVISION DE LOS OPERANDOS: DIVISION FALLIDA O NO REALIZADA.");
	}

}

//LA FUNCION MOSTRARA EL RESULTADO DE LA MULTIPLICACION O INFORMARA QUE LA MULTIPLICACION FALLO O NO SE REALIZO DEPENDIENDO DEL CASO
void mostrarMultiplicacion(int respuestaMultiplicacion, int validacionMultiplicacion)
{
	if(validacionMultiplicacion == 1)
	{
		printf("\nMULTIPLICACION DE LOS OPERANDOS: %d", respuestaMultiplicacion);
	}
	else
	{
		printf("\nMULTIPLICACION DE LOS OPERANDOS: MULTIPLICACION FALLIDA O NO REALIZADA.");
	}
}

//LA FUNCION MOSTRARA EL RESULTADO DE LA FACTORIZACION O INFORMARA QUE LA FACTORIZACION FALLO O NO SE REALIZO DEPENDIENDO DEL CASO
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

//LA FUNCION MOSTRARA EL RESULTADO DE LA FACTORIZACION O INFORMARA QUE LA FACTORIZACION FALLO O NO SE REALIZO DEPENDIENDO DEL CASO
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
