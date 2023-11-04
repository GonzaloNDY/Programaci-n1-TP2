/* Realizar un programa que permita ingresar N números enteros positivos, luego
determinar el valor promedio (o media aritmética) de los números ingresados que sean
primos.
Para resolver este problema deberá implementar las siguientes funciones:
a- ingresarEntero(): permite ingresar un número entero y controlar si el mismo es
positivo.
b- esPrimo(): para determinar si un número es primo.
c- promedioPrimos(): calcula el promedio de los números primos (esta función no debe
retornar un valor)
Se debe presentar por pantalla el promedio calculado, o en su defecto un mensaje si en
la serie ingresada no hay números primos.
Aclaración: Ud debe definir si las funciones arribas mencionadas reciben o no
parámetros, como así también si retornan o no valor*/

#include <stdio.h>

int ingresarEntero();
int esPrimo(int num);
void promedio(float *promedio, int num, int cantidad);

int main(int argc, char *argv[]){
    int cantidad, numero, contadorPrimos = 0;
    float promedioPrimos = 0;
    printf("\nIndique la cantidad de números positivos que ingresará: ");
    cantidad = ingresarEntero();
    printf("Ingrese los números positivos a controlar:\n");
    for (int i = 0; i < cantidad; i++){
        numero = ingresarEntero();
        if (esPrimo(numero)){
            contadorPrimos++;
        }
    }
    promedio(&promedioPrimos, contadorPrimos, cantidad);
    if (promedioPrimos)
        printf("\nEl %c%.1f de los números ingresados son primos\n", '%', promedioPrimos);
    else
        printf("\nNo se ingresaron números primos\n");
    return 0;
}

int ingresarEntero(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El valor ingresado tiene que ser mayor a cero, ingrese un nuevo valor: ");
    } while (numero <= 0);
    return numero;
}

int esPrimo(int num){
    for (int i = 2; i < num; i++){
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void promedio(float *promedio, int num, int cantidad){
    *promedio = num * 100.0 / cantidad; 
}