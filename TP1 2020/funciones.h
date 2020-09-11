#include "funciones.c"

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

//LA FUNCION DIVISION RECIBIRA LOS DOS NUMEROS INGRESADOS POR EL USUARIO Y LOS DIVIDIRA, LA DIVISION POR 0 ARROJARA UN MENSAJE DE ERROR
float division(float numero1, float numero2)
{
    float divisionRetorno;

    if(numero1 != 0 && numero2 != 0)
    {

        divisionRetorno = numero1 / numero2;

    }
    else
    {
        printf("***************NO ES POSIBLE DIVIDIR POR 0***************");
    }

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
int factorizacion(int numero1)
{
    int factorialRetorno = 1;
    int i;
    for(i = 1; i <= numero1; i++)
    {

        factorialRetorno = factorialRetorno * i;

    }

    return factorialRetorno;

}


//LA FUNCION MOSTRARRESULTADOS RECIBIRA LOS RESULTADOS DE TODAS LAS OPERACIONES MATEMATICAS Y LOS MOSTRARA TODOS UNO ABAJO DEL OTRO
void mostrarResultados(int respuestaSuma, int respuestaResta, float respuestaDivision, int respuestaMultiplicacion, int respuestaFactorialUno, int respuestaFactorialDos)
{

    printf ("\nSUMA DE LOS OPERANDOS: %d \nRESTA DE LOS OPERANDOS: %d \nDIVISION DE LOS OPERANDOS: %f \nMULTIPLICACION DE LOS OPERANDOS: %d, \nFACTORIAL DEL OPERANDO A: %d, \nFACTORIAL DEL OPERANDO B: %d", respuestaSuma, respuestaResta, respuestaDivision, respuestaMultiplicacion, respuestaFactorialUno, respuestaFactorialDos);

}
