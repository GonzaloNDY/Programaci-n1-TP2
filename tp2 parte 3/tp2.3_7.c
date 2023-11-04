/*Dado un número natural de 4 o más dígitos, presentar por pantalla el número y su
invertido. Ejemplo : número = 34256, invertido = 65243. Para resolver emplear:
○ Una función para controlar que el número ingresado sea de 4 o más dígitos
○ Una función para invertir el número*/

#include <stdio.h>

int control4digitos();
int numInvertido( int num);

int main(int argc, char*argv[]){
    int num;
    printf("\nIngrese un número de 4 o más cifras: ");
    num = control4digitos();
    if (num % 10 == 0){
        printf("\n\tEl invertido de %i es: 0%i\n", num, numInvertido(num));
    } else {
        printf("\n\tEl invertido de %i es: %i\n", num, numInvertido(num));
    }
    return 0;
}

int control4digitos(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero < 1000)
            printf("El número ingresado tiene que tener 4 dígitos o más, ingrese un nuevo valor: ");
    } while (numero < 1000);
    return numero;
}

int numInvertido( int num){
    int invertido = 0;
    for (; num > 0; num /= 10){
        invertido = invertido * 10 + (num % 10);
    }
    return invertido;
}