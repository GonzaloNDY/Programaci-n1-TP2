/*Realizar un programa en lenguaje C que permita ingresar un valor N y muestre las N letras en
mayúsculas en orden descendente.
Por ejemplo si se ingresa N = 5, deberá mostrar: Z, Y, X, W, V
Para resolver implementar:
a- una función que realice el control de que N sea positivo
b- una función que muestre las letras en mayúsculas en orden descendente*/

#include <stdio.h>

int controlPositivo();
void mostrar_N_ultimasLetras(int num);

int main(int argc, char*argv[]){
    int num;
    printf("Ingresar un número positivo: ");
    num = controlPositivo();
    printf("Las últimas %i letras mayúsculas del alfabeto son:\n", num);
    mostrar_N_ultimasLetras(num);
    return 0;
}

int controlPositivo(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El número ingresado tiene que ser mayor a cero, ingrese un nuevo número: ");
    } while (numero <= 0);
    return numero;
}

void mostrar_N_ultimasLetras(int numero){
    char control;
    control = 'Z' - numero;
    for (char letra = 'Z'; letra > control; letra--){
        printf("%c\n", letra);
    }
}