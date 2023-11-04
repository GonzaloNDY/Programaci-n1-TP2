/*Ingresar N caracteres en un programa, identificar cuántos caracteres son numéricos y
cuantos alfabéticos. Presentar por pantalla los resultados. Para ello usar funciones para:
○ int solicitarCantidad(): solicita el ingreso de N y controla que sea positivo, en
caso contrario vuelve a solicitarlo.
○ int verificarCaracter(char var): recibe un carácter e identifica si es alfabetico o
numerico. Retorna 1 si es numérico y retorna 2 si es alfabetico*/

#include <stdio.h>
#include <ctype.h>

int solicitarCantidad();
int verificarCaracter( char var);

int main(int argc, char*argv[]){
    int contadorLetras = 0, contadorNumeros = 0;
    char caracter;
    for (int i = solicitarCantidad(); i > 0; i--){
        fgetc(stdin);
        printf("Ingrese un caracter: ");
        scanf("%c", &caracter);
        if (verificarCaracter(caracter) == 1){
            contadorNumeros++;
        } else if (verificarCaracter(caracter) == 2){
            contadorLetras++;
        }
    }
    printf("\n\tSe ingresaron %i letras y %i números\n", contadorLetras, contadorNumeros);
    return 0;
}

int solicitarCantidad(){
    int numero;
    printf("\nIndique la cantidad de caracteres que ingresará: ");
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El valor ingresado tiene que ser mayor a cero, ingrese un nuevo valor: ");
    } while (numero <= 0);
    return numero;
}

int verificarCaracter( char var){
    if (isalpha(var)){
        return 2;
    } else if (isdigit(var)){
        return 1;
    }
}