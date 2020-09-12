#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//LA FUNCION MAIN CONTENDRA EL MENU DE OPCIONES A ELEGIR POR EL USUARIO, CON SUS RESPECTIVAS INVOCACIONES A LAS FUNCIONES (SUMA, RESTA, DIVISION, MULTIPLICACION, FACTOREO, MOSTRARRESULTADOS)
int main()
{
    int numero1;
    int numero2;
    int opcion;
    int respuestaSuma;
    int respuestaResta;
    float respuestaDivision;
    int respuestaMultiplicacion;
    int respuestaFactorialUno;
    int respuestaFactorialDos;

    numero1 = 0;
    numero2 = 0;

    do
    {
        printf ("\n\n***************MENU DE OPCIONES*************** \n1: Ingresar operando A ***Operando A actual: %d*** \n2: Ingresar operando B ***Operando B actual: %d*** \n3: Sumar los operandos \n4: Restar los operandos \n5: Dividir los operandos \n6: Multiplicar los operandos \n7: Sacar el factorial de los operandos  \n8: Mostrar resultados \n9: Salir ", numero1, numero2);
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
            printf("\n***************NUMEROS SUMADOS CON EXITO***************");
            break;
        case 4:
            respuestaResta = resta(numero1, numero2);
            printf("\n***************NUMEROS RESTADOS CON EXITO***************");
            break;
        case 5:
            respuestaDivision = division(numero1, numero2);
            if (respuestaDivision == 0)
            {
                printf("\n***************DIVISION FALLIDA, NO SE PUEDE DIVIDIR POR 0***************");
            }
            else
            {
                printf("\n***************NUMEROS DIVIDIDOS CON EXITO***************");
            }
            break;
        case 6:
            respuestaMultiplicacion = multiplicacion(numero1, numero2);
            printf("\n***************NUMEROS MULTIPLICADOS CON EXITO***************");
            break;
        case 7:
            respuestaFactorialUno = factorizacion(numero1);
            respuestaFactorialDos = factorizacion(numero2);
            printf("\n***************FACTORIALES CALCULADOS CON EXITO***************");
            break;
        case 8:
            printf("\n***************MOSTRANDO RESULTADOS*************** ");
            mostrarResultados(respuestaSuma, respuestaResta, respuestaDivision, respuestaMultiplicacion, respuestaFactorialUno, respuestaFactorialDos);
            break;
        case 9:
            opcion = 9;
            printf ("\n***************GRACIAS POR USAR EL PROGRAMA, VUELVA PRONTO!***************\n");
            break;

        }

    }
    while(opcion!=9);

}
