/*. Solicitar al usuario el ingreso de un carácter y luego mostrarlo por pantalla. Realizar la
lectura y presentación por pantalla empleando las funciones: scanf, fgetc, getchar, printf,
fputc y putchar.*/

#include <stdio.h>

int main (int argc, char*argv[]){
    char caracter;
    //Usando printf() y scanf():
    printf("Ingrese un caracter: ");
    scanf("%c", &caracter);
    printf("El caracter ingresado es %c\n", caracter);
    fgetc(stdin);
    //Usando fgetc() y putchar():
    printf("Ingrese otro caracter: ");
    caracter = fgetc(stdin);
    fputc(caracter, stdout);
    printf("\n");
    getchar();
    //Usando getchar() y putchar():
    printf("Ingrese otro caracter: ");
    caracter = getchar();
    putchar(caracter);
    printf("\n");
    return 0;
}