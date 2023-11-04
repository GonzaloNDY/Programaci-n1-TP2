/*Realizar un programa que halle cualquier raíz de un número entero positivo. El usuario
deberá indicar el número (por ejemplo, 2) y el índice de la raíz (por ejemplo, 3 para la
raíz cúbica). Pista: hallar la raíz cúbica de 2 es lo mismo que elevar 2 a 1/3*/

#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[]){
    float num, raiz;
    printf("\n\tPrograma para calcular la raiz de un número\nIngrese el número al que se la calculará la riz: ");
    scanf("%f", &num);
    printf("Indique el índice de la raiz a calcular: ");
    scanf("%f", &raiz);
    printf("La raiz %0.f de %0.f es: %0.f\n", raiz, num, pow(num, (1/raiz)));
    return 0;
}