#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#define T 10

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado.
     4. Modificar datos de empleado.
     5. Baja de empleado.
     6. Listar empleados.
     7. Ordenar empleados.
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir.

    ALUMNO: LEANDRO SEOANE. 1°F.
*****************************************************/


int main()
{
    LinkedList* pMiLista;
    pMiLista = ll_newLinkedList();

    int opcionMenu;
    int validarSalir=0;

    printf("\n***** BIENVENIDO AL TRABAJO PRACTICO NRO 3 *****\n");

    do
    {
        printf("\n***** MENU DE OPCIONES *****\n"
               "\n1. Cargar los datos de los empleados desde el archivo data.csv.\n"
               "2. Cargar los datos de los empleados desde el archivo data.bin.\n"
               "3. Alta de empleado.\n"
               "4. Modificar datos de empleado.\n"
               "5. Baja de empleado.\n"
               "6. Listar empleados.\n"
               "7. Ordenar empleados.\n"
               "8. Guardar los datos de los empleados en el archivo data.csv.\n"
               "9. Guardar los datos de los empleados en el archivo data.bin.\n"
               "10. Salir.\n"
               "\nIngrese la opcion que desea realizar: ");
        scanf("%d", &opcionMenu);

        switch(opcionMenu)
        {
        case 1:
            controller_loadFromText("data.csv" , pMiLista);
            break;
        case 2:
            controller_loadFromBinary("data.bin" , pMiLista);
            break;
        case 3:
            controller_addEmployee(pMiLista);
            break;
        case 4:
            controller_editEmployee(pMiLista);
            break;
        case 5:
            controller_removeEmployee(pMiLista);
            break;
        case 6:
            controller_ListEmployee(pMiLista);
            break;
        case 7:
            controller_sortEmployee(pMiLista);
            break;
        case 8:
            controller_saveAsText("data.csv", pMiLista);
            break;
        case 9:
            controller_saveAsBinary("data.bin" , pMiLista);
            break;
        case 10:
            printf("\n***** ESTA A PUNTO DE CERRAR EL PROGRAMA *****\n"
                   "\nTodos los datos que no haya guardado se perderan una vez que cierre el programa.\n"
                   "\nEsta seguro que desea salir? ingrese 1 para si o 0 para no: ");
            scanf("%d",&validarSalir);
            if(validarSalir==1)
            {
                printf("\nGRACIAS POR UTILIZAR EL PROGRAMA!!!\n");
            }
            break;
        }
    }
    while(validarSalir != 1);


    return 0;
}
