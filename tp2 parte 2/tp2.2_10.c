/*Codificar un programa en el que se solicita el ingreso de N carácteres, luego presentar por
pantalla las consonantes ingresadas en minúscula y las vocales en mayúscula.
Para resolver este ejercicio deberá implementar:
a- función para controlar si el número N es un entero positivo.
b-función para solicitar el ingreso de los caracteres, evaluarlos y presentarlos por
pantalla (las vocales en mayúscula y las consonantes en minúscula)*/

#include <stdio.h>
#include <ctype.h>

int controlPositivo();
char ingresoYpresentacionDeLetra();

int main(int argc, char*argv[]){
    int cantidad;
    printf("\nIndique la cantidad de letras que ingresará: ");
    cantidad = controlPositivo();
    printf("Ingrese los caracteres a controlar:\n");
    while (cantidad > 0){
        ingresoYpresentacionDeLetra();
        cantidad--;
    }
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

char ingresoYpresentacionDeLetra(){
    char caracter;
    do {
        fgetchar();
        scanf("%c", &caracter);
        if (!isalpha(caracter)){
            printf("El caracter ingresado no es una letra, ingrese un nuevo caracter: ");
        }
    } while (!isalpha(caracter));
    caracter = tolower(caracter);
    if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u'){
        printf("La letra \"%c\" es una vocal\n", toupper(caracter));
    } else {
        printf("La letra \"%c\" es una consonante\n", caracter);
    }
    return caracter;
}