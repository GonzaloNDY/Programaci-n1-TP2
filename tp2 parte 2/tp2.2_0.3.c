/*Ingresar, en una variable tipo estructura, los datos referentes a una fecha (día, mes, año). Luego
usar una función para presentar por pantalla el contenido de dicha variable con el siguiente
formato "la fecha ingresada es 5-4-1996"(dónde 5 corresponde a los días, 4 a los meses y 1996 a
los años).
Usar la siguiente estructura para la fecha
typedef struct {
int dia;
int mes;
int anio;
}fecha;  */

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int anio;
}fecha;

void mostrarFecha(fecha fechaActual);

int main(int argc, char*argv[]){
    fecha unaFecha;
    printf("\n\tPrograma para mostrar fechas\nIngrese el dia: ");
    do {
        scanf("%i", &unaFecha.dia);
        if (unaFecha.dia <1 || unaFecha.dia > 31)
            printf("Ingrese un dia existente: ");
    } while (unaFecha.dia <1 || unaFecha.dia > 31);
    printf("Ingrese el mes: ");
    do {
        scanf("%i", &unaFecha.mes);
        if (unaFecha.mes <1 || unaFecha.mes > 12)
            printf("Ingrese un mes existente: ");
    } while (unaFecha.mes <1 || unaFecha.mes > 12);
    printf("Ingrese el año: ");
    do {
        scanf("%i", &unaFecha.anio);
        if (unaFecha.anio <1)
            printf("Ingrese un año existente: ");
    } while (unaFecha.anio <1);
    mostrarFecha(unaFecha);
    return 0;
}

void mostrarFecha(fecha fechaActual){
    printf("\n\tLa fecha ingresada es %i - %i - %i\n", fechaActual.dia, fechaActual.mes, fechaActual.anio);
}