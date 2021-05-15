#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "FuncionesGet.h"

#define MAX 1000

int initEmployees(Employee* list, int len)
{
    int estado;
    int i;
    if (list != NULL)
    {
        for (i=0; i<len; i++)
        {
            list[i].isEmpty = 0;
        }
        estado = 0;
    }
    else
    {
        estado = -1;
    }

    return estado;
}

void addEmployees (Employee* listaEmployee, int tam)
{
    int id[7] = {1,2,3,4,5,6,7};
    char name[7][50] = {"Fernando", "Juan", "Mirta", "Felipe","Agustin", "Rodrigo", "Lucas"};
    char lastname[7][50] = {"Fernandez","Fox","White","Andina","Ted", "Rex", "Lopez"};
    float salary[7] = {1800, 9000, 8700, 4500,6700, 8900, 5550};
    int sector[7] = {6,9,4,10,5,8,2};

    int i;
    for (i=0; i<7; i++)
    {
        listaEmployee[i].id = id[i];
        strcpy (listaEmployee[i].name, name[i]);
        strcpy (listaEmployee[i].lastname, lastname[i]);
        listaEmployee[i].salary = salary[i];
        listaEmployee[i].sector = sector[i];
        listaEmployee[i].isEmpty = 1; //  Estado ocupado
    }
}

int findEmployeeById(Employee* list, int len, int id)
{

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1 && list[i].id==id)
        {
            return i;
        }
    }

    return -1;
}

int removeEmployee(Employee* list, int len, int id)
{
    int i;

    char auxiliarID[50];
    int scanID;

    int opcion;

    int estado = -1; // No se encontro ID

    printEmployees(list, len);


    printf("Ingrese la ID del empleado a dar de baja ");
    fflush(stdin);
    gets(auxiliarID);
    while(esNumerico(auxiliarID)==0)
    {
        printf("Error, ID incorrecto, ingrese nuevamente el id ");
        fflush(stdin);
        gets(auxiliarID);
    }
    scanID=atoi(auxiliarID);


    for(i=0; i<len; i++)
    {
        if(scanID==list[i].id)
        {
            printf("\nRealmente desea dar de baja el empleado? SI(1) -------- NO(2)\n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                list[i].isEmpty = 0;
                list[i].id= 0;
                estado = 0; //Se dio de baja el empleado
                break;

            case 2:
                estado = -2; //Se cancelo la baja.
                break;

            default:
                printf("\nError, Ingrese una opcion valida\n");
                estado = -2;
                break;
            }
        }

    }

    return estado;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee auxiliarEmpleado;
    int i;
    int j;

    char auxiliarOpcion[50];
    int opcion;

    printf("\n\nComo quiere ordenar la lista? 1 -- Por apellido: / 2 -- Por sector: \n");
    fflush(stdin);
    gets(auxiliarOpcion);

    while(esNumerico(auxiliarOpcion)==0)
    {
        printf("Error, Ingrese nuevamente la opcion: ");
        fflush(stdin);
        gets(auxiliarOpcion);
    }
    opcion=atoi(auxiliarOpcion);

    switch(opcion)
    {
    case 1:
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastname,list[j].lastname)>order)
                {
                    auxiliarEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxiliarEmpleado;
                }
            }
        }
        break;

    case 2:
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[i].sector > list[j].sector)
                {
                    auxiliarEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxiliarEmpleado;
                }
            }
        }
        break;
    }
    return i;
}

int printEmployees(Employee* list, int length)
{
    int i;
    printf("\n\nID \t NOMBRE: \t APELLIDO: \t SALARIO: \t SECTOR:\n\n");
    for(i=0; i<length; i++)
    {
        if (list[i].isEmpty == 1)
        {
            printOneEmployee(list[i]);
        }

    }
    return i;
}


/*--------------------FUNCIONES PROPIAS----------------------*/


