/*Ingresar N caracteres en un programa, identificar cuántos caracteres son letras
minúsculas e indicar el porcentaje con respecto al total de caracteres. Por ejemplo: se
ingresa N= 10 y se ingresan los siguientes caracteres: e 5 T 1 C i ? / 1 >
Se debe mostrar que el porcentaje de minúsculas fue del 20%.
Para ello usar funciones para:
● controlar el valor de N,
● contar cuantos caracteres en minúsuculas se ingresaron,
● calcular el promedio con una función con esta declaración:
float calcularPromedio(int cantidad, int total);
● presentar por pantalla el promedio, con una función con la siguiente declaración:
void mostrarPorcentaje(float promedio);*/

#include <stdio.h>
#include <ctype.h>

int solicitarCantidad();
int contadorMinusculas(char caracter, int countMinus);
float calcularPromedio(int cantidad, int totalLetras);
void mostrarPorcentaje(float promedio);

int main(int argc, char*argv[]){
    int cantidad, cantMinus = 0;
    char caracter;
    cantidad = solicitarCantidad();
    printf("Ingrese los caracteres a controlar:\n");
    for (int i = 0; i < cantidad; i++){
        fgetc(stdin);
        scanf("%c", &caracter);
        cantMinus = contadorMinusculas(caracter, cantMinus);
    }
    mostrarPorcentaje(calcularPromedio(cantMinus, cantidad));
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

int contadorMinusculas(char caracter, int countMinus){
    if (islower(caracter)){
        countMinus++;
    }
    return countMinus;
}

float calcularPromedio(int cantidadMinusculas, int totalLetras){
    float promedio;
    promedio = (cantidadMinusculas * 1.0) * 100 / totalLetras;
    return promedio;
}

void mostrarPorcentaje(float promedio){
    printf("El promedio de letras minúsculas ingresadas es: %.1f%c\n", promedio, '%');
}