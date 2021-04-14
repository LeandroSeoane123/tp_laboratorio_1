
#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

int main()
{
	setbuf(stdout, NULL);

    int numero1;
    int numero2;
    int opcion;
    int respuestaSuma;
    int validacionSuma;
    int respuestaResta;
    int validacionResta;
    int respuestaDivision;
    int validacionDivision;
    int respuestaMultiplicacion;
    int validacionMultiplicacion;
    int respuestaFactorialUno;
    int validacionFactorialUno;
    int respuestaFactorialDos;
    int validacionFactorialDos;

    numero1 = 0;
    numero2 = 0;
    validacionSuma = -1;
    validacionResta = -1;
    validacionDivision = -1;
    validacionMultiplicacion = -1;
    validacionFactorialUno = -1;
    validacionFactorialDos = -1;


    do
    {
        printf ("\n\n***************MENU DE OPCIONES***************"
        		"\n1: Ingresar operando A ***Operando A actual: %d***"
        		"\n2: Ingresar operando B ***Operando B actual: %d***"
        		"\n3: Sumar los operandos"
        		"\n4: Restar los operandos"
        		"\n5: Dividir los operandos"
                "\n6: Multiplicar los operandos"
        		"\n7: Sacar el factorial de los operandos"
        		"\n8: Mostrar resultados"
        		"\n9: Salir ", numero1, numero2);
        printf ("\nPor favor, ingrese la opcion que desea realizar: ");
        scanf ("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf ("\nPor favor, ingrese el operando A: ");
            scanf ("%d",&numero1);
            printf("\n***************NUMERO INGRESADO CON EXITO***************");
            break;
        case 2:
            printf ("\nPor favor, ingrese el operando B: ");
            scanf ("%d",&numero2);
            printf("\n***************NUMERO INGRESADO CON EXITO***************");
            break;
        case 3:
            respuestaSuma = suma (numero1, numero2);
            validacionSuma = 1;
            printf("\n***************NUMEROS SUMADOS CON EXITO***************");
            break;
        case 4:
            respuestaResta = resta(numero1, numero2);
            validacionResta = 1;
            printf("\n***************NUMEROS RESTADOS CON EXITO***************");
            break;
        case 5:
            if(numero1 == 0 || numero2 == 0)
            {
            	printf("\n***************DIVISION FALLIDA, NO SE PUEDE DIVIDIR POR 0***************");
            }
            else
            {
            	respuestaDivision = division (numero1, numero2);
            	validacionDivision = 1;
            	printf("\n***************NUMEROS DIVIDIDOS CON EXITO***************");
            }
            break;
        case 6:
            respuestaMultiplicacion = multiplicacion(numero1, numero2);
            validacionMultiplicacion = 1;
            printf("\n***************NUMEROS MULTIPLICADOS CON EXITO***************");
            break;
        case 7:
            respuestaFactorialUno = factorizacion(numero1);
            validacionFactorialUno = 1;
            respuestaFactorialDos = factorizacion(numero2);
            validacionFactorialDos = 1;
            printf("\n***************FACTORIALES CALCULADOS CON EXITO***************");
            break;
        case 8:
            printf("\n***************MOSTRANDO RESULTADOS*************** ");
            mostrarResultados(respuestaSuma, validacionSuma, respuestaResta, validacionResta, respuestaDivision, validacionDivision, respuestaMultiplicacion, validacionMultiplicacion, respuestaFactorialUno, validacionFactorialUno, respuestaFactorialDos, validacionFactorialDos);
            break;
        case 9:
            opcion = 9;
            printf ("\n***************GRACIAS POR USAR EL PROGRAMA, VUELVA PRONTO!***************\n");
            break;

        }

        if(opcion > 9 || opcion <= 0)
        {
        	printf("\n*****LA OPCION INGRESADA NO ES CORRECTA, INTENTE NUEVAMENTE*****");
        }

    }
    while(opcion!=9);

   return 0;
}
