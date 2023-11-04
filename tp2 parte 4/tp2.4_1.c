/*Presentar por pantalla, las N primeras letras del alfabeto en mayúsculas*/

#include <stdio.h>

int solicitarCantidad();
void mostrarLetras();

int main(int argc, char*argv[]){
    int cantidad;
    printf("Indique la cantidad de letras del abecedario que se mostrarán: ");
    cantidad = solicitarCantidad();
    for (;cantidad > 0; cantidad--){
        mostrarLetras();
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

void mostrarLetras(){
    static char letra = 'A';
    printf("%c\n", letra);
    letra++;
}