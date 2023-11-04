/* Se ingresan N números enteros, presentar por pantalla un mensaje indicando cuál es el
promedio de los impares. No considerar el número cero como número impar. Resolver
empleando funciones:
○ Controlar que el valor de N con la función solicitarCantidad().
○ Usar además una función para determinar si un número es impar
○ Usar una función para calcular el promedio de solicitado*/

#include <stdio.h>

int controlPositivo();
int esImpar(int num);
float calcularPromedio(int cantidadImpares, int total);

int main(int argc, char*argv[]){
    int cantTotal, num, cantImpares = 0;
    printf("\nIndique la cantidad de números a controlar: ");
    cantTotal = controlPositivo();
    printf("Ingrese los números a controlar:\n");
    for (int i = 0; i < cantTotal; i++){
        scanf("%i", &num);
        if (esImpar(num))
            cantImpares++;
    }
    printf("\nDe los %i números ingresados, el %.1f%c son impares\n", cantTotal, calcularPromedio(cantImpares, cantTotal), '%');
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

int esImpar(int num){
    if(num % 2 != 0 && num != 0)
        return 1;
    else
        return 0;
}

float calcularPromedio(int cantidadImpares, int total){
    float promedio;
    promedio = (cantidadImpares * 1.0) * 100 / total;
    return promedio;
}