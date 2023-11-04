/*Codificar un programa que solicite al usuario un número complejo en la forma binómica y lo
almacene en una estructura como el siguiente formato:
typdef struct {
float real;
float imaginario;
}complejo;
Luego mostrar por pantalla el mismo.
Para resolver este problema debe utilizar funciones que:
a)Permita solicitar al usuario un número complejo
b)Muestre un número complejo dado por pantalla con el siguiente formato: "El número
ingresado es a + b i" (esta función no es necesario que retorne valor)*/

#include <stdio.h>

typedef struct {
    float real;
    float imaginario;
}complejo;

complejo ingresarComplejo();
void mostrarComplejo(complejo);

int main(int argc, char*argv[]){
    printf("\n\tPrograma para ingresar y mostrar números complejos en forma binomica\n\n");
    mostrarComplejo(ingresarComplejo());
    return 0;
}

complejo ingresarComplejo(){
    complejo unComplejo;
    printf("Ingresar la parte real del número complejo:\t");
    scanf("%f", &unComplejo.real);
    printf("Ingresar la parte imaginaria del número complejo:\t");
    scanf("%f", &unComplejo.imaginario); 
    return unComplejo;
}

void mostrarComplejo(complejo unComplejo){
    printf("\nEl número ingresado es: %.1f + %.1fi\n", unComplejo.real, unComplejo.imaginario);
}