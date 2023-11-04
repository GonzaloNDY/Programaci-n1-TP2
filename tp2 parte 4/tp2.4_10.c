/*Referencia ejercicio 2 del TP2-Parte 2).Definir un tipo struct que tenga dos campos, uno
para contener la parte real y otro la parte imaginaria de un número complejo:
typedef struct{
    float real;
    float imaginario;
} complejo;
Emplear esta estructura para solicitar al usuario el ingreso de dos números complejos,
realizar la suma de los mismos. Al finalizar los cálculos deberá presentar por pantalla los
números complejos ingresados, la suma de dichos números. Para resolver deberá
implementar funciones que empleen parámetros por referencia (y por valor si fuese
necesario):
● Una función para solicitar al usuario el ingreso de un número complejo
● Una función para presentar por pantalla un número complejo dado
● Una función para calcular la suma de dos números complejos dados.
Ninguna de las funciones debe retornar valor*/

#include <stdio.h>

typedef struct{
    float real;
    float imaginario;
} complejo;

complejo ingresoNumComplejo();
void presentarComplejo(complejo unComplejo);
void sumaComplejos(complejo complejo1, complejo complejo2, complejo *sumaComplejos);

int main(int argc, char *argv[]){
    complejo unComplejo, otroComplejo, suma;
    printf("\nIngrese el primer número imaginario\n");
    unComplejo = ingresoNumComplejo();
    presentarComplejo(unComplejo);
    printf("\nIngrese el segundo número imaginario\n");
    otroComplejo = ingresoNumComplejo();
    presentarComplejo(otroComplejo);
    sumaComplejos(unComplejo, otroComplejo, &suma);
    printf("La suma de los complejos anteriormente ingresados es %.1f + %.1fi\n", suma.real, suma.imaginario);
    return 0;
}

complejo ingresoNumComplejo(){
    complejo unComplejo;
    printf("Parte real: ");
    scanf("%f", &unComplejo.real);
    printf("Parte imaginaria: ");
    scanf("%f", &unComplejo.imaginario);
    return unComplejo;
}

void presentarComplejo(complejo unComplejo){
    printf("El complejo ingresado es: %.1f + %.1fi\n", unComplejo.real, unComplejo.imaginario);
}

void sumaComplejos(complejo complejo1, complejo complejo2, complejo *sumaComplejos){
    sumaComplejos->real = complejo1.real + complejo2.real;
    sumaComplejos->imaginario = complejo1.imaginario + complejo2.imaginario;
}