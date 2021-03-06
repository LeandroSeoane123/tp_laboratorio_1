#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Seoane.h"

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
            getInt("\nADVERTENCIA: La lista esta ocupada, si desea cargar los datos de 'data.csv',"
                    "se perderan los datos actuales a menos que los haya guardado antes."
                    "\nDesea continuar? Ingrese 1 para si o 0 para no: ", &validar);
            while(validar != 1 && validar != 0)
            {
                getInt("\nLa opcion ingresada no es correcta, en esta linea solo se puede ingresar 1 o 0 (si o no).", &validar);
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
            retornoParser = -1;
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
            getInt("\nADVERTENCIA: La lista esta ocupada, si desea cargar los datos de 'data.bin',"
            	   "se perderan los datos actuales a menos que los haya guardado antes."
                   "\nDesea continuar? Ingrese 1 para si o 0 para no: ", &validar);
            while(validar != 1 && validar != 0)
            {
                getInt("\nLa opcion ingresada no es correcta, en esta linea solo se puede ingresar 1 o 0 (si o no).", &validar);
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
            retornoParser = -1;
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

int controller_saveLastIdAsText(char* path, int id)
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


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int retorno = 0;
    int id;
    char idStr[20];
    char NombreStr[128];
    char HorasTrabajadasStr[20];
    char SueldoStr[20];
    int retornoAddList;

    parser_LoadLastIdFromText("config.csv",idStr);

    id = atoi(idStr);
    id = id+1;
    sprintf(idStr,"%d",id);

    getString("\nIngrese el nombre del empleado: ", NombreStr);
    strlwr(NombreStr);
    NombreStr[0] = toupper(NombreStr[0]);
    getString("\nIngrese las horas trabajadas del empleado: ", HorasTrabajadasStr);
    getString("\nIngrese el sueldo del empleado: ", SueldoStr);

    pEmpleado = employee_newParametros(idStr, NombreStr, HorasTrabajadasStr, SueldoStr);

    if(pEmpleado != NULL)
    {
        retornoAddList = ll_add(pArrayListEmployee, pEmpleado);
        if(retornoAddList == 0)
        {
            printf("\n***** EL EMPLEADO FUE AGREGADO A LA LISTA SATISFACTORIAMENTE *****\n");
            controller_saveLastIdAsText("config.csv", id);
            retorno = 1;
        }
    }
    else
    {
        printf("\nERROR: No se pudo agregar el empleado a la lista.\n");
        retorno = -1;
    }

    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int len;
    int i;
    Employee* auxE;

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
            mostrarEmpleado(auxE);
            retorno = 1;
        }
    }
    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    int idAux;
    int i;
    int len;
    char nombreAux[128];
    int horasTrabajadasAux;
    int sueldoAux;
    int retornoNombre;
    int retornoHoras;
    int retornoSueldo;
    Employee* auxE;

    len = ll_len(pArrayListEmployee);

    if(len > 0)
    {
        controller_ListEmployee(pArrayListEmployee);
        getInt("\nIngrese el id de empleado que quiere modificar: ", &idAux);
        for(i=0; i<len; i++)
        {
            auxE = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(auxE, &id);
            if(auxE != NULL && id == idAux)
            {
                printf("\nEmpleado encontrado.\n");
                getString("\nIngrese el nombre de su nuevo empleado: ", nombreAux);
                strlwr(nombreAux);
                nombreAux[0] = toupper(nombreAux[0]);
                retornoNombre = employee_setNombre(auxE, nombreAux);
                if(retornoNombre == 1)
                {
                    getInt("\nIngrese las horas trabajadas de su nuevo empleado: ", &horasTrabajadasAux);
                    retornoHoras = employee_setHorasTrabajadas(auxE, horasTrabajadasAux);
                    if(retornoHoras == 1)
                    {
                        getInt("\nIngrese el sueldo de su nuevo empleado: ", &sueldoAux);
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

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int idAux;
    int id;
    int i;
    int len;
    Employee* auxE;

    len = ll_len(pArrayListEmployee);

    if(len == 0)
    {
        printf("\nERROR: No hay empleados cargados para borrar.\n");
    }
    else
    {
        controller_ListEmployee(pArrayListEmployee);
        getInt("\nIngrese el id del empleado que desea borrar: ", &idAux);
        for(i=0; i<len; i++)
        {
            auxE = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(auxE, &id);
            if(id == idAux)
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

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int retornoSort;
    int opcionMenu;
    int opcionMenu2;
    int len;

    len = ll_len(pArrayListEmployee);


    if(len>1)
    {
    	getInt("\nDefina el criterio con el que quiere ordenar, 1 para ordenar por ID y 2 para ordenar por nombre: ", &opcionMenu);
    	    while(opcionMenu != 1 && opcionMenu != 2)
    	    {
    	        getInt("\nERROR: La opcion ingresada no es correcta, ingrese 1 para ordenar por ID y 2 para ordenar por nombre: ", &opcionMenu);
    	    }

    	    switch(opcionMenu)
    	    {
    	    case 1:
    	        getInt("\nIngrese 1 para ordenar ascendentemente y 2 para ordenar descendentemente: ", &opcionMenu2);
    	        while(opcionMenu2 != 1 && opcionMenu2 != 2)
    	        {
    	            getInt("\nERROR: La opcion ingresada no es correcta, ingrese 1 para ordenar ascendentemente y 2 para ordenar descendentemente: ", &opcionMenu2);
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
    	    	getInt("\nIngrese 1 para ordenar ascendentemente y 2 para ordenar descendentemente: ", &opcionMenu2);
    	    	 while(opcionMenu2 != 1 && opcionMenu2 != 2)
    	    	 {
    	    	   getInt("\nERROR: La opcion ingresada no es correcta, ingrese 1 para ordenar ascendentemente y 2 para ordenar descendentemente: ", &opcionMenu2);
    	    	  }
    	    	switch(opcionMenu2)
    	    	{
    	    	  case 1:
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
    	    	  case 2:
    	    		  printf("\nSe esta ordenando la lista, esto puede tardar unos minutos...\n");
    	    		  retornoSort = ll_sort(pArrayListEmployee, employee_CompareByName, 0);
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
    	    }
    }
    else
    {
    	printf("\nERROR: No hay suficientes empleados cargados para ordenar."
    			"\nDebe haber como minimo dos empleados para poder ordenar.");
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=0;
    int len;
    int i;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* pEmpleado;

    pFile = fopen(path, "a");

    len = ll_len(pArrayListEmployee);

    if(len > 0)
    {
        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                pEmpleado = ll_get(pArrayListEmployee, i);
                employee_getId(pEmpleado, &id);
                employee_getNombre(pEmpleado, nombre);
                employee_getHorasTrabajadas(pEmpleado, &horas);
                employee_getSueldo(pEmpleado, &sueldo);
                fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
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

    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=0;
    int len;
    int i;
    Employee* pEmpleado;

    pFile = fopen(path, "ab");

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
