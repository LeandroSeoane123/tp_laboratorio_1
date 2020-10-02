#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleado.h"
#include "validaciones.h"

/** \brief Hardcodea todas las posiciones de isEmpty a 1 (TRUE)
 *         en el array de empleados.
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
void hardcodearEmpleados (eEmpleado arrayEmpleado[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        arrayEmpleado[i].isEmpty = 1;
    }

}

/** \brief La funcion se encargara de pedirle al usuario el nombre, apellido, sueldo y sector
 *         que quiera ingresar y luego los guardara en sus respectivas variables dentro del array de empleados.
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
void cargarEmpleado (eEmpleado arrayEmpleado[], int tam)
{
    int PL;

    PL = buscarLibre(arrayEmpleado, tam);

    if(PL == -1)
    {
        printf("\nNO HAY LUGARES LIBRES");
    }
    else
    {
        printf("\n\n****** ESPACIO LIBRE ENCONTRADO EN LA POSICION %d *****",PL+1);
        printf("\n\nIngrese el nombre del empleado %d: ", PL+1);
        fflush(stdin);
        scanf("%s",&arrayEmpleado[PL].nombre[0]);
        strlwr (arrayEmpleado[PL].nombre);
        arrayEmpleado[PL].nombre[0] = toupper(arrayEmpleado[PL].nombre[0]);
        printf("\nIngrese el apellido del empleado %d: ", PL+1);
        fflush(stdin);
        scanf("%s",&arrayEmpleado[PL].apellido[0]);
        strlwr (arrayEmpleado[PL].apellido);
        arrayEmpleado[PL].apellido[0] = toupper(arrayEmpleado[PL].apellido[0]);
        printf("\nIngrese el sueldo del empleado %s %s: ", arrayEmpleado[PL].nombre, arrayEmpleado[PL].nombre);
        scanf("%f",&arrayEmpleado[PL].sueldo);
        printf("\nIngrese el sector del empleado %s %s: ", arrayEmpleado[PL].nombre, arrayEmpleado[PL].nombre);
        scanf("%d",&arrayEmpleado[PL].sector);
        arrayEmpleado[PL].legajo = PL+1;
        arrayEmpleado[PL].isEmpty = 0;
        printf("\n\n***** EMPLEADO CARGADO CON EXITO ***** \nEl numero de legajo generado para este empleado es: %d", arrayEmpleado[PL].legajo);

    }
}

/** \brief La funcion se encargara de modificar los campos de nombre, apellido, sueldo y sector del empleado que
 *         haya ingresado el usuario.
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
void modificarEmpleado (eEmpleado arrayEmpleado[], int tam)
{
    int auxiliarLegajoLocal;
    int contadorLibreLocal = 0;
    char confirmar;
    int flag = -1;
    int i;

    contadorLibreLocal = contadorDeEspaciosLibres(arrayEmpleado, tam);

    if(contadorLibreLocal == tam)
    {
        mostrarERROR04();
    }
    else
    {
        printf("\n\nIntroduzca el legajo del empleado que quiere modificar aqui: ");
        scanf("%d",&auxiliarLegajoLocal);
        auxiliarLegajoLocal = validarLegajoMayorOMenorA0(auxiliarLegajoLocal);

        for(i=0; i < tam; i++)
        {
            if (auxiliarLegajoLocal == arrayEmpleado[i].legajo)
            {
                printf("\nEMPLEADO ENCONTRADO: \n\nNOMBRE: %s \nAPELLIDO: %s \nLEGAJO: %d"
                       "\n\nPOR FAVOR INGRESE 'S' SI QUIERE MODIFICARLO O 'N' SI QUIERE CANCELAR LA OPERACION: ",arrayEmpleado[i].nombre, arrayEmpleado[i].apellido, arrayEmpleado[i].legajo);
                scanf("%s",&confirmar);
                confirmar = validarSIoNO(confirmar);

                if(confirmar == 's' || confirmar == 'S')
                {
                    printf("\nIngrese el nuevo nombre del empleado %d: ", i+1);
                    fflush(stdin);
                    scanf("%s",&arrayEmpleado[i].nombre[0]);
                    strlwr (arrayEmpleado[i].nombre);
                    arrayEmpleado[i].nombre[0] = toupper(arrayEmpleado[i].nombre[0]);
                    printf("\nIngrese el nuevo apellido del empleado %d: ", i+1);
                    fflush(stdin);
                    scanf("%s",&arrayEmpleado[i].apellido[0]);
                    strlwr (arrayEmpleado[i].apellido);
                    arrayEmpleado[i].apellido[0] = toupper(arrayEmpleado[i].apellido[0]);
                    printf("\nIngrese el nuevo sueldo del empleado %d: ", i+1);
                    scanf("%f",&arrayEmpleado[i].sueldo);
                    printf("\nIngrese el nuevo sector del empleado %d: ", i+1);
                    scanf("%d",&arrayEmpleado[i].sector);
                    printf("\n********** EMPLEADO MODIFICADO CON EXITO **********");
                }

                if(confirmar == 'n' || confirmar == 'N')
                {
                    printf("\n***** OPERACION CANCELADA *****");
                }

                flag = 0;
            }
        }

        if (flag == -1)
        {
            mostarERROR00();
        }
    }
}

/** \brief La funcion se encargara de borrar el empleado que haya ingresado el usuario y cambiar el estado de isEmpety a 1 (TRUE) del empleado que
 *         haya ingresado el usuario.
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
void borrarEmpleado (eEmpleado arrayEmpleado[], int tam)
{
    int auxiliarLegajoLocal;
    int i;
    int flag = -1;
    int contadorLibreLocal = 0;
    char confirmar;

    contadorLibreLocal = contadorDeEspaciosLibres(arrayEmpleado, tam);

    if(contadorLibreLocal == tam)
    {
        mostrarERROR04();
    }
    else
    {
        printf("\n\nPor favor, introduzca el legajo del empleado que desea borrar: ");
        scanf("%d",&auxiliarLegajoLocal);
        auxiliarLegajoLocal = validarLegajoMayorOMenorA0(auxiliarLegajoLocal);

        for(i=0; i < tam; i++)
        {
            if (auxiliarLegajoLocal == arrayEmpleado[i].legajo)
            {
                flag = 0;
                printf("\nEMPLEADO ENCONTRADO: \n\nNOMBRE: %s \nAPELLIDO: %s \nLEGAJO: %d"
                       "\n\nPOR FAVOR INGRESE 'S' SI QUIERE BORARLO O 'N' SI QUIERE CANCELAR LA OPERACION: ",arrayEmpleado[i].nombre, arrayEmpleado[i].apellido, arrayEmpleado[i].legajo);
                scanf("%s",&confirmar);
                confirmar = validarSIoNO(confirmar);

                if(confirmar == 's' || confirmar == 'S')
                {
                    strcpy(arrayEmpleado[i].nombre, " ");
                    strcpy(arrayEmpleado[i].apellido, " ");
                    arrayEmpleado[i].sueldo = 0;
                    arrayEmpleado[i].sector = 0;
                    arrayEmpleado[i].legajo = i-10;
                    arrayEmpleado[i].isEmpty = 1;
                    printf("\n\n********** EMPLEADO BORRADO CON EXITO **********");
                }
            }
        }

        if(confirmar == 'n' || confirmar == 'N')
        {
            printf("\n***** OPERACION CANCELADA *****");
        }

        if (flag == -1)
        {
            mostarERROR00();
        }
    }
}

/** \brief La funcion se encargara de buscar el primer lugar libre dentro del array de empleados.
 *
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
int buscarLibre (eEmpleado arrayEmpleado[], int tam)
{
    int i;
    int espacioLibre = -1;

    for (i=0; i < tam; i++)
    {
        if (arrayEmpleado[i].isEmpty == 1)
        {
            espacioLibre = i;
            break;
        }
    }
    return espacioLibre;
}

/** \brief La funcion se encargara de contar los espacios libres dentro del array de empleados.
 *
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
int contadorDeEspaciosLibres (eEmpleado arrayEmpleado[], int tam)
{
    int contadorLibreLocal = 0;
    int i;

    for (i=0; i < tam; i++)
    {
        if (arrayEmpleado[i].isEmpty == 1)
        {
            contadorLibreLocal++;
        }
    }
    return contadorLibreLocal;
}

/** \brief La funcion se encargara ordenar el array de empleados alfabeticamente.
 *
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
void ordenarPorNombre (eEmpleado arrayEmpleado[], int tam)
{
    int i;
    int j;
    eEmpleado auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(arrayEmpleado[i].nombre,arrayEmpleado[j].nombre)>0)
            {
                auxEmpleado = arrayEmpleado[i];
                arrayEmpleado[i] = arrayEmpleado[j];
                arrayEmpleado[j] = auxEmpleado;
            }
        }
    }
}

/** \brief La funcion se encargara de ordenar el array de empleados por su sueldo de forma ascendente.
 *
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
void ordenarPorSueldo (eEmpleado arrayEmpleado[], int tam)
{
    int i;
    int j;
    eEmpleado auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(arrayEmpleado[i].sueldo > arrayEmpleado[j].sueldo)
            {
                auxEmpleado = arrayEmpleado[i];
                arrayEmpleado[i] = arrayEmpleado[j];
                arrayEmpleado[j] = auxEmpleado;
            }
        }
    }
}

/** \brief La funcion se encargara calcular el promedio de sueldos de todos los empleados dentro del array de empleados.
 *
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 * \param  Sueldos sumados de todos los empleados.
 *
 */
