#define VACIO 1
#define OCUPADO 0
#include "empleado.h"
#include "seoane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hardcodearEmpleados(eEmpleado arrayEmpleado[], int tam)
{
  int i;
  int retorno;

  retorno = -1;

  for(i=0; i<tam; i++)
  {
      arrayEmpleado[i].isEmpty = VACIO;
      retorno = 1;
  }

  return retorno;
}

int cargarEmpleado(eEmpleado arrayEmpleado[], int tam)
{
    int retorno;
    int pos;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;

    retorno = -1;
    pos = buscarLibre(arrayEmpleado, tam);

    if(pos != -1)
    {
        puts("\nLUGAR LIBRE ENCONTRADO.");
        getString("\nIngrese el nombre del empleado: ", nombre);
        strlwr(nombre);
        nombre[0] = toupper(nombre[0]);
        getString("\nIngrese el apellido del empleado: ", apellido);
        strlwr(apellido);
        apellido[0] = toupper(apellido[0]);
        getFloat("\nIngrese el salario del empleado: ", &salario);
        getInt("\nIngrese el sector del empleado: ", &sector);

        retorno = agregarEmpleado(arrayEmpleado, pos, nombre, apellido, salario, sector);

        if(retorno == 1)
        {
            puts("\nEl empleado fue agregado con exito.");
            retorno = 1;
        }
        else
        {
            puts("\nHubo un error al cargar el empleado.");
            arrayEmpleado[pos].isEmpty = VACIO;
            retorno = 0;
        }
    }
    else
    {
        puts("\nERROR: No hay posiciones libres para cargar un empleado.");
        retorno = 0;
    }

    return retorno;
}

int modificarEmpleado(eEmpleado arrayEmpleado[], int tam)
{
    int retorno;
    int len;
    int pos;
    int id;
    int confirmacion;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int flagCambio;

    flagCambio = 0;
    retorno = -1;

    len = empleados_len(arrayEmpleado, tam);

    if(len > 0)
    {
        getInt("\nIngrese el ID del empleado que quiere modificar: ", &id);
        pos = buscarEmpleadoPorID(arrayEmpleado, tam, id);

        id = arrayEmpleado[pos].id;
        strcpy(nombre, arrayEmpleado[pos].nombre);
        strcpy(apellido, arrayEmpleado[pos].apellido);
        salario = arrayEmpleado[pos].salario;
        sector = arrayEmpleado[pos].sector;

        if(pos != -1)
        {
            puts("\nEMPLEADO ENCONTRADO.");
            puts("\nID -------- NOMBRE -------- APELLIDO -------- SALARIO -------- SECTOR");
            mostrarUnEmpleado(arrayEmpleado, pos);
            getInt("\nDesea modificar el nombre del empleado?"
                   "\nIngrese '1' para si o cualquier otro numero para no: ", &confirmacion);
            if(confirmacion == 1)
            {
                getString("\n\nRe-ingrese el nombre del empleado: ", nombre);
                strlwr(nombre);
                nombre[0] = toupper(nombre[0]);
                flagCambio = 1;
            }
            getInt("\nDesea modificar el apellido del empleado?"
                   "\nIngrese '1' para si o cualquier otro numero para no: ", &confirmacion);
            if(confirmacion == 1)
            {
                getString("\nRe-ingrese el apellido del empleado: ", apellido);
                strlwr(apellido);
                apellido[0] = toupper(apellido[0]);
                flagCambio = 1;
            }
            getInt("\nDesea modificar el salario del empleado?"
                   "\nIngrese '1' para si o cualquier otro numero para no: ", &confirmacion);
            if(confirmacion == 1)
            {
                getFloat("\nRe-ingrese el salario del empleado: ", &salario);
                flagCambio = 1;
            }
            getInt("\nDesea modificar el sector del empleado?"
                   "\nIngrese '1' para si o cualquier otro numero para no: ", &confirmacion);
            if(confirmacion == 1)
            {
                getInt("\nRe-ingrese el sector del empleado: ", &sector);
                flagCambio = 1;
            }

            if(flagCambio == 1)
            {
                getInt("\nEsta seguro que desea modificar el empleado? ingrese 1 para 'si' o cualquier otro numero para 'no': ", &confirmacion);
                if(confirmacion == 1)
            {

                retorno = agregarModificacionesEmpleado(arrayEmpleado, pos, nombre, apellido, salario, sector);
                if(retorno == 1)
                {
                    puts("\nEl empleado fue modificado con exito.");
                    retorno = 1;
                }
                else
                {
                    puts("\nHubo un error al modificar el empleado.");
                    retorno = 0;
                }
            }
            else
            {
                puts("\nOperacion cancelada.");
                retorno = 0;
            }

            }
            else
            {
                puts("\nNo se ha realizado ninguna modificacion, el empleado se mantendra sin cambios.");
            }
        }
        else
        {
            puts("\nERROR: No se encontro ningun empleado con ese ID.");
            retorno = 0;
        }
    }
    else
    {
        puts("\nERROR: No hay empleados cargados para poder modificar.");
        retorno = 0;
    }

    return retorno;
}

