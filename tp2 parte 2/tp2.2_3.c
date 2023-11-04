/*Ingresar un número entero positivo, luego presentar por pantalla un mensaje que indique si el
número ingresado es o no es primo. Para resolver implementar:
a- una función que realice el control de que el número sea positivo.
b- una función que determine si un número es primo*/

#include <stdio.h>

int controlPositivo();
int esPrimo(int num);

int main(int argc, char*argv[]){
    int num;
    printf("\nIngrese un número positivo: ");
    num = controlPositivo();
    if (esPrimo(num)){  //si la funcion retornó algo distinto de cero, es verdadero 
        printf("El numero ingresado es primo\n");
    } else {
        printf("El numero ingresado no es primo\n");
    }
    return 0;
}

int controlPositivo(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El número ingresado tiene que ser mayor a cero, ingrese un nuevo número: ");
    } while (numero <= 0);
    return numero;
}

int esPrimo(int numero){
    for (int i = 2; i < numero; ++i){
        if (numero % i == 0)
            return 0;  //en c, el cero es interpretado como falso
    }
    return 1;  //números distintos de cero se interpretan como verdadero
}