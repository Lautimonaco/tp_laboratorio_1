#define MAX 1000

typedef struct
{
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;


/** \ brief Para indicar que todas las posiciones en la matriz están vacías,
* esta función pone la bandera (isEmpty) en TRUE en todos
* posición de la matriz
* \ param list Employee * Puntero a la matriz de empleados
* \ param len int Array length
* \ return int Return (-1) if Error [Longitud inválida o puntero NULL] - (0) si Ok
* *
*/
int initEmployees(Employee*, int);


/** \ brief Inicia el programa con los dats ya cargados.
 * *
 * \ param Employee * Apunta a la estructura de los empleados.
 * \ param
 * \ return
 * *
 */
void addEmployees (Employee* listaEmployee, int);


/** \ brief Obtiene el primer índice libre de la matriz.
 * *
 * \ param Employee * Apunta a la estructura de los empleados.
 * \ param int limit.
 * \ return -1 si no hay espacio
 * *
 */
int buscarEspacio (Employee*, int);


/** \ brief Muestra solo un empleado.
 * *
 * \ param Empleado Estructura de empleado único
 * \ return void
 * *
 */
void printOneEmployee (Employee);


/** \ brief Inicializa la estructura del empleado
 * *
 * \ param list Employee * Apunta a la estructura de los empleados.
 * \ param int limit.
 * \return void
 *
 */
void inicializarEmployeesConDatos (Employee*, int);


/** \ breve ID incremental
 * *
 * \ param Employee * Apunta a la estructura de los empleados.
 * \ param int limit
 * \ return int Devuelve el id incrementado en 1 si se pudo y 0 si no.
 * *
 */
int idAutoIncremental(Employee*, int);


/** \ breves empleados modificados
 * *
 * \ param Employee * Apunta a la estructura de los empleados
 * \ param int limit
 * \ return int 0 si se ingresó -1 Si no hay espacio
 * *
 */
int addEmployeesModificado(Employee*, int);


/** \ breve imprime el contenido de la matriz de empleados
 * *
 * \ param list Employee * Puntero que apunta a la estructura de empleados
 * \ longitud del parámetro int limite del puntero
 * \return int
 *
 */
int printEmployees(Employee* list, int length);


/** \ brief find a Employee by Id en devuelve la posición del índice en la matriz.
 * *
 * \ param list Employee *
 * \ param len int
 * \ param id int
 * \ return Devuelve la posición del índice del empleado o (-1)
 * *
 */
int findEmployeeById(Employee*, int, int);


/** \ brief Eliminar un empleado por Id (poner isEmpty Flag en 1)
 * *
 * \ param list Employee *
 * \ param len int
 * \ param id int
 * \ return int Return (-1)
 * *
 */
int removeEmployee(Employee*, int, int);


/** \ brief Función que permite modificar un empleado
 * *
 * \ param
 * \ límite de param
 * \ return int mayor que 0 si podría modificarse y -1 si la modificación fue cancelada
 * *
 */
int modificacionDeEmpleado(Employee*, int);


/** \ brief Función que permite mostrar el menú de datos que desea modificar
 * *
 * \ param * Puntero para modificar datos
 * \ límite de param
 * \ return int mayor que 0 si podría modificarse y -1 si la modificación fue cancelada
 * *
 */
int menuModificacion(Employee*, int);



/** \ brief Ordena los elementos en la matriz de empleados
 * *
 * \ param list Employee *
 * \ param len int
 * \ param order int (1) indica UP - (0) indica DOWN
 * \ return int Return (-1)
 * *
 */
int sortEmployees(Employee* list, int len, int order);
