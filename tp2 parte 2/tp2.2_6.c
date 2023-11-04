/*Leer un número entero positivo de dos o más dígitos, y luego presentar por pantalla al número
ingresado y su invertido. Para resolver deberá implementar
a- función para controlar si un número es un entero positivo de dos o más dígitos
b- función para generar el invertido del número dado*/

#include <stdio.h>

int ingresarEntero2Cifras();
int numInvertido(int numero);

int main(int argc, char*argv[]){
    int numDosCifras;
    printf("\nIngrese un número de 2 o mas cifras: ");
    numDosCifras = ingresarEntero2Cifras();
    printf("El invertido de %d es %d\n", numDosCifras, numInvertido(numDosCifras));
    return 0;
}

int ingresarEntero2Cifras(){
    int numero;
    do {
        scanf("%d", &numero);
        if (numero < 10)
            printf("El número ingresado tiene que ser de dos o más cifras, ingrese un nuevo número: ");
    } while (numero < 10);
    return numero;
}

int numInvertido(int numero){
    int invertido = 0;
    while(numero > 0){
        invertido = invertido * 10 + (numero % 10);
        numero /= 10;
    }
    return invertido;
}