int SacarPromedioSueldos (eEmpleado arrayEmpleado[], int tam, int totalSueldos)
{
    float promedioDeSueldos;
    int contadorDivisor = 0;
    int i;

    for (i=0; i < tam; i++)
    {
        if (arrayEmpleado[i].isEmpty == 0)
        {
            contadorDivisor++;
        }
    }

    promedioDeSueldos = totalSueldos / contadorDivisor;

    return promedioDeSueldos;

}

/** \brief La funcion se encargara de sumar todos los sueldos dentro del array de empleados.
 *
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 *
 */
int sumarSueldos (eEmpleado arrayEmpleado[], int tam)
{
    int i;
    int sumaDeSueldos = 0;

    for(i=0; i < tam; i++)
    {
        sumaDeSueldos = sumaDeSueldos + arrayEmpleado[i].sueldo;
    }

    return sumaDeSueldos;
}

/** \brief La funcion se encargara de contar todos los empleados que superen el
 *         sueldo promedio dentro del array de empleados.
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 * \param  Promedio de sueldos del array de empleados.
 *
 */
int contarEmpleadosQueSuperenSalarioPromedio (eEmpleado arrayEmpleado[], int tam, float promedio)
{
    int i;
    int contadorEmpleados = 0;

    for(i=0; i < tam; i++)
    {
        if(arrayEmpleado[i].sueldo > promedio)
        {
            contadorEmpleados++;
        }
    }

    return contadorEmpleados;
}

