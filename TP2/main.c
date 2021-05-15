#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "FuncionesGet.h"

#define MAX 1000

int main()
{
    int i;
    int Init;
    int checkIn;
    int checkLow;
    int checkModification;
    int acumSalary;
    int contSalary;
    float averageSalary;
    int contHighSalaryAverage;
    char opcion;

    Employee listEmployees[MAX];

    Init = initEmployees(listEmployees, MAX);
    if (Init == 0) //Valida si se inician los estados
    {
        printf("Los estados se han inicializado");

    }
    else
    {
        printf("Error al inicializar estados.\n");
    }

    printf("\n\n\n");
    system("pause");

    addEmployees(listEmployees, MAX); // Se inicia el programa con datos ya cargados

    do
    {
        system("cls");
        printf("BIENVENIDO A LA NOMINA DE EMPLEADOS!\n\n");
        printf("1 - ALTA DE EMPLEADO\n");
        printf("2 - MODIFICAR EMPLEADO \n");
        printf("3 - BAJA DE EMPLEADO\n");
        printf("4 - LISTA DE EMPLEADOS\n");
        printf("5 - ORDENAR EMPLEADOS\n");
        printf("6 - TOTAL Y PROMEDIO SALARIAL DE EMPLEADOS\n");
        printf("7 - SALIR\n");

        printf("Debe elegir una opcion a realizar: ");
        fflush(stdin);
        scanf("%c", &opcion);

        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='6' && opcion!='7')
        {
            printf("Erorr, Ingrese una opcion del 1 al 7!\n\n");
            printf("Elija una opcion: ");
            fflush(stdin);
            scanf("%c", &opcion);
        }

        switch (opcion)
        {
        case '1':
            checkIn = addEmployeesModificado(listEmployees, MAX);
            if (checkIn == 0)
            {
                printf("\n\nEl empleado ha sido dado de alta!\n\n");
            }
            else
            {
                system("cls");
                printf("\nNo quedan espacios libres!\n");
            }
            break;

        case '2':
            checkModification = modificacionDeEmpleado(listEmployees, MAX);

            if (checkModification == -2)
            {
                system("cls");
                printf("\nNo se encontro ningun empleado con esa ID!\n");
            }
            else if (checkModification == -3)
            {
                printf("\nError. Se ha ingresado una opcion invalida.\n");
            }

            break;

        case '3':
            checkLow = removeEmployee(listEmployees, MAX, 5);
            if (checkLow == 0)
            {
                printf("\n\nEl empleado ha sido dado de baja!\n");
            }
            else if (checkLow == -2)
            {
                printf("\n\nSe ha cancelado la baja!\n");
            }
            else
            {
                system("cls");
                printf("\nNo se ha encontrado ningun usuario con esa ID!\n");
            }
            break;

        case '4':
            printEmployees(listEmployees, MAX);
            break;

        case '5':
            sortEmployees(listEmployees, MAX, 0);
            printEmployees(listEmployees, MAX);
            break;

        case '6':
            acumSalary = 0;
            contSalary = 0;
            averageSalary = 0;
            contHighSalaryAverage = 0;


            for (i=0; i<MAX; i++)
            {
                if (listEmployees[i].isEmpty == 1)
                {
                    acumSalary = listEmployees[i].salary + acumSalary;
                    contSalary++;
                }
            }

            averageSalary = (acumSalary / contSalary);

            for (i=0; i<MAX; i++)
            {
                if (listEmployees[i].isEmpty == 1 )
                {
                    if (listEmployees[i].salary > averageSalary)
                    {
                        contHighSalaryAverage++;
                    }
                }
            }


            printEmployees(listEmployees, MAX);

            printf("El Total de los salarios es: %d\n\n", acumSalary);
            printf("El promedio por empleados es: %.2f\n\n", averageSalary);
            printf("La cantidad de empleados que superan el sueldo promedio son: %d\n\n", contHighSalaryAverage);
            break;

        case '7':
            opcion = '7';
            printf("\nSaliendo del programa...\n");
            break;

        default:
            printf("Erorr, Ingrese una opcion correcta del 1 al 7");
        }

        system("pause");
        system("cls");
    }

    while (opcion!='7');
    system("cls");
    printf("\nSaliendo del programa...\n");
    return 0;
}


