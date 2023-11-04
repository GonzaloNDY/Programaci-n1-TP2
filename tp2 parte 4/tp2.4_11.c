/*(Referencia ejercicio 3 del TP2-Parte 2) Ingresar un número entero positivo, luego presentar
por pantalla un mensaje que indique si el número ingresado es o no es primo. Para resolver
implementar:
○ una función que realice el control de que el número sea positivo.
○ una función que determine si un número es primo (esta función no debe retornar un valor)*/

#include <stdio.h>

int controlPositivo();
void controlPrimo(int num, int *banderaPrimo);

int main(int argc, char *argv[]){
    int num, banderaPrimo = 1;
    printf("Ingrese un número positivo: ");
    num = controlPositivo();
    controlPrimo(num, &banderaPrimo);
    if (banderaPrimo){
        printf("El número ingresado es primo\n");
    } else {
        printf("El número ingresado no es primo\n");
    }
    return 0;
}

int controlPositivo(){
    int num;
    do {
        scanf("%i", &num);
        if (num < 0)
            printf("El valor ingresado tiene que ser mayor que cero, intente nuevamente: ");
    } while (num < 0);
    return num;
}

void controlPrimo(int num, int *banderaPrimo){
    for (int i = 2; i < num; i++){
        if (num % i == 0)
            *banderaPrimo = 0;
    }
}