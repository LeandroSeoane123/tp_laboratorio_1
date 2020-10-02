#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "validaciones.h"
#define CANT 10


int main()
{
    char opcion;
    char continuarCargando;
    char continuarModificando;
    char continuarBorrando;
    int contadorLibreLocal;
    int empleadosQueSuperanPromedio = 0;
    int sumaDeSueldos;
    float promedioSueldos;

    eEmpleado arrayDeEmpleados[CANT];
    hardcodearEmpleados (arrayDeEmpleados, CANT);

    do
    {
        printf("\n\n********** MENU DE OPCIONES **********\n \n1: Cargar empleado. \n2: Modificar empleado."
               "\n3: Borrar empleado. \n4: Listar empleados. \n5: SALIR\n \nPor favor, ingrese el numero de opcion que desea realizar: ");
        scanf("%s",&opcion);
        opcion = validarOpcionMenu(opcion);

        switch(opcion)
        {
        case '1':
            do
            {
                cargarEmpleado(arrayDeEmpleados, CANT);
                printf("\n\nDesea continuar cargando empleados? \nIngrese 'S' si desea continuar, o 'N' si quiere volver al menu: ");
                scanf("%s",&continuarCargando);
                continuarCargando = validarSIoNO(continuarCargando);
            }
            while(continuarCargando == 's');
            break;

        case '2':
            do
            {
                modificarEmpleado(arrayDeEmpleados, CANT);
                printf("\n\nDesea continuar modificando empleados? \nIngrese 'S' si desea continuar, o 'N' si quiere volver al menu: ");
                scanf("%s",&continuarModificando);
                continuarModificando = validarSIoNO(continuarModificando);
            }
            while(continuarModificando == 's');
            break;
        case '3':
            do
            {
                borrarEmpleado(arrayDeEmpleados, CANT);
                printf("\n\nDesea continuar borrando empleados? \nIngrese 'S' si desea continuar, o 'N' si quiere volver al menu: ");
                scanf("%s",&continuarBorrando);
                continuarBorrando = validarSIoNO(continuarBorrando);
            }
            while(continuarBorrando == 's');
            break;

        case '4':
            contadorLibreLocal = contadorDeEspaciosLibres(arrayDeEmpleados, CANT);

            if (contadorLibreLocal == CANT)
            {
                mostrarERROR04();
            }
            else
            {
                sumaDeSueldos = sumarSueldos(arrayDeEmpleados, CANT);
                promedioSueldos = SacarPromedioSueldos(arrayDeEmpleados, CANT, sumaDeSueldos);
                empleadosQueSuperanPromedio = contarEmpleadosQueSuperenSalarioPromedio (arrayDeEmpleados, CANT, promedioSueldos);
                listarEmpleados(arrayDeEmpleados, CANT, sumaDeSueldos, promedioSueldos, empleadosQueSuperanPromedio);
            }
            break;
        }
    }
    while(opcion != '5');

    printf("\n\n********** GRACIAS POR UTILIZAR EL PROGRAMA **********\n\n");

    return 0;
}
