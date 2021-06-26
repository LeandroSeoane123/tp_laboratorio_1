#define TE 1000
#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "seoane.h"

int main()
{

   setbuf(stdout, NULL);

   int opcion;
   eEmpleado arrayDeEmpleados[TE];

   hardcodearEmpleados(arrayDeEmpleados, TE);

   do
    {
        getInt("***** ABM EMPLEADOS: MENU DE OPCIONES *****"
               "\n1. Alta de empleado."
               "\n2. Modificacion de empleado."
               "\n3. Baja de empleado."
               "\n4. Listado de empleados."
               "\n5. Listado de empleados ordenados."
               "\n6. Listar el total y el promedio de los salarios y cuantos empleados superan el salario promedio"
               "\n7. Salir."
               "\nIngrese la opcion que desea realizar: ", &opcion);

        switch(opcion)
        {
        case 1:
            cargarEmpleado(arrayDeEmpleados, TE);
            break;
        case 2:
            modificarEmpleado(arrayDeEmpleados, TE);
            break;
        case 3:
            borrarEmpleado(arrayDeEmpleados, TE);
            break;
        case 4:
            mostrarEmpleados(arrayDeEmpleados, TE);
            break;
        case 5:
            ordenarEmpleados(arrayDeEmpleados, TE);
            break;
        case 6:
            mostrarTotalYPromedioSalariosYEmpleadosSuperiorPromedio(arrayDeEmpleados, TE);
            break;
        case 7:
            puts("\nGracias por utilizar el programa!");
            break;
        }

        validarMenu(opcion, 1, 7);
        limpiarPantalla();

    }while(opcion !=7);

    return EXIT_SUCCESS;
}