int agregarEmpleado(eEmpleado arrayEmpleado[], int pos, char nombre[], char apellido[], float salario, int sector)
{
    int retorno;
    char idStr;
    int id;

    emp_cargarUltimoID("config.csv", &idStr);
    id = atoi(&idStr);
    id++;
    emp_guardarUltimoID("config.csv", id);

    arrayEmpleado[pos].id=id;
    strcpy(arrayEmpleado[pos].nombre, nombre);
    strcpy(arrayEmpleado[pos].apellido, apellido);
    arrayEmpleado[pos].salario=salario;
    arrayEmpleado[pos].sector=sector;
    arrayEmpleado[pos].isEmpty = OCUPADO;
    retorno = 1;

    return retorno;
}

int agregarModificacionesEmpleado(eEmpleado arrayEmpleado[], int pos, char nombre[], char apellido[], float salario, int sector)
{
    int retorno;

    strcpy(arrayEmpleado[pos].nombre, nombre);
    strcpy(arrayEmpleado[pos].apellido, apellido);
    arrayEmpleado[pos].salario=salario;
    arrayEmpleado[pos].sector=sector;
    arrayEmpleado[pos].isEmpty = OCUPADO;
    retorno = 1;

    return retorno;

}

int borrarEmpleado(eEmpleado arrayEmpleado[], int tam)
{
    int idLocal;
    int confirmacion;
    int pos;
    int retorno;
    int len;

    len = empleados_len(arrayEmpleado, tam);

    retorno = -1;

    if(len > 0)
    {
        getInt("\nIngrese el ID del empleado que desea borrar: ",&idLocal);

        pos = buscarEmpleadoPorID(arrayEmpleado, tam, idLocal);

        if(pos != -1)
        {
            puts("\nEmpleado encontrado: ");
            puts("\nID -------- NOMBRE -------- APELLIDO -------- SALARIO -------- SECTOR");
            mostrarUnEmpleado(arrayEmpleado, pos);
            getInt("\n\nEsta seguro que desea borrarlo? ingrese 1 para 'si' o cualquier otro numero para 'no': ", &confirmacion);
            if(confirmacion == 1)
            {
                arrayEmpleado[pos].isEmpty = VACIO;
                puts("\nEmpleado borrado con exito");
                retorno = 1;
            }
            else
            {
                puts("\nOperacion cancelada");
                retorno = 0;
            }
        }
        else
        {
            puts("\nERROR: No se encontro ningun empleado con ese ID.");
            retorno=0;
        }
    }
    else
    {
        puts("\nERROR: No hay empleados cargados para poder borrar.");
        retorno=0;
    }

    return retorno;
}

int buscarEmpleadoPorID(eEmpleado arrayEmpleado[], int tam, int id)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tam; i++)
    {
        if(arrayEmpleado[i].isEmpty == OCUPADO)
        {
            if(arrayEmpleado[i].id==id)
            {
                pos=i;
                break;
            }
        }
    }

    return pos;
}

int buscarLibre(eEmpleado arrayEmpleado[], int tam)
{
    int i;
    int pos;

    pos=-1;

    for(i=0; i<tam; i++)
    {
        if(arrayEmpleado[i].isEmpty == VACIO)
        {
            pos=i;
            break;
        }
    }

    return pos;
}

int empleados_len(eEmpleado arrayEmpleado[], int tam)
{
    int i;
    int contador;

    contador = 0;

    for(i=0; i<tam; i++)
    {
        if(arrayEmpleado[i].isEmpty == OCUPADO)
        {
            contador++;
        }
    }

    return contador;
}

int mostrarEmpleados(eEmpleado arrayEmpleado[], int tam)
{
    int i;
    int len;
    int retorno;

    retorno = -1;

    len = empleados_len(arrayEmpleado, tam);

    if(len > 0)
    {
        puts("\nMOSTRANDO EMPLEADOS");
        puts("\nID -------- NOMBRE -------- APELLIDO -------- SALARIO -------- SECTOR");
        for(i=0; i<tam; i++)
        {
            if(arrayEmpleado[i].isEmpty == OCUPADO)
            {
                mostrarUnEmpleado(arrayEmpleado, i);
                retorno = 1;
            }
        }
    }
    else
    {
        puts("\nERROR: No hay empleados cargados para mostrar.");
        retorno = 0;
    }

    return retorno;
}


void mostrarUnEmpleado(eEmpleado arrayEmpleado[], int pos)
{
    printf("\n%d %15s %17s %17.2f %15d", arrayEmpleado[pos].id,
                                         arrayEmpleado[pos].nombre,
                                         arrayEmpleado[pos].apellido,
                                         arrayEmpleado[pos].salario,
                                         arrayEmpleado[pos].sector);


}

int ordenarEmpleadosPorApellido(eEmpleado arrayEmpleado[], int tam, int orden)
{
    int i;
    int j;
    int retornoCmp;
    int retorno;
    eEmpleado aux;

    retorno = -1;

    if(orden == 1)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                retornoCmp = strcmp(arrayEmpleado[i].apellido, arrayEmpleado[j].apellido);
                if(retornoCmp == 1)
                {
                    aux = arrayEmpleado[i];
                    arrayEmpleado[i] = arrayEmpleado[j];
                    arrayEmpleado[j] = aux;
                    retorno = 1;
                }
            }
        }
    }
    else
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                retornoCmp = strcmp(arrayEmpleado[i].apellido, arrayEmpleado[j].apellido);
                if(retornoCmp == -1)
                {
                    aux = arrayEmpleado[j];
                    arrayEmpleado[j] = arrayEmpleado[i];
                    arrayEmpleado[i] = aux;
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}

int ordenarEmpleados(eEmpleado arrayEmpleado[], int tam)
{
    int orden;
    int opcion;
    int retorno;
    int len;

    retorno = -1;

    len = empleados_len(arrayEmpleado, tam);

    if(len > 0)
    {
        getInt("\nComo desea ordenar la lista de empleados?"
               "\n1. Por apellido."
               "\n2. Por sector."
               "\nIngrese la opcion que desea realizar: ", &opcion);

        while(opcion > 2 || opcion < 1)
        {
            getInt("\nERROR: Opcion incorrecta"
                   "\nIngrese nuevamente como desea ordenar la lista de empleados?"
                   "\n1. Por apellido."
                   "\n2. Por sector."
                   "\nIngrese la opcion que desea realizar: ", &opcion);
        }

        switch(opcion)
        {
        case 1:
            getInt("\nIngrese el criterio con el que desea ordenar la lista."
                   "\n'1' para ascendente o '0' para descendente: "
                   "\nIngrese la opcion que desea realizar: ", &orden);
            while(orden > 1 || orden < 0)
            {
                getInt("\nERROR: El numero ingresado no es correcto, intente nuevamente."
                       "\n'1' para ascendente o '0' para descendente: "
                       "\nIngrese la opcion que desea realizar: ", &orden);
            }
            ordenarEmpleadosPorApellido(arrayEmpleado, tam, orden);
            mostrarEmpleados(arrayEmpleado, tam);
            retorno = 1;
            break;
        case 2:
            getInt("\nIngrese el criterio con el que desea ordenar la lista."
                   "\n'1' para ascendente o '0' para descendente: "
                   "\nIngrese la opcion que desea realizar: ", &orden);
            while(orden > 1 || orden < 0)
            {
                getInt("\nERROR: El numero ingresado no es correcto, intente nuevamente."
                       "\n'1' para ascendente o '0' para descendente: "
                       "\nIngrese la opcion que desea realizar: ", &orden);
            }
            ordenarEmpleadosPorSector(arrayEmpleado, tam, orden);
            mostrarEmpleados(arrayEmpleado, tam);
            retorno = 1;
            break;
        }
    }
    else
    {
        puts("\nERROR: No hay empleados cargados para mostrar la lista ordenada.");
    }

    return retorno;
}

int ordenarEmpleadosPorSector(eEmpleado arrayEmpleado[], int tam, int orden)
{
  int i;
  int j;
  int retorno;
  eEmpleado aux;

  retorno = -1;
    if(orden == 1)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(arrayEmpleado[i].sector > arrayEmpleado[j].sector)
                {
                    aux = arrayEmpleado[i];
                    arrayEmpleado[i] = arrayEmpleado[j];
                    arrayEmpleado[j] = aux;
                    retorno = 1;
                }
            }
        }
    }
    else
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(arrayEmpleado[i].sector < arrayEmpleado[j].sector)
                {
                    aux = arrayEmpleado[j];
                    arrayEmpleado[j] = arrayEmpleado[i];
                    arrayEmpleado[i] = aux;
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}

int emp_guardarUltimoID(char* path, int id)
{
    FILE* pFile;
    int retorno=0;

    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
        fprintf(pFile,"%d", id);
        retorno=1;
    }

    fclose(pFile);

    return retorno;
}

int emp_cargarUltimoID (char* path, char* id)
{
    int retorno=0;
    FILE* pFile;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        fscanf(pFile, "%s", id);
        retorno=1;
    }

    fclose(pFile);

    return retorno;
}

void mostrarTotalYPromedioSalariosYEmpleadosSuperiorPromedio(eEmpleado arrayEmpleado[], int tam)
{
    int i;
    int contadorSalarios;
    float sumaSalarios;
    float promedioSalarios;
    int empleadosSuperiorPromedio;
    int len;

    contadorSalarios = 0;
    promedioSalarios = 0;
    sumaSalarios = 0;

    len = empleados_len(arrayEmpleado, tam);

    if(len > 0)
    {
        for(i=0; i<tam; i++)
        {
            if(arrayEmpleado[i].isEmpty == OCUPADO)
            {
                sumaSalarios = sumaSalarios + arrayEmpleado[i].salario;
                contadorSalarios++;
            }
        }

        promedioSalarios = sumaSalarios / contadorSalarios;

        empleadosSuperiorPromedio = empleadosSuperanSalarioPromedio(arrayEmpleado,  tam, promedioSalarios);

        puts("\nEmpleados cargados hasta el momento: ");
        mostrarEmpleados(arrayEmpleado, tam);

        printf("\nEl total de los salarios es: %.2f", sumaSalarios);
        printf("\nEl promedio de los salarios es: %.2f", promedioSalarios);
        printf("\nLa cantidad de empleados que superan el salario promedio es: %d", empleadosSuperiorPromedio);

    }
    else
    {
        puts("\nERROR: No hay empleados cargados para mostrar el promedio de salarios, total de salarios y la cantidad de empleados que lo superan.");
    }
}

int empleadosSuperanSalarioPromedio(eEmpleado arrayEmpleado[], int tam, float salarioPromedio)
{
    int i;
    int empleadosSuperiorPromedio;

    empleadosSuperiorPromedio = 0;

    for(i=0; i<tam; i++)
    {
        if(arrayEmpleado[i].isEmpty == OCUPADO)
        {
            if(arrayEmpleado[i].salario > salarioPromedio)
            {
                empleadosSuperiorPromedio++;
            }
        }
    }

    return empleadosSuperiorPromedio;
}
