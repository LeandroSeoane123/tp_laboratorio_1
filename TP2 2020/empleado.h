
typedef struct
{

    char nombre[50];
    char apellido[50];
    int legajo;
    float sueldo;
    int sector;
    int isEmpty;

} eEmpleado;

void hardcodearEmpleados (eEmpleado arrayEmpleado[], int tam);
int buscarLibre (eEmpleado arrayEmpleado[], int tam);
int contadorDeEspaciosLibres (eEmpleado arrayEmpleado[], int tam);
void cargarEmpleado (eEmpleado arrayEmpleado[], int tam);
void modificarEmpleado (eEmpleado arrayEmpleado[], int tam);
void borrarEmpleado (eEmpleado arrayEmpleado[], int tam);
void ordenarPorNombre (eEmpleado arrayEmpleado[], int tam);
void ordenarPorSueldo (eEmpleado arrayEmpleado[], int tam);
int SacarPromedioSueldos (eEmpleado arrayEmpleado[], int tam, int totalSueldos);
int sumarSueldos (eEmpleado arrayEmpleado[], int tam);
int contarEmpleadosQueSuperenSalarioPromedio (eEmpleado arrayEmpleado[], int tam, float promedio);
void listarEmpleados (eEmpleado arrayEmpleado[], int tam, int sumaSueldos, float promedioSueldos, int contadorEmpleadosArribaDelPromedio);