int buscarEspacio (Employee* listaEmployee, int cant)
{
    int indice = -1;
    int i;

    for (i=0; i<cant; i++)
    {
        if (listaEmployee[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void printOneEmployee (Employee listaEmployee)
{
    printf("%d || %10s %15s %20f %10d\n\n", listaEmployee.id, listaEmployee.name, listaEmployee.lastname, listaEmployee.salary, listaEmployee.sector);
}

int idAutoIncremental(Employee* listaEmployee, int len)
{
    int retorno = 0;
    int i;
    if(len > 0 && listaEmployee != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(listaEmployee[i].isEmpty == 1)
            {
                if(listaEmployee[i].id > retorno)
                {
                    retorno = listaEmployee[i].id;
                }
            }
        }
    }
    return retorno+1;
}

int addEmployeesModificado(Employee* listaEmployee,int tam)
{
    int retorno = -1;
    int i;

    char auxiliarsalary[50];
    float salary;

    char auxiliarSector[50];
    int sector;

    int id;

    i = buscarEspacio(listaEmployee, tam);
    id = idAutoIncremental(listaEmployee, tam);

    if(i>=0)
    {
        printf("Ingrese el nombre del empleado:");
        fflush(stdin);
        gets(listaEmployee[i].name);
        while(esSoloLetras(listaEmployee[i].name)==0)
        {
            printf("Error, ingrese un tipo de nombre correcto: ");
            fflush(stdin);
            gets(listaEmployee[i].name);
        }

        printf("Ingrese el apellido del empleado:");
        fflush(stdin);
        gets(listaEmployee[i].lastname);

        while(esSoloLetras(listaEmployee[i].lastname)==0)
        {
            printf("Usted ha ingresado un tipo de apellido incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(listaEmployee[i].lastname);
        }

        printf("Ingrese el salario del empleado: ");
        fflush(stdin);
        gets(auxiliarsalary);

        while(esNumerico(auxiliarsalary)==0)
        {
            printf("Usted ha ingresado un tipo de salario incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(auxiliarsalary);
        }
        salary=atoi(auxiliarsalary);
        listaEmployee[i].salary=salary;




        printf("Ingrese el sector del empleado: ");
        fflush(stdin);
        gets(auxiliarSector);

        while(esNumerico(auxiliarSector)==0)
        {
            printf("Error, Ingrese un sector correcto: ");
            fflush(stdin);
            gets(auxiliarSector);
        }
        sector=atoi(auxiliarSector);
        listaEmployee[i].sector=sector;


        listaEmployee[i].isEmpty=1;

        listaEmployee[i].id=id;

        retorno=0;
    }
    return retorno;
}

int modificacionDeEmpleado(Employee* listaEmployee, int len)
{
    int id;
    int indice;
    int rt;

    int retorno=-2;

    char auxiliarID[20];

    if(len > 0 && listaEmployee != NULL)
    {
        retorno=-1;

        printEmployees(listaEmployee, len);

        printf("Ingrese el ID del empleado: ");
        fflush(stdin);
        gets(auxiliarID);
        while(esNumerico(auxiliarID)==0)
        {
            printf("Error, ID incorrecta, ingrese nuevamente ");
            fflush(stdin);
            gets(auxiliarID);
        }
        id=atoi(auxiliarID);



        indice=findEmployeeById(listaEmployee, len, id);


        if(indice>=0)
        {
            rt=menuModificacion(listaEmployee,indice);
            retorno=rt;
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}

int menuModificacion(Employee* listaEmployee, int indice)
{
    char auxiliarOpcion[30];
    char auxiliarNombre[30];
    char auxiliarApellido[30];
    char auxiliarsalary[30];
    char auxiliarSector[30];
    float salary;
    int sector;
    int opcion;


    int retorno=-1;


    printf("\nQue desea modificar:\n1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    gets(auxiliarOpcion);


    while(esNumerico(auxiliarOpcion)==0)
    {
        printf("Error, Ingrese nuevamente la opcion ");
        fflush(stdin);
        gets(auxiliarOpcion);
    }
    opcion=atoi(auxiliarOpcion);  //Convierte la cadena a su valor numerico



    if(opcion>=1&&opcion<=6)
    {
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre del empleado:");
            fflush(stdin);
            gets(auxiliarNombre);
            while(esSoloLetras(auxiliarNombre)==0)
            {
                printf("Error, Ingrese un tipo de nombre correcto ");
                fflush(stdin);
                gets(auxiliarNombre);
            }

            strcpy(listaEmployee[indice].name, auxiliarNombre);
            printf("\nEmpleado modificado con exito!\n");
            retorno=indice;
            break;

        case 2:
            printf("Ingrese el nuevo apellido del empleado:");
            fflush(stdin);
            gets(auxiliarApellido);
            while(esSoloLetras(auxiliarApellido)==0)
            {
                printf("Error, Ingrese un tipo de apellido correcto ");
                fflush(stdin);
                gets(auxiliarApellido);
            }

            strcpy(listaEmployee[indice].lastname, auxiliarApellido);
            printf("\nEmpleado modificado con exito!\n");
            retorno=indice;
            break;

        case 3:
            printf("Ingrese el nuevo salario del empleado:");
            fflush(stdin);
            gets(auxiliarsalary);
            while(esNumerico(auxiliarsalary)==0)
            {
                printf("Error, ingrese un salario correcto ");
                fflush(stdin);
                gets(auxiliarsalary);
            }

            salary = atoi(auxiliarsalary);
            listaEmployee[indice].salary = salary;
            printf("\nEmpleado modificado con exito!\n");
            retorno=indice;
            break;

        case 4:
            printf("Ingrese el nuevo sector del empleado:");
            fflush(stdin);
            gets(auxiliarSector);
            while(esNumerico(auxiliarSector)==0)
            {
                printf("Error, ingrese un sector correcto ");
                fflush(stdin);
                gets(auxiliarSector);
            }
            sector = atoi(auxiliarSector);
            listaEmployee[indice].sector = sector;
            printf("\nEmpleado modificado con exito!\n");
            retorno=indice;
            break;

        default:
            retorno = -3;
            break;
        }
    }
    else
    {
        retorno = -3;
    }

    return retorno;
}

