/*Realizar un programa que permita ingresar N números enteros positivos y muestre la
suma de todos ellos. Para esto, escriba una función que reciba un número entero como
argumento y devuelva la suma acumulativa de todos los números ingresados. Utilice una
variable estática para almacenar la suma acumulativa*/

#include <stdio.h>

int controlPositivo();
int sumaNumeros(int num);

int main(int argc, char *argv[]){
    int cantidad, num, suma;
    printf("\nIndique la cantidad de numeros a controlar: ");
    cantidad = controlPositivo();
    printf("\tIngrese los números a sumar:\n");
    for (; cantidad > 0 ; --cantidad){
        scanf("%i", &num);
        suma = sumaNumeros(num);
    }
    printf("La suma de los números ingresados es: %i\n", suma);
    return 0;
}

int controlPositivo(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0)
            printf("El valor ingresado tiene que ser mayor que cero, intente nuevamente: ");
    } while (num < 0);
    return num;
}

int sumaNumeros(int num){
    static int suma;
    suma += num;
    return suma;
}