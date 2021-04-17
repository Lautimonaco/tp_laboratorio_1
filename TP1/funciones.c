#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float sumar(float numeroUno, float numeroDos)
{
    float suma;
    suma = numeroUno + numeroDos;
    return suma;
}

float restar(float numeroUno, float numeroDos)
{
    float resta;
    resta = numeroUno - numeroDos;
    return resta;
}

float dividir(float numeroUno, float numeroDos)
{
    float division;
    if(numeroUno == 0 || numeroDos == 0)
    {
        printf("Error, no es posible dividir por 0.\n");  //
    }
    else
    {
        division = numeroUno / numeroDos;
        printf("Operaciones realizadas con exito.\n");
    }
    return division;
}

float multiplicar(float numeroUno, float numeroDos)
{
    float multiplicacion;
    multiplicacion = numeroUno * numeroDos;
    return multiplicacion;
}

long int factorizar(long int numero)
{
    int i;
    long int factorizacion=1;
    if(numero < 0)
    {
        printf("\n Error, no se pueden factorizar numeros negativos.\n");
    }
    else
    {
        for(i=1; i<=numero; i++)
        {
            factorizacion*=i;
        }
    }
    return factorizacion;
}

void calculadora()
{
    float A=0;
    float B=0;
    float resultadosuma;
    float resultadoresta;
    float resultadodivision;
    float resultadomultiplicacion;
    long int resultadofactorialuno;
    long int resultadofactorialdos;
    char opciones;
    int flag=0;
    char seguir='N';


    printf("---------------------CALCULADORA-------------------\n");

    while(seguir=='N')
    {
        system("cls");
        printf("---------------------CALCULADORA-------------------\n\n");
        printf("Seleccione una opcion:\n");
        printf("1) Primer operando (A = %.2f)\n", A);
        printf("2) Segundo operando (B = %.2f)\n", B);
        printf("3) Calcular todas las operaciones \n");
        printf("4) Informar resultados\n");
        printf("5) Salir \n");
        fflush(stdin);
        printf("INGRESE UNA OPCION: \n");
        scanf("%c",&opciones);

        switch(opciones)
        {
        case '1':
            printf("Ingrese el primer operando: ");
            scanf("%f", &A);
            break;

        case '2':
            printf("Ingrese el segundo operando: ");
            scanf("%f", &B);
            break;

        case '3':
            resultadosuma = sumar(A,B);
            resultadoresta = restar(A,B);
            resultadodivision = dividir(A,B);
            resultadomultiplicacion = multiplicar(A,B);
            resultadofactorialuno = factorizar(A);
            resultadofactorialdos = factorizar(B);
            flag=1;
            break;

        case '4':
            if(flag==1)
            {
            printf("El resultado de A+B es: %.2f\n", resultadosuma);
            printf("El resultado de A-B es: %.2f\n", resultadoresta);
            printf("El resultado de A/B es: %.2f\n", resultadodivision);
            printf("El resultado de A*B es: %.2f\n", resultadomultiplicacion);
            printf("El factorial de A es: %ld y el factorial de B es: %ld\n", resultadofactorialuno, resultadofactorialdos);
            }
            else
            {
                printf("ERROR, primero debes calcular todas las operaciones.\n\n");
            }
            break;

        case '5':
            system("cls");
            fflush(stdin);
            printf("Esta seguro que desea salir? S/N \n");
            scanf("%c",&seguir);
            seguir = toupper(seguir);
            if(seguir=='S')
            {
                system("cls");
                printf("\nGracias por utilizar la calculadora!\nSaliendo del programa...\n\n");
            }
            break;
        default:
            printf("Opcion invalida, ingrese una opcion del 1 al 5.\n\n");
        }
        system("pause");
    }
    return 0;

}



