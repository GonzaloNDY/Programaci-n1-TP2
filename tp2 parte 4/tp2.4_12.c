/*(Referencia ejercicio 9 del TP2-Parte 2) Codificar un programa en el que se solicita el ingreso
de un carácter alfabético, luego presentar por pantalla el carácter en mayúscula si el mismo fue
ingresado en minúscula y viceversa. Para resolver este ejercicio deberá implementar:
a- una función para ingresar el carácter y controlar que sea alfabético.
b- una función para devolver el carácter convertido (esta función no debe retornar
un valor)
c-una función para mostrar por pantalla el caracter convertido(esta función no es
necesario que retorno valor)*/

#include <stdio.h>
#include <ctype.h>

char controlCaracter();
void convertirCaracter(char *caracter); 
void mostrarCaracter(char caracter);

int main(int argc, char *argv[]){
    char letra;
    printf("\nIngrese una letra: ");
    letra = controlCaracter();
    convertirCaracter(&letra);
    mostrarCaracter(letra);
    return 0;
}

char controlCaracter(){
    char letra;
    do {
        scanf("%c", &letra);
        if (!isalpha(letra)){
            printf("El caracter ingresado debe ser una letra, intente nuevamente: ");
            fgetc(stdin);
        }
    } while (!isalpha(letra));
    return letra;
}

void convertirCaracter(char *caracter){
    *caracter = toupper(*caracter);
}

void mostrarCaracter(char caracter){
    printf("\n--- La letra convertida en mayúscula es: \"%c\" ---\n", caracter);
}