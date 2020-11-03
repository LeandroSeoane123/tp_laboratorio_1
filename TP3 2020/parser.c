#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* pEmpleadoLocal;
    char* id=NULL;
    char* nombre=NULL;
    char* horas=NULL;
    char* sueldo=NULL;

    id = (char*)malloc(sizeof(char*)*20);
    nombre = (char*)malloc(sizeof(char*)*128);
    horas = (char*)malloc(sizeof(char*)*20);
    sueldo = (char*)malloc(sizeof(char*)*20);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
        pEmpleadoLocal=employee_newParametros(id, nombre, horas, sueldo);
        if(pEmpleadoLocal != NULL)
        {
            ll_add(pArrayListEmployee, pEmpleadoLocal);
        }
    }

    fclose(pFile);

    printf("\n***** DATOS IMPORTADOS CORRECTAMENTE. *****\n");

    free(id);
    free(nombre);
    free(horas);
    free(sueldo);

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
            }
        }
    }

    printf("\n***** DATOS IMPORTADOS CORRECTAMENTE. *****\n");

    fclose(pFile);

    return retorno;
}
