/*. (Referencia ejercicio 2 del TP2-Parte 3)Ingresar N caracteres en un programa, identificar
cuántos caracteres son letras minúsculas e indicar el porcentaje con respecto al total de
caracteres.
Por ejemplo: se ingresa N= 10 y se ingresan los siguientes caracteres: e 5 T 1 C i ? / 1 >
Se debe mostrar que el porcentaje de minúsculas fue del 20%.
Para ello usar funciones para:
● controlar el valor de N,
● contar cuantos caracteres en minúsculas se ingresaron, con una función con la
siguiente declaración:
void contarMinusculas(char c, int *cantidadMinusculas);
● calcular el porcentaje con una función con esta declaración:
void calcularPorcentaje(int cantidad, int total, float *porcentaje);
● presentar por pantalla el promedio, con una función con la siguiente declaración:
void mostrarPorcentaje(float porcentaje);*/

#include <stdio.h>
#include <ctype.h>

int solicitarCantidad();
void contadorMinusculas(char caracter, int *cantMinus);
void calcularPromedio(int cantidadMinus, int totalLetras, float *promedio);
void mostrarPorcentaje(float porcentaje);

int main(int argc, char *argv[]){
    int cantidad, cantMinus = 0;
    float promedioMinus = 0;
    char caracter;
    cantidad = solicitarCantidad();
    printf("Ingrese los caracteres a controlar:\n");
    for (int i = 0; i < cantidad; i++){
        fgetc(stdin);
        scanf("%c", &caracter);
        contadorMinusculas(caracter, &cantMinus);
    }
    calcularPromedio(cantMinus, cantidad, &promedioMinus);
    mostrarPorcentaje(promedioMinus);
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

void contadorMinusculas(char caracter, int *cantMinus){
    if (islower(caracter)){
        ++*cantMinus;  //El operador de post incremento (variable++) no sirve al usar parametros por referencia debido a que devuelve
    }                  //el valor original antes de la modificación. Pero la variable si se incrementa correctamente dentro de la funcion
}

void calcularPromedio(int cantidadMinus, int totalLetras, float *promedio){
    *promedio = (cantidadMinus * 1.0) * 100 / totalLetras;
}

void mostrarPorcentaje(float porcentaje){
    printf("El promedio de letras minúsculas ingresadas es: %.1f%c\n", porcentaje, '%');
}