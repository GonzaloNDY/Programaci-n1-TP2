/*Ingresar un número entero positivo, luego presentar por pantalla la cantidad de dígitos
que posee dicho número. Para resolver emplear:
○ una función que controle si el dato ingresado es un número positivo, caso
contrario solicitar que se ingrese de nuevo.
○ Una función para contar los dígitos del número ingresado*/

#include <stdio.h>

int controlPositivo();
int cantDigitos(int num);

int main(int argc, char**argv[]){
    int num;
    printf("\nIngrese el número a controlar: ");
    num = controlPositivo();
    printf("\n\tEl número %i tiene %i dígitos\n", num, cantDigitos(num));
    return 0;
}

int controlPositivo(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El valor ingresado tiene que ser mayor a cero, ingrese un nuevo valor: ");
    } while (numero <= 0);
    return numero;
}

int cantDigitos(int num){
    int contador = 0;
    for (;num > 0; contador++){
        num /= 10;
    }
    return contador;
}