/*Implementar un programa en el cual: se define una constante numérica llamada "PI" con el valor
3.14, se solicite que se ingrese un número que será el radio de una circunferencia, se calcule el
valor de la longitud de la circunferencia y se lo presente por pantalla.
Recordar que la longitud de la circunferencia = 2 * PI * radio.
Para este problema diseñar una función que reciba los dos valores y calcule el valor de la
solicitado*/

#include <stdio.h>

float longitudCirculo(float radio, float pi);

int main(int argc, char*argv[]){
    float pi = 3.14, radio;
    printf("\nIngrese el radio del circulo:\t");
    scanf("%f", &radio);
    longitudCirculo(radio, pi);
    return 0;
}

float longitudCirculo(float radio, float pi){
    printf("\nLa longitud del circulo es %.2f\n", 2*(pi*radio));
}