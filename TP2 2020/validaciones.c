#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "empleado.h"

/** \brief La funcion se encarga de validar que el usuario solo
 *         ingrese s para SI o n para NO.
 * \param Recibe la validacion cargada con lo que haya ingresado el usuario.
 * \return validacion que solo es s o n.
 *
 */
char validarSIoNO(char validacion)
{
    while(validacion != 's' && validacion != 'S' && validacion != 'n' && validacion != 'N' )
    {
        printf("\n\n***** ERROR 03 ***** \n\nLa opcion ingresada no es correcta, por favor intentelo nuevamente. \n\nIngrese 'S' para 'SI', o 'N' para 'NO': ");
        scanf("%s",&validacion);
    }

    return validacion;
}

/** \brief La funcion valida que solo se ingrese una de las opciones del menu
 *         ya sea 1,2,3,4 o 5.
 * \param  Recibe la opcion ingresada por el usuario.
 * \return Retorna la opcion validada que solo puede ser 1,2,3,4 o 5.
 *
 */
char validarOpcionMenu (char opcionMenu)
{
    while(opcionMenu != '1' &&  opcionMenu != '2' && opcionMenu != '3' && opcionMenu != '4' && opcionMenu != '5')
    {
        printf("\n\n***** ERROR 03 ***** \n\nLa opcion ingresada no es correcta, por favor intentelo nuevamente. \n\nIngrese el numero de opcion que desea realizar (1 a 5): ");
        scanf("%s",&opcionMenu);
    }

    return opcionMenu;

}

/** \brief La funcion se encarga de pedirle al usuario que ingrese la forma en que quiere ordenar la lista de empleados,
 *         para luego validar que la opcion ingresada sea solo 1 o 2.
 * \param  Recibe la opcion ingresada por el usuario.
 * \return Retorna la opcion validada que solo serae 1 o 2.
 *
 */
int validarOpcionOrdenar (int opcionOrdenar)
{

    printf("\nDesea mostrar el listado de empleados ordenado por nombre o por sueldo? \nIngrese 1 si quiere listar por nombre, o 2 si quiere listar por sueldo: ");
    scanf("%d",&opcionOrdenar);
    while(opcionOrdenar != 1 && opcionOrdenar != 2)
    {
        printf("\n\n***** ERROR 03 ***** \n\nLa opcion ingresada no es correcta, por favor intentelo nuevamente. \n\nIngrese 1 si quiere listar por nombre, o 2 si quiere listar por sueldo: ");
        scanf("%d",&opcionOrdenar);
    }

    return opcionOrdenar;

}

/** \brief La funcion valida que el legajo ingresado sea mayor que 0.
 *
 * \param Recibe el legajo ingresado por el usuario
 * \return Retorna el legajo validado que sera si o si mayor a 0
 *
 */
int validarLegajoMayorOMenorA0 (int legajo)
{
    while(legajo == 0 || legajo < 0)
    {
        printf("\n\n***** ERROR 02 ***** \nEl legajo ingresado es erroneo, asegurese de ingresar un numero de legajo mayor a 0: ");
        scanf("%d",&legajo);
    }

    return legajo;
}

/** \brief Muestra el error 00
 *
 * \return void
 *
 */
void mostarERROR00()
{
    printf("\n\n***** ERROR 00: EL LEGAJO INGRESADO NO SE CORRESPONDE CON NINGUN EMPLEADO ACTUAL *****\n");
}

/** \brief Muestra el error 04
 *
 * \return void
 *
 */
void mostrarERROR04()
{
    printf("\n\n***** ERROR 04 ***** \n\nNo hay empleados cargados, debe cargar al menos un empleado para poder realizar esta accion.");
}
