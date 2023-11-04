/*Un número triangular es un número que puede recomponerse en la forma de un
triángulo equilátero (por convención, el primer número triangular es el 1). Es decir, los
primeros números triangulares son 1, 3, 6, 10, etc. Elabore un programa que muestre en
pantalla los N primeros números triangulares*/

#include <stdio.h>

int solicitarCantidad();
void mostrarTriangular();

int main(int argc, char*argv[]){
    int num;
    printf("\nIndique la cantidad de números triangulares que se mostrarán: ");
    num = solicitarCantidad();
    printf("Los primeros %i números triangulares son:\n", num);
    for (;num > 0; num--){
        mostrarTriangular();
    }
    return 0;
}

int solicitarCantidad(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El valor ingresado tiene que ser mayor a cero, ingrese un nuevo valor: ");
    } while (numero <= 0);
    return numero;
}

void mostrarTriangular(){
    static int triangular, aux = 1;
    triangular += aux;
    aux++;
    printf("%i\n", triangular);
}