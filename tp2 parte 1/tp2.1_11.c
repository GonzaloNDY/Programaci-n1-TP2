/*Generar N números aleatorios e indicar la cantidad de números pares e impares*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char*argv[]){
    srand(time(NULL));
    int cantidad, num, cantPar = 0, cantImpar = 0;
    printf("Ingresar la cantidad de números aleatorios a generar: ");
    do {
        if (scanf("%i", &cantidad) != 1)   //verifica que se ingrese un número entero válido
            printf("Entrada inválida. Intente de nuevo (la cantidad tiene que ser un número mayor a cero): ");
            getchar();
            continue;
        if (cantidad <= 0)
            printf("Tiene que ser un valor mayor a cero, ingrese una cantidad válida:\t");
    } while (scanf("%i", &cantidad) != 1 || cantidad <= 0);
    do {
        num = rand() % 100 + 1;
        printf("\t%i\n", num);
        if (num % 2 == 0)
            cantPar++;
        else {
            cantImpar++;
        }
        cantidad--;
    } while (cantidad > 0);
    printf("\nSe ingresaron %i números pares y %i números impares\n", cantPar, cantImpar);
    return 0;
}