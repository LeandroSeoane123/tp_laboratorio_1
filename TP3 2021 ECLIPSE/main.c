#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Seoane.h"
#define T 10

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	FILE* pFile;

	pFile = fopen("config.csv", "w");

	if(pFile!=NULL)
	{
		fprintf(pFile, "%d", 1000);
	}

	fclose(pFile);

    int option = 0;
    int validarSalir = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();


    do
        {
            getInt("\n***** MENU DE OPCIONES *****\n"
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
                    "\nIngrese la opcion que desea realizar: ", &option);

            switch(option)
            {
            case 1:
                controller_loadFromText("data.csv" , listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("data.bin" , listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.csv", listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin" , listaEmpleados);
                break;
            case 10:
                getInt("\n***** ESTA A PUNTO DE CERRAR EL PROGRAMA *****\n"
                        "\nTodos los datos que no haya guardado se perderan una vez que cierre el programa.\n"
                        "\nEsta seguro que desea salir? ingrese 1 para si o 0 para no: ", &validarSalir);
                if(validarSalir==1)
                {
                    printf("\nGRACIAS POR UTILIZAR EL PROGRAMA!!!\n");
                }
                break;
            }

            validarMenu(option, 1, 10);
            limpiarPantalla();

        }
        while(validarSalir != 1);

    return 0;
}
