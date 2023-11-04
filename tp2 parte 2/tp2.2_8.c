/*Codificar un programa en el que se solicita el ingreso de un carácter, luego presentar por pantalla
un mensaje que indique si dicho carácter es un dígito, una letra del alfabeto en mayúscula, una
letra del alfabeto en minúscula o de otro tipo de carácter. Para resolver deberá implementar:
a- una función para ingresar el carácter
b-una función para mostrar por pantalla qué tipo de carácter es (esta función no es
necesario que retorne valor)*/

#include <stdio.h>
#include <ctype.h>

char ingresarCaracter();
void mostrarTipoCaracter(char caracter);

int main(int argc, char*argv[]){
    printf("\nIngresar un caracter: ");
    mostrarTipoCaracter(ingresarCaracter());
    return 0;
}

char ingresarCaracter(){
    char caracter;
    scanf("%c", &caracter);
    return caracter;
}

void mostrarTipoCaracter(char caracter){
    if (isdigit(caracter)){
        printf("El caracter \"%c\" es un número\n", caracter);;
    } else if (isupper(caracter)){
        printf("El caracter \"%c\" es una letra mayúscula\n", caracter);;
    } else if (islower(caracter)){
        printf("El caracter \"%c\" es una letra minúscula\n", caracter);;
    } else {
        printf("El caracter \"%c\" no es un número ni una letra\n", caracter);;
    }
}