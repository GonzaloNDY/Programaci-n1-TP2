/*Realizar un programa en lenguaje C que permita ingresar N caracteres alfabéticos y los
muestre en minúsculas. En caso de ingresar uno que no sea alfabético volver a
solicitarlo.
Por ejemplo si se ingresa N = 4, caracteres ingresados: H, o, L, a deberá mostrar: h o l a*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    int cantidad;
    char caracter;
    printf("\nIndique la cantidad de caracteres alfabeticos que ingresará: ");
    do {
        scanf("%i", &cantidad);
        if (cantidad <= 0)
            printf("Debe ser un numero mayor a cero, ingrese una cantidad válida: ");
    } while (cantidad <= 0);
    printf("Ingrese los caracteres (el programa no funciona con la letra ñ o Ñ):\n");
    while (cantidad > 0) {
        fgetc(stdin);
        scanf("%c", &caracter);
        if (!isalpha(caracter))
            printf("El caracter ingresado no es alfabético, tiene que ingresar solo letras: ");
        else {
            printf("%c\n", tolower(caracter));
            cantidad--;
        }    
    }
    return 0;
}