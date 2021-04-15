
#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

int main()
{
	setbuf(stdout, NULL);

    float numero1;
    float numero2;
    int validacionNumero1;
    int validacionNumero2;
    int opcion;
    float respuestaSuma;
    int validacionSuma;
    float respuestaResta;
    int validacionResta;
    float respuestaDivision;
    int validacionDivision;
    float respuestaMultiplicacion;
    int validacionMultiplicacion;
    int respuestaFactorialUno;
    int validacionFactorialUno;
    int respuestaFactorialDos;
    int validacionFactorialDos;

    numero1 = 0;
    numero2 = 0;
    validacionNumero1 = -1;
    validacionNumero2 = -1;
    validacionSuma = -1;
    validacionResta = -1;
    validacionDivision = -1;
    validacionMultiplicacion = -1;
    validacionFactorialUno = -1;
    validacionFactorialDos = -1;


    do
    {
        printf ("\n\n***************MENU DE OPCIONES***************"
        		"\n1: Ingresar operando A ***Operando A actual: %.2f***"
        		"\n2: Ingresar operando B ***Operando B actual: %.2f***"
        		"\n3: Calcular todas las operaciones:"
        		"\n   A)Suma"
        		"\n   B)Resta"
        		"\n   C)Division"
        		"\n   D)Multiplicacion"
        		"\n   E)Factorizacion"
        		"\n4: Mostrar los resultados"
        		"\n5: Salir ", numero1, numero2);
        printf ("\nPor favor, ingrese la opcion que desea realizar: ");
        scanf ("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf ("\nPor favor, ingrese el operando A: ");
            scanf ("%f",&numero1);
            validacionNumero1 = 1;
            printf("\n***************NUMERO INGRESADO CON EXITO***************");
            break;
        case 2:
            printf ("\nPor favor, ingrese el operando B: ");
            scanf ("%f",&numero2);
            validacionNumero2 = 1;
            printf("\n***************NUMERO INGRESADO CON EXITO***************");
            break;
        case 3:
        	if(validacionNumero1 == 1 && validacionNumero2 == 1)
        	{
        		respuestaSuma = suma (numero1, numero2);
        	    validacionSuma = 1;
        		printf("\n***************NUMEROS SUMADOS CON EXITO***************");
        		respuestaResta = resta(numero1, numero2);
        		validacionResta = 1;
        		printf("\n***************NUMEROS RESTADOS CON EXITO***************");
        		if(numero2 == 0)
        		{
        		    printf("\n***************DIVISION FALLIDA, NO SE PUEDE DIVIDIR POR 0***************");
        		    validacionDivision = -1;
        	    }
        		else
        		{
        		    respuestaDivision = division (numero1, numero2);
        		    validacionDivision = 1;
        		    printf("\n***************NUMEROS DIVIDIDOS CON EXITO***************");
        		}
        		respuestaMultiplicacion = multiplicacion(numero1, numero2);
        		validacionMultiplicacion = 1;
        		printf("\n***************NUMEROS MULTIPLICADOS CON EXITO***************");
        		respuestaFactorialUno = factorizacion(numero1);
        		if(respuestaFactorialUno != -1)
        		{
        			validacionFactorialUno = 1;
        		}
        		respuestaFactorialDos = factorizacion(numero2);
        		if(respuestaFactorialDos != -1)
        		{
        			validacionFactorialDos = 1;
        		}
        		printf("\n***************FACTORIALES CALCULADOS CON EXITO***************");
        	}
        	else
        	{
        		printf("\nERROR: Para poder realizar las operaciones asegurese de haber ingresado ambos operandos.");
        	}
            break;
        case 4:
            printf("\n***************MOSTRANDO RESULTADOS*************** ");
            mostrarResultados(respuestaSuma, validacionSuma, respuestaResta, validacionResta, respuestaDivision, validacionDivision, respuestaMultiplicacion, validacionMultiplicacion, respuestaFactorialUno, validacionFactorialUno, respuestaFactorialDos, validacionFactorialDos);
            break;
        case 5:
            printf ("\n***************GRACIAS POR USAR EL PROGRAMA, VUELVA PRONTO!***************\n");
            break;
        }

        if(opcion > 5 || opcion <= 0)
        {
        	printf("\n*****LA OPCION INGRESADA NO ES CORRECTA, INTENTE NUEVAMENTE*****");
        }

        if(opcion != 5)
        {
        	printf("\n\nPulse enter para continuar.");
        }

        fflush(stdin);
        getchar();
        system("cls");
    }
    while(opcion!=5);

   return 0;
}
