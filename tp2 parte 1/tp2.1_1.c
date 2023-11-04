/*Ingresar caracteres e ir mostrando los mismos por pantalla hasta que el usuario ingrese
el carácter ‘n’(este último no debe mostrarse por pantalla)*/

#include <stdio.h>

int main(int argc, char*argv[]){
    char caracter;
    printf("\n\tPrograma para ingresar y mostrar caracteres (para finalizar presione 'n')");
    do {
        printf("Ingrese un caracter: ");
        scanf("%c", &caracter);
        fgetc(stdin);
        if (caracter != 'n')
            printf("El caracter ingresado es: %c\n", caracter);
    } while (caracter != 'n');
    return 0;
}