/** \brief La funcion se encargara listar los empleados con todos sus campos junto a la sumatoria de sueldos, el promedio de sueldos
 *         y cuantos de los empleados superan el promedio de sueldo.
 * \param  Array de empleados.
 * \param  Tamaño del array de empleados.
 * \param  Suma de sueldos del array de empleados.
 * \param  Promedio de sueldos del array de empleados.
 * \param  Cantidad de personas que superan el sueldo promedio en el array de empleados.
 *
 */
void listarEmpleados (eEmpleado arrayEmpleado[], int tam, int sumaSueldos, float promedioSueldos, int contadorEmpleadosArribaDelPromedio)
{
    int i;
    int opcionOrdenar = 0;

    opcionOrdenar = validarOpcionOrdenar(opcionOrdenar);
    if(opcionOrdenar == 1)
    {
        ordenarPorNombre(arrayEmpleado, tam);
    }
    else
    {
        ordenarPorSueldo(arrayEmpleado, tam);
    }

    printf("\n\n----------NOMBRE-----APELLIDO-----SUELDO-------SECTOR-----LEGAJO---------- ");

    for (i=0; i < tam; i++)
    {
        if(arrayEmpleado[i].isEmpty == 0)
        {
            printf("\n\n%15s %12s %14.2f %6d %13d", arrayEmpleado[i].nombre,
                   arrayEmpleado[i].apellido,
                   arrayEmpleado[i].sueldo,
                   arrayEmpleado[i].sector,
                   arrayEmpleado[i].legajo);

        }
    }

    printf("\n\n***** EL TOTAL DE SUELDOS ES: %d *****", sumaSueldos);
    printf("\n\n***** EL PROMEDIO DE SUELDOS ES: %.2f *****", promedioSueldos);
    printf("\n\n***** LA CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO DE SUELDOS ES: %d *****\n", contadorEmpleadosArribaDelPromedio);
}


