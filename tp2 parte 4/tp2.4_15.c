/*Se reciben dos valores numéricos enteros, realizar con ellos la suma, resta, división y
multiplicación y mostrar los resultados en pantalla.
Para resolver este problema debe:
○ Crear un menú a través del cual se puedan seleccionar las operaciones a realizar
○ Cada una de las operaciones deberá ser resuelta por una función y los resultados
se mostrarán en la función principal main().
Observación: Tener en cuenta que las funciones deben ser:
menu(): Retorna Valor (devuelve la operación seleccionada) y no tiene
parámetros.
suma(): Retorna Valor (devuelve resultado de la suma) y usa parámetros por
valor.
resta(): No retorna valor, utiliza dos parámetros por valor y uno por referencia.
cociente(): Retorna valor y utiliza parámetros por valor. ¡Cuidado con la división
en cero!
producto(): No retorna valor, utiliza dos parámetros por valor y uno por
referencia*/

#include <stdio.h>

int controlMenu();
int sumaNumeros(int num1, int num2);
void restaNumeros(int num1, int num2, int *resta);
void cocienteNumeros(int num1, int num2, float *cociente);
void productoNumeros(int num1, int num2, int *producto);

int main(int argc, char *argv[]){
    int opcionMenu, num1, num2, suma, resta, producto;
    float cociente;
    printf("\n\tCalculadora simple y básica\n\n1)Suma\t\t\t3)Resta\n\n2)Multiplicación\t4)División\n\nIngrese una de las opciones mostradas: ");
    opcionMenu = controlMenu();
    printf("\nIngrese el primer número: ");
    scanf("%i", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%i", &num2);
    switch (opcionMenu){
    case 1:
        suma = sumaNumeros(num1, num2);
        printf("\nLa suma de los números ingresados es %i\n", suma);
        break;
    case 2:
        restaNumeros(num1, num2, &resta);
        printf("\nLa resta de los números ingresados es %i\n", resta);
        break;
    case 3:
        if (num2 < 0){
            printf("\nError. No es posible realizar la división entre cero\n");
        } else {
            cocienteNumeros(num1, num2, &cociente);
            printf("\nEl cociente de los números ingresados es %.1f\n", cociente);
        }
        break;
    case 4:
        productoNumeros(num1, num2, &producto);
        printf("El producto de los números ingresados es %i\n", producto);
        break;
    }
    return 0;
}

int controlMenu(){
    int  opcion;
    do {
        scanf("%i", &opcion);
        if (opcion < 1 || opcion > 4)
            printf("Opción no válida, intente nuevamente: ");
    } while (opcion < 1 || opcion > 4);
    return opcion;
}

int sumaNumeros(int num1, int num2){
    int suma;
    suma = num1 + num2;
    return suma;
}

void restaNumeros(int num1, int num2, int *resta){
    *resta = num1 - num2;
}

void cocienteNumeros(int num1, int num2, float *cociente){
    *cociente = (num1 * 1.0) / num2;
}

void productoNumeros(int num1, int num2, int *producto){
    *producto = num1 * num2;
}