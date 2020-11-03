#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retornoParser;
    int validar = 0;
    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        if(ll_isEmpty(pArrayListEmployee)==1)
        {
            validar = 1;
        }
        else
        {
            printf("\nADVERTENCIA: La lista esta ocupada, si desea cargar los datos de 'data.csv',"
                   "se perderan los datos actuales a menos que los haya guardado antes.");
            printf("\nDesea continuar? Ingrese 1 para si o 0 para no: ");
            scanf("%d", &validar);
            while(validar != 1 && validar != 0)
            {
                printf("\nLa opcion ingresada no es correcta, en esta linea solo se puede ingresar 1 o 0 (si o no).");
                scanf("%d", &validar);
            }
        }
        if(validar==1)
        {
            ll_clear(pArrayListEmployee);
            retornoParser = parser_EmployeeFromText(pFile, pArrayListEmployee);
            if(retornoParser == 1)
            {
                printf("\nDATOS CARGADOS EXITOSAMENTE.\n");
            }

        }
        else
        {
            printf("\nOPERACION CANCELADA POR EL USUARIO.\n");
        }

        fclose(pFile);
    }
    else
    {
        printf("\nNo se encontro el archivo 'data.csv'.\n");
        retornoParser = -1;
    }

    return retornoParser;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retornoParser;
    int validar = 0;
    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        if(ll_isEmpty(pArrayListEmployee)==1)
        {
            validar = 1;
        }
        else
        {
            printf("\nADVERTENCIA: La lista esta ocupada, si desea cargar los datos de 'data.bin', se perderan los datos actuales a menos que los haya guardado antes.");
            printf("\nDesea continuar? Ingrese 1 para si o 0 para no: ");
            scanf("%d", &validar);
            while(validar != 1 && validar != 0)
            {
                printf("\nLa opcion ingresada no es correcta, en esta linea solo se puede ingresar 1 o 0 (si o no).");
                scanf("%d", &validar);
            }
        }
        if(validar==1)
        {
            ll_clear(pArrayListEmployee);
            retornoParser = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
            if(retornoParser == 1)
            {
                printf("\nDATOS CARGADOS EXITOSAMENTE.\n");
            }

        }
        else
        {
            printf("\nOPERACION CANCELADA POR EL USUARIO.\n");
        }

        fclose(pFile);
    }
    else
    {
        printf("\nNo se encontro el archivo 'data.bin'.\n");
        retornoParser = -1;
    }

    return retornoParser;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int retorno = 0;
    int id;
    char* idStr=NULL;
    char* pNombreStr=NULL;
    char* pHorasTrabajadasStr=NULL;
    char* pSueldoStr=NULL;
    int retornoAddList;

    FILE* pFile;

    pFile = fopen("data.csv", "r");

    idStr = (char*)malloc(sizeof(char*)*20);
    pNombreStr = (char*)malloc(sizeof(char*)*128);
    pHorasTrabajadasStr = (char*)malloc(sizeof(char*)*20);
    pSueldoStr = (char*)malloc(sizeof(char*)*20);

    if(pFile != NULL)
    {
        parser_LastIdFromText(pFile, pArrayListEmployee, idStr);
    }

    id = atoi(idStr);
    id = id+1;
    sprintf(idStr,"%d",id);

    printf("\nIngrese el nombre del empleado: ");
    fflush(stdin);
    gets(pNombreStr);

    printf("\nIngrese las horas trabajadas del empleado: ");
    fflush(stdin);
    gets(pHorasTrabajadasStr);

    printf("\nIngrese el sueldo del empleado: ");
    fflush(stdin);
    gets(pSueldoStr);

    pEmpleado = employee_newParametros(idStr, pNombreStr, pHorasTrabajadasStr, pSueldoStr);

    if(pEmpleado != NULL)
    {
        retornoAddList = ll_add(pArrayListEmployee, pEmpleado);
        if(retornoAddList == 0)
        {
            printf("\n***** EL EMPLEADO FUE AGREGADO A LA LISTA SATISFACTORIAMENTE *****\n");
            retorno = 1;
        }
    }
    else
    {
        printf("\nERROR: No se pudo agregar el empleado a la lista.\n");
        retorno = -1;
    }

    free(idStr);
    free(pNombreStr);
    free(pHorasTrabajadasStr);
    free(pSueldoStr);

    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int len;
    int i;
    int* id;
    char* nombre;
    int* horas;
    int* sueldo;
    Employee* auxE;

    id=(int*)malloc(sizeof(int*));
    nombre=(char*)malloc(sizeof(char*)*128);
    horas=(int*)malloc(sizeof(int*));
    sueldo=(int*)malloc(sizeof(int*));

    len = ll_len(pArrayListEmployee);

    if(len == 0)
    {
        printf("\nERROR: No hay empleados cargados para mostrar.\n");
    }
    else
    {
        printf("\n********** LISTA DE EMPLEADOS **********\n"
               "-----ID-----NOMBRE-----HORAS-----SUELDO-----\n");
        for(i=0; i < len; i++)
        {
            auxE = ll_get(pArrayListEmployee, i);
            employee_getId(auxE, id);
            employee_getNombre(auxE, nombre);
            employee_getHorasTrabajadas(auxE, horas);
            employee_getSueldo(auxE, sueldo);
            printf("\n%7d %10s %9d %10d\n", *id, nombre, *horas, *sueldo);
            retorno = 1;
        }
    }

    free(id);
    free(nombre);
    free(horas);
    free(sueldo);

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int* id;
    int idAux;
    int i;
    int len;
    char nombreAux[30];
    int horasTrabajadasAux;
    int sueldoAux;
    int retornoNombre;
    int retornoHoras;
    int retornoSueldo;
    Employee* auxE;

    id=(int*)malloc(sizeof(int*));

    len = ll_len(pArrayListEmployee);

    if(len > 0)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("\nIngrese el id de empleado que quiere modificar: ");
        scanf("%d", &idAux);
        for(i=0; i<len; i++)
        {
            auxE = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(auxE, id);
            if(auxE != NULL && *id == idAux)
            {
                printf("\nEmpleado encontrado.\n");
                printf("\nIngrese el nombre de su nuevo empleado: ");
                scanf("%s", nombreAux);
                retornoNombre = employee_setNombre(auxE, nombreAux);
                if(retornoNombre == 1)
                {
                    printf("\nIngrese las horas trabajadas de su nuevo empleado: ");
                    scanf("%d", &horasTrabajadasAux);
                    retornoHoras = employee_setHorasTrabajadas(auxE, horasTrabajadasAux);
                    if(retornoHoras == 1)
                    {
                        printf("\nIngrese el sueldo de su nuevo empleado: ");
                        scanf("%d", &sueldoAux);
                        retornoSueldo = employee_setSueldo(auxE, sueldoAux);
                        if(retornoSueldo == 1)
                        {
                            printf("\n***** EMPLEADO MODIFICADO CON EXITO *****\n");
                            retorno = 1;
                        }
                    }
                }
            }
            else
            {
                auxE = NULL;
            }
        }
    }
    else
    {
        printf("\nERROR: No hay empleados cargados para modificar.\n");
    }

    if(retornoNombre != 1 || retornoHoras != 1 || retornoSueldo != 1)
    {
        printf("\nERROR: Hubo un problema al modificar el empleado.\n");
    }

    if(auxE == NULL)
    {
        printf("\nERROR: El empleado no fue encontrado.\n");
        retorno = -1;
    }

    free(id);

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int idAux;
    int* id;
    int i;
    int len;
    Employee* auxE;

    id=(int*)malloc(sizeof(int*));

    len = ll_len(pArrayListEmployee);

    if(len == 0)
    {
        printf("\nERROR: No hay empleados cargados para borrar.\n");
    }
    else
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("\nIngrese el id del empleado que desea borrar: ");
        scanf("%d", &idAux);
        for(i=0; i<len; i++)
        {
            auxE = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(auxE, id);
            if(*id == idAux)
            {
                ll_pop(pArrayListEmployee, i);
                len = ll_len(pArrayListEmployee);
                printf("\n***** EMPLEADO BORRADO CON EXITO *****\n");
                retorno = 1;
                break;
            }
            else
            {
                auxE = NULL;
            }
        }

        if(auxE == NULL)
        {
            printf("\nERROR: El empleado no fue encontrado.\n");
            retorno = -1;
        }
    }

    free(id);

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int retornoSort;
    int opcionMenu;
    int opcionMenu2;

    printf("\nDefina el criterio con el que quiere ordenar, 1 para ordenar por ID y 2 para ordenar por nombre: ");
    scanf("%d",&opcionMenu);
    while(opcionMenu != 1 && opcionMenu != 2)
    {
        printf("\nERROR: La opcion ingresada no es correcta, ingrese 1 para ordenar por ID y 2 para ordenar por nombre: ");
        scanf("%d",&opcionMenu);
    }

    switch(opcionMenu)
    {
    case 1:
        printf("\nIngrese 1 para ordenar ascendentemente y 2 para ordenar descendentemente: ");
        scanf("%d",&opcionMenu2);
        while(opcionMenu2 != 1 && opcionMenu2 != 2)
        {
            printf("\nERROR: La opcion ingresada no es correcta, ingrese 1 para ordenar ascendentemente y 2 para ordenar descendentemente: ");
            scanf("%d",&opcionMenu2);
        }
        switch(opcionMenu2)
        {
        case 1:
            printf("\nSe esta ordenando la lista, esto puede tardar unos minutos...\n");
            retornoSort = ll_sort(pArrayListEmployee, employee_CompareById, 1);
            if(retornoSort == 0)
            {
               printf("\n***** LISTA ORDENADA SATISFACTORIAMENTE *****\n");
               retorno = 1;
            }
            else
            {
                printf("\nERROR: No se pudo ordenar la lista.\n");
                retorno = -1;
            }
            break;
        case 2:
            printf("\nSe esta ordenando la lista, esto puede tardar unos minutos...\n");
            retornoSort = ll_sort(pArrayListEmployee, employee_CompareById, 0);
            if(retornoSort == 0)
            {
               printf("\n***** LISTA ORDENADA SATISFACTORIAMENTE *****\n");
               retorno = 1;
            }
            else
            {
                printf("\nERROR: No se pudo ordenar la lista.\n");
                retorno = -1;
            }
            break;
        }
        break;

    case 2:
        printf("\nSe esta ordenando la lista, esto puede tardar unos minutos...\n");
        retornoSort = ll_sort(pArrayListEmployee, employee_CompareByName, 1);
        if(retornoSort == 0)
            {
               printf("\n***** LISTA ORDENADA SATISFACTORIAMENTE *****\n");
               retorno = 1;
            }
            else
            {
                printf("\nERROR: No se pudo ordenar la lista.\n");
                retorno = -1;
            }
        break;
    }
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=0;
    int len;
    int i;
    int* id;
    char* nombre;
    int* horas;
    int* sueldo;
    Employee* pEmpleado;

    id=(int*)malloc(sizeof(int*));
    nombre=(char*)malloc(sizeof(char*)*128);
    horas=(int*)malloc(sizeof(int*));
    sueldo=(int*)malloc(sizeof(int*));

    pFile = fopen(path, "w");

    len = ll_len(pArrayListEmployee);

    if(len > 0)
    {
        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                pEmpleado = ll_get(pArrayListEmployee, i);
                employee_getId(pEmpleado, id);
                employee_getNombre(pEmpleado, nombre);
                employee_getHorasTrabajadas(pEmpleado, horas);
                employee_getSueldo(pEmpleado, sueldo);
                fprintf(pFile, "%d,%s,%d,%d\n", *id, nombre, *horas, *sueldo);
                retorno = 1;
            }
            printf("\n***** DATOS GUARDADOS CORRECTAMENTE. *****\n");
        }
        else
        {
            printf("\nERROR: No se pudo crear el archivo.\n");
        }

    }
    else
    {
        printf("\nERROR: No hay empleados cargados para guardar en el archivo de texto.\n");
    }

    fclose(pFile);

    free(id);
    free(nombre);
    free(horas);
    free(sueldo);

    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=0;
    int len;
    int i;
    Employee* pEmpleado;

    pFile = fopen(path, "wb");

    len = ll_len(pArrayListEmployee);

    if(len > 0)
    {
        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                pEmpleado = ll_get(pArrayListEmployee, i);
                fwrite(pEmpleado, sizeof(Employee), 1, pFile);
                retorno = 1;
            }
            printf("\n***** DATOS GUARDADOS CORRECTAMENTE. *****\n");
        }
        else
        {
            printf("\nERROR: No se pudo crear el archivo.\n");
        }

    }
    else
    {
        printf("\nERROR: No hay empleados cargados para guardar en el archivo binario.\n");
    }

    fclose(pFile);

    return retorno;
}

