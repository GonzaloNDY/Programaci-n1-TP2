/*Utilizando las funciones diseñadas en el ejercicio anterior, codificar un programa en el que se
solicita el ingreso de dos números complejos y muestre la suma de ambos. Para esto deberá
ingresar parte real y parte imaginaria de la forma binómica en una variable tipo estructura para
cada número complejo, luego utilizar otra función para calcular la suma de los mismos, además
debe retornar el resultado utilizando una variable tipo estructura. Presentar por pantalla los
números ingresados y el resultado*/

#include <stdio.h>

typedef struct {
    float real;
    float imaginario;
}complejo;

complejo ingresarComplejo();
complejo sumaComplejos(complejo, complejo);
void mostrarComplejo(complejo);

int main(int argc, char*argv[]){
    complejo unComplejo, otroComplejo;
    printf("\nPrograma para ingresar y sumar 2 números complejos\n");
    printf("\nA continuacion tendrá que ingresar los números complejos a sumar\n");
    printf("\n----- Primer número -----\n");
    unComplejo = ingresarComplejo();
    printf("\n----- Segundo número -----\n");
    otroComplejo = ingresarComplejo();
    printf("\nLa suma de ambos números es: ");
    mostrarComplejo(sumaComplejos(unComplejo, otroComplejo));
    printf("\nPrimer número complejo ingresado:  ");
    mostrarComplejo(unComplejo);
    printf("Segundo número complejo ingresado:  ");
    mostrarComplejo(otroComplejo);
    return 0;
}

complejo ingresarComplejo(){
    complejo numComplejo;
    printf("Ingresar la parte real: ");
    scanf("%f", &numComplejo.real);
    printf("Ingresar la parte imaginaria: ");
    scanf("%f", &numComplejo.imaginario); 
    return numComplejo;
}

complejo sumaComplejos(complejo complejo1, complejo complejo2){
    complejo sumaComplejo;
    sumaComplejo.real = complejo1.real + complejo2.real;
    sumaComplejo.imaginario = complejo1.imaginario + complejo2.imaginario;
    return sumaComplejo;
}

void mostrarComplejo(complejo unComplejo){
    printf("%.1f + %.1f i\n", unComplejo.real, unComplejo.imaginario);
}