/*Ingresar N números enteros no negativos, luego presentar por pantalla cuantas series de
números estrictamente crecientes aparecen.
Ejemplo: 5, 1, 9, 7, 6, 0, 1, 9, 3, 2, 4, 7, 9
.          |----|      |-------|   |----------|
.             1            2             3   ----→   3 series*/

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
    printf("\nLa cantidad de series de números crecientes es %i\n", contadorSeries);
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
    static int cantSeries, bandera, numAnterior = -2147483648;
    if (num > numAnterior && numAnterior != -2147483648){
        bandera++;
        if (bandera == 1){
            cantSeries++;
        }
    } else {
        bandera = 0;
    }
    numAnterior = num;
    return cantSeries;
}