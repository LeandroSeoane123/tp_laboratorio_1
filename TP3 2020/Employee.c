#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* pEmpleadoLocal;

    pEmpleadoLocal = (Employee*)malloc(sizeof(Employee));

    return pEmpleadoLocal;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleadoLocal=NULL;
    int id;
    int horasTrabajadas;
    int sueldo;
    int retornoId;
    int retornoNombre;
    int retornoHoras;
    int retornoSueldo;

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);
    if(atoi(idStr))
    {
        pEmpleadoLocal = employee_new();
        if(pEmpleadoLocal != NULL)
        {
            retornoId = employee_setId(pEmpleadoLocal, id);
            if(retornoId == 1)
            {
                retornoNombre = employee_setNombre(pEmpleadoLocal, nombreStr);
                if(retornoNombre == 1)
                {
                    retornoHoras = employee_setHorasTrabajadas(pEmpleadoLocal, horasTrabajadas);
                    if(retornoHoras == 1)
                    {
                        retornoSueldo = employee_setSueldo(pEmpleadoLocal, sueldo);
                    }
                }
            }
        }
    }

    if(retornoId != 1 || retornoNombre != 1 || retornoHoras != 1 || retornoSueldo != 1)
    {
        pEmpleadoLocal=NULL;
    }

    return pEmpleadoLocal;
}



int employee_setId(Employee* this,int id)
{
    int setteo = 0;
    if(this != NULL)
    {
        this->id = id;
        setteo = 1;
    }

    return setteo;
}

int employee_getId(Employee* this,int* id)
{
    int getteo = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        getteo = 1;
    }

    return getteo;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int setteo = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        setteo = 1;
    }

    return setteo;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int getteo = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        getteo = 1;
    }

    return getteo;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setteo = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        setteo = 1;
    }

    return setteo;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int setteo = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        setteo = 1;
    }

    return setteo;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int setteo = 0;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        setteo = 1;
    }

    return setteo;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int setteo = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        setteo = 1;
    }

    return setteo;
}

int employee_CompareByName(void* e1, void* e2)
{
    int retorno=0;
    char* nombre1;
    char* nombre2;

    nombre1=(char*)malloc(sizeof(char*)*128);
    nombre2=(char*)malloc(sizeof(char*)*128);

    Employee* auxE1 = (Employee*) e1;
    Employee* auxE2 = (Employee*) e2;

    employee_getNombre(auxE1,nombre1);
    employee_getNombre(auxE2,nombre2);

    if (strcmp(nombre1, nombre2)>0)
    {
        retorno = 1;
    }
    else
    {
        if(strcmp(nombre1, nombre2)<0)
        {
            retorno = -1;
        }
    }

    free(nombre1);
    free(nombre2);

    return retorno;
}


int employee_CompareById(void* e1, void* e2)
{
    int retorno=0;
    int* id1;
    int* id2;

    id1=(int*)malloc(sizeof(int*));
    id2=(int*)malloc(sizeof(int*));

    Employee* auxE1 = (Employee*) e1;
    Employee* auxE2 = (Employee*) e2;

    employee_getId(auxE1,id1);
    employee_getId(auxE2,id2);

    if (*id1 > *id2)
    {
        retorno = 1;
    }
    else
    {
        if(*id1 < *id2)
        {
            retorno = -1;
        }
    }

    free(id1);
    free(id2);

    return retorno;
}
