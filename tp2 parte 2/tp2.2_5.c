/*Ingresar dos números enteros positivos N1 y N2, en donde N1 tiene que ser menor que N2.
Luego sumar los números primos mayores que N1 y menores que N2, Posteriormente mostrar
por pantalla el resultado de la suma.
Por ej: se ingresan N1=1 y N2=5. Los números primos entre N1 Y N2 son 2 y 3. Entonces 2 + 3 = 5
Entonces debe mostrar por pantalla "El resultado de la suma es: 5 ”
Para resolver este problema deberá implementar las definiciones y declaraciones de las
funciones que se solicitan a continuación.
RESPETANDO LOS NOMBRES PARÁMETROS Y DE LA FUNCIÓN Y QUE PARÁMETROS RETORNA.

a- ingresarEntero:
Datos de entrada: ninguno
Proceso: permite ingresar un número entero y controlar si el mismo es positivo.
Salida: retorna el número ingresado.

b- controlarNumeros:
Datos de entrada: dos valores enteros, N1 y N2
Proceso: controlar que un valor (N1) es menor que otro (N2).
Salida: retorna una variable entera que representa si es menor o no.

c- sumarPrimos:
Datos de entrada: dos valores enteros (N1 y N2)
Proceso: sumar los números primos, comprendidos entre dos valores dados (N1
y N2) y mostrar por pantalla el valor.
Salida:no retorna nada

d- Una función para determinar si un número es primo.
Datos de entrada: un número entero
Proceso: determinar si el número es primo
Salida: retorna un entero 1= si el numero es primo, 0= si el número no es primo.
Aclaración: La suma debe efectuarse en la función “sumarPrimos” que llamará a una
segunda función (ud. puede elegir el nombre) que determinará si un número es primo*/

#include <stdio.h>

int ingresarEntero();
int controlMayorMenor(int num1, int num2);
int sumarPrimos(int num1, int num2);
int esPrimo(int numero);

int main(int argc, char*argv[]){
    int num1, num2, aux;
    printf("\nPrograma para sumar los primos comprendidos entre dos números\n");
    printf("\nIngrese un número entero positivo: ");
    num1 = ingresarEntero();
    printf("Ingrese otro número entero positivo: ");
    num2 = ingresarEntero();
    if(controlMayorMenor(num1, num2)){
        printf("La suma de los numeros comprendidos entre %i y %i es igual a: %i\n", num1, num2, sumarPrimos(num1, num2));
    } else {
        aux = num1;
        num1 = num2;
        num2 =aux;
        printf("La suma de los numeros comprendidos entre %i y %i es igual a: %i\n", num1, num2, sumarPrimos(num1, num2));
    }
    return 0;
}

int ingresarEntero(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El número ingresado tiene que ser mayor a cero, ingrese un nuevo número: ");
    } while (numero <= 0);
    return numero;
}

int controlMayorMenor(int num1, int num2){
    if (num1 < num2){
        return 1;
    } else
        return 0;
}

int sumarPrimos(int num1, int num2){
    int sumaPrimos = 0;
    for (int i = num1 + 1; i < num2; i++){
        if (esPrimo(i))
            sumaPrimos += i;
    }
    return sumaPrimos;
}

int esPrimo(int numero){
    for (int i = 2; i < numero; ++i){
        if (numero % i == 0)
            return 0;  //en c, el cero es interpretado como falso y
    }                 //números distintos de cero se interpretan como verdadero
    return 1;         
}