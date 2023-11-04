/* Codificar un programa en el que se solicita el ingreso de N carácteres, luego presentar
por pantalla las consonantes ingresadas en minúscula y las vocales en mayúscula*/

#include <stdio.h>
#include <ctype.h>

int main (int argc, char*argv[]){
    int cantCaracteres, cantNum = 0, cantLetraMayus = 0, cantLetraMinus = 0, cantSignos = 0;
    char caracter;
    printf("\nIndique la cantidad de caracteres que ingresará:\t");
    do {
        scanf("%i", &cantCaracteres);
        if (cantCaracteres <= 0){
            printf("Tiene que ser un valor mayor a cero, ingrese una cantidad válida:\t");
        }
    } while (cantCaracteres <= 0);
    printf("Ingrese los caracteres (el programa no reconoce a la ñ o Ñ como letras):\n");
    do {
        fgetc(stdin);
        scanf("%c", &caracter);
        if (isalpha(caracter)){
            caracter = tolower(caracter);
            if (caracter == 'a' || caracter == 'e' ||caracter == 'i' ||caracter == 'o' ||caracter == 'u')
                printf("------%c------\n", toupper(caracter));
            else
                printf("------%c------\n", caracter);
        } else {
            printf("El caracter \"%c\" no es una letra\n", caracter);
        }
        cantCaracteres--;
    } while (cantCaracteres > 0);
    return 0;
}