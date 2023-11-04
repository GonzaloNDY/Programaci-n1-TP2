/*Codificar un programa en el que se solicita el ingreso de un carácter, luego presentar por
pantalla un mensaje que indique si dicho carácter es un dígito, una letra del alfabeto en
mayúscula, una letra del alfabeto en minúscula o de otro tipo de carácter*/

#include <stdio.h>
#include <ctype.h>

int main (int argc, char*argv[]){
    char caracter;
    printf("\n\tIngrese un caracter:\t");
    scanf("%c", &caracter);
    if (isdigit(caracter))
        printf("El caracter ingresado es un número\n");
    else if (isupper(caracter))
        printf("El caracter ingresado es una letra mayuscula\n");
    else if (islower(caracter))
        printf("El caracter ingresado es una letra minuscula\n");
    else {
        printf("El caracter ingresado no es una letra ni un número\n");
    }
    return 0;
}