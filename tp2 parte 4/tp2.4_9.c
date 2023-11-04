/*(Referencia ejercicio 2 del TP2-Parte 2) Implementar un programa en el cual: se define
una constante numérica llamada "PI" con el valor 3.14; se solicite que se ingrese un
número que será el radio de una circunferencia; se calcule el valor de la longitud de la
circunferencia y se lo presente por pantalla. Recordar que la longitud de la circunferencia
es 2 * PI * radio. Para este problema diseñar una función que no retorne valor y que
además de recibir los dos valores (PI y radio), reciba un parámetro por referencia
donde se guarde el resultado del cálculo solicitado*/

#include <stdio.h>

void longitudCirculo(float pi, float num, float *suma);

int main(int argc, char *argv[]){
    float PI = 3.14, radio, suma = 0;
    printf("\n\tPrograma para calcular la longitud de un círculo\nIngrese el radio del círculo: ");
    scanf("%f", &radio);
    longitudCirculo(PI, radio, &suma);
    printf("\nLa longitud del círculo de radio %.1f es: %.2f\n", radio, suma);
    return 0;
}

void longitudCirculo(float pi, float radio, float *suma){
    *suma = pi * radio * 2;
}