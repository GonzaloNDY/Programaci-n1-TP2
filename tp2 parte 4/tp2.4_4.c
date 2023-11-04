/*Realizar un programa que permita generar N códigos incrementales automáticos a partir
de un cierto número base definido previamente. Por ejemplo, si se quieren generar 5
códigos incrementales a partir de un cierto número, como ser el 10000, se generarán los
siguientes códigos: 10001, 10002, 10003, 10004, 10005.
Para ello escriba una función que genere un código incremental. Utilice una variable
estática para almacenar el último código generado y aumente el valor del código en 1
cada vez que se llame a la función. Esta función debe cumplir con la siguiente
declaración:
int generadorNumero();*/

#include <stdio.h>

int solicitarCantidad();
int generadorNumero();

int main(int argc, char *argv[]){
    int contador;
    printf("\nIngrese la cantidad de códigos incrementales automáticos a generar: ");
    contador = solicitarCantidad();
    for (;contador > 0 ; contador--){
        printf("%i\n", generadorNumero());
    }
    
    return 0;
}

int solicitarCantidad(){
    int numero;
    scanf("%i", &numero);
    while (numero <= 0){
        printf("El valor ingresado tiene que ser mayor a cero, ingrese un número positivo: ");
        scanf("%i", &numero);
    }
    return numero;
}

int generadorNumero(){
    static int base;
    if (base == 0){
        printf("Ingrese el número base del que se generarán los códigos incrementales: ");
        base = solicitarCantidad();
    }
    base++;
}