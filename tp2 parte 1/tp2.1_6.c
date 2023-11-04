/*Ingresar un número entero y mostrar por pantalla el número ingresado y su valor
absoluto*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    int num;
    printf("Ingresar un número: ");
    scanf("%i", &num);
    print("El valor absoluto del número %i es %i", num, abs(num));
    return 0;
}