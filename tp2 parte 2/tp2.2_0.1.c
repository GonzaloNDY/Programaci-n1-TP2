/*Implementar un programa que utilice una función para realizar una presentación de la materia,
por ejemplo:
"Programacion I"
"Anio de cursada: 2023"
"Facultad de Ciencias Exactas y Tecnología"
Usar secuencias de escape para salto de línea (\n) y tabulaciones (\t)*/

#include <stdio.h>

void presentacion();

int main(int argc, char*argv[]){
    presentacion();
    return 0;
}

void presentacion(){
    printf("\n\t\t   Programacion I\n\t\tAño de cursada: 2023\n\tFacultad de Ciencias Exactas y Tecnología\n");
}