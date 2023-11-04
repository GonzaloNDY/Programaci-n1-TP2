/*Ingresar dos números enteros número y base, controlar mediante una función que número sea
positivo y mediante otra función controlar que base sea mayor que 1 y menor que 10. Utilizar
una función para realizar la conversión de número a la base representada por el valor base.
Presentar ambos números por pantalla*/

#include <stdio.h>

int controlPositivo();
int baseMenorA10();
int numEnOtraBase(int numero, int base);
int numInvertido(int numero);

int main(int argc, char*argv[]){
    int num, base;
    printf("\nIngrese un número positivo: ");
    num = controlPositivo();
    printf("Ingrese una base mayor a 1 y menor a 10: ");
    base = baseMenorA10();
    printf("El número %i en base 10, es igual al número %i en base %i\n", num, numEnOtraBase(num, base), base);
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

int baseMenorA10(){
    int base;
    do {
        scanf("%i", &base);
        if (base <= 1 || base >= 10)
            printf("La base tiene que ser mayor que 1 y menor que 10, ingrese una nueva base: ");
    } while (base <= 1 || base >= 10);
    return base;
}

int numEnOtraBase(int numero, int base){
    int numCambiado = 0, flag = 0;
    while (numero != 0){
        numCambiado = numCambiado * 10 + numero % base;
        if (numCambiado == 0 && numero % base == 0){
            flag = 1;
        }
        numero /= base;
    }
    numCambiado = numInvertido(numCambiado);
    if (flag){
        numCambiado *= 10;
    }
    return numCambiado;
}

int numInvertido(int numero){
    int invertido = 0;
    while(numero > 0){
        invertido = invertido * 10 + (numero % 10);
        numero /= 10;
    }
    return invertido;
}