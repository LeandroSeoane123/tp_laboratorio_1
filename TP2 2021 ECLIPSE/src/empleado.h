
typedef struct{

  int id;
  char nombre[51];
  char apellido[51];
  float salario;
  int sector;
  int isEmpty;

}eEmpleado;

int hardcodearEmpleados(eEmpleado arrayEmpleado[], int tam);
int cargarEmpleado(eEmpleado arrayEmpleado[], int tam);
int modificarEmpleado(eEmpleado arrayEmpleado[], int tam);
int agregarEmpleado(eEmpleado arrayEmpleado[], int pos, char nombre[], char apellido[], float salario, int sector);
int agregarModificacionesEmpleado(eEmpleado arrayEmpleado[], int pos, char nombre[], char apellido[], float salario, int sector);
int borrarEmpleado(eEmpleado arrayEmpleado[], int tam);
int emp_guardarUltimoID(char* path, int id);
int emp_cargarUltimoID (char* path, char* id);
int buscarEmpleadoPorID(eEmpleado arrayEmpleado[], int tam, int id);
int buscarLibre(eEmpleado arrayEmpleado[], int tam);
int empleados_len(eEmpleado arrayEmpleado[], int tam);
int ordenarEmpleados(eEmpleado arrayEmpleado[], int tam);
int ordenarEmpleadosPorApellido(eEmpleado arrayEmpleado[], int tam, int orden);
int ordenarEmpleadosPorSector(eEmpleado arrayEmpleado[], int tam, int orden);
int mostrarEmpleados(eEmpleado arrayEmpleado[], int tam);
void mostrarUnEmpleado(eEmpleado arrayEmpleado[], int pos);
void mostrarTotalYPromedioSalariosYEmpleadosSuperiorPromedio(eEmpleado arrayEmpleado[], int tam);
int empleadosSuperanSalarioPromedio(eEmpleado arrayEmpleado[], int tam, float salarioPromedio);
