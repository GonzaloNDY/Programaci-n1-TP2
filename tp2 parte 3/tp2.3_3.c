/* Implementar un programa que solicite el ingreso de un valor NUMERO y que muestre
por pantalla un mensaje que indique si el valor ingresado es o no un número primo. Usar
una función con esta declaración para verificar lo solicitado: int esPrimo(int numero);*/

#include <stdio.h>

int esPrimo(int numero);

int main(int argc, char*argv[]){
    int numero;
    printf("\nIngrese un número: ");
    scanf("%i", &numero);
    if (esPrimo(numero)){
        printf("\n\tEl número %i es primo\n", numero);
    } else {
        printf("\n---- El número %i no es primo ----\n", numero);
    }
    return 0;
}

int esPrimo(int num){
    for (int i = 2; i < num; i++){
        if (num % i == 0)
            return 0;
    }
    return 1;
}