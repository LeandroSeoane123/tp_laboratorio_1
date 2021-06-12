#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* pEmpleadoLocal;
    char id[20];
    char nombre[128];
    char horas[20];
    char sueldo[20];

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
        pEmpleadoLocal=employee_newParametros(id, nombre, horas, sueldo);
        if(pEmpleadoLocal != NULL)
        {
            ll_add(pArrayListEmployee, pEmpleadoLocal);
            retorno = 1;
        }
    }

    fclose(pFile);

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* pEmpleadoLocal;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            pEmpleadoLocal = employee_new();
            fread(pEmpleadoLocal, sizeof(Employee), 1, pFile);
            if(feof(pFile))
            {
                break;
            }
            if(pEmpleadoLocal != NULL)
            {
                ll_add(pArrayListEmployee, pEmpleadoLocal);
                retorno=1;
            }
        }
    }

    fclose(pFile);

    return retorno;
}

int parser_LoadLastIdFromText (char* path, char* id)
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
