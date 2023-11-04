/*Codificar un programa en el que se solicita el ingreso de un carácter alfabético, luego
presentar por pantalla el carácter en mayúscula si el mismo fue ingresado en minúscula
y viceversa*/

#include <stdio.h>
#include <ctype.h>

int main(int argc,char*argv[]){
    char letra;
    printf("Ingresar un caracter alfabetico (letras): ");
    do{
        scanf("%c", &letra);
        fgetc(stdin);
        if (!isalpha(letra))
            printf("El caracter ingresado no es una letra, ingreselo nuevamente: ");
    } while (!isalpha(letra));
    if (isupper(letra))
        printf("\t%c\n", tolower(letra));
    else if (islower(letra)){
        printf("\t%c\n", toupper(letra));
    }
    return 0;
}