/*Ingresar N números enteros, luego presentar por pantalla la cantidad de series de
números impares ingresados. Se considera serie si tiene 2 o más elementos seguidos.
Ejemplo: 4, 9, 2, 5, 3, 2, 15, 3, 7, 9
.                |----|   |-----------|
.                  1            2     ----> 2 series*/

#include <stdio.h>

int solicitarCantidad();
int controlSeries(int num);

int main(int argc, char *argv[]){
    int cantidad, num, contadorSeries = 0;
    printf("\nIndique la cantidad de números a controlar");
    cantidad = solicitarCantidad();
    printf("\nIngrese los números a controlar:\n");
    for (;cantidad > 0; --cantidad){
        scanf("%i", &num);
        contadorSeries = controlSeries(num);
    }
    printf("\nLa cantidad de series de números impares es %i\n", contadorSeries);
    return 0;
}

int solicitarCantidad(){
    int numero;
    do {
        printf(" (el valor ingresado tiene que ser mayor a cero): ");
        scanf("%i", &numero);
    } while (numero <= 0);
    return numero;
}

int controlSeries(int num){
    static int cantSeries, bandera;
    if (num % 2 != 0){
        bandera++;
        if (bandera == 2){
            cantSeries++;
        }
    } else {
        bandera = 0;
    }
    return cantSeries;
}