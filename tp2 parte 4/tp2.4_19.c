/* Ingresar dos caracteres; controlar que los mismos sean letras del alfabeto; en caso de
que las letras ingresadas sean mayúsculas, convertirlas a minúsculas; luego presentar
por pantalla dichas letras pero ordenadas en forma alfabética, o un mensaje en caso de
que sean iguales (debe realizar una función para ordenar las letras y determinar si son
iguales)*/

#include <stdio.h>
#include <ctype.h>

char controlLetra();
void ordenarLetras(char *letraMenor, char *letraMayor, int *bandera);

int main(int argc, char *argv[]){
    int bandera = 0;
    char letra1, letra2;
    printf("Ingrese la primera letra: ");
    letra1 = controlLetra();
    printf("Ingrese la segunda letra: ");
    letra2 = controlLetra();
    ordenarLetras(&letra1, &letra2, &bandera);
    if (bandera){
        printf("\nLas letras ingresadas son iguales\n");
    } else {
        printf("\nLas letras ingresadas son %c y %c\n", letra1, letra2);
    }
    return 0;
}

char controlLetra(){
    char letra;
    do {
        scanf("%c", &letra);
        fgetc(stdin);
        if (!isalpha(letra))
            printf("El caracter ingresado tiene que ser una letra del alfabeto, ingrese otra letra: ");
    } while (!isalpha(letra));
    letra = tolower(letra);
    return letra;
}

void ordenarLetras(char *letraMenor, char *letraMayor, int *bandera){
    char auxiliar;
    if (*letraMenor > *letraMayor){
        auxiliar = *letraMayor;
        *letraMayor = *letraMenor;
        *letraMenor = auxiliar;
    } else if (letraMayor == letraMenor){
        *bandera = 1;
    }
}