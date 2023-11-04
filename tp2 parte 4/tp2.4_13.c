/*(Referencia ejercicio 12 del TP2-Parte 2) Implementar un programa que permita determinar
si un medicamento se encuentra o no vencido, conociendo la fecha de vencimiento y la fecha
actual. Para resolver este ejercicio deberá:
○ Usar del ejercicio (Referencia ejercicio 11 del TP2-Parte 2) las funciones para leer una
fecha y controlar su validez.
○ Implementar una función que determine si el medicamento está vencido y que presente
por pantalla el mensaje correspondiente. (esta función no debe retornar un valor)
Almacenar la fecha en un dato tipo estructura con el siguiente formato:
typedef struct{
    int dia;
    int mes;
    int anio;
} fecha;*/

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} fecha;

fecha ingresoFecha();
void controlFecha(fecha *fechaControlada);
void caducidadDeMedicamento(fecha, fecha);

int main(int argc, char *argv[]){
    fecha fechaActual, fechaMedicamento;
    printf("\n\tPrograma para determinar la caducidad de un medicamento\n\nIngrese la fecha actual\n");
    fechaActual = ingresoFecha();
    controlFecha(&fechaActual);
    printf("\nIngrese la fecha de caducidad del medicamento\n");
    fechaMedicamento = ingresoFecha();
    controlFecha(&fechaMedicamento);
    caducidadDeMedicamento(fechaActual, fechaMedicamento);
    return 0;
}

fecha ingresoFecha(){
    fecha fechaIngresada;
    printf("Dia: ");
    scanf("%i", &fechaIngresada.dia);
    printf("Mes: ");
    scanf("%i", &fechaIngresada.mes);
    printf("Año: ");
    scanf("%i", &fechaIngresada.anio);
    return fechaIngresada;
}

void controlFecha(fecha *fechaControlada){
    int diasPorMes;
    //control de año:
    if (fechaControlada->anio < 1900){
        do {
            printf("Ingrese un año válido (tiene que ser mayor a 1900): ");
            scanf("%i", &fechaControlada->anio);
        } while (fechaControlada->anio < 1900);
    }
    //control de mes:
    if (fechaControlada->mes < 1 || fechaControlada->mes > 12){
        do {
            printf("Ingrese un mes valido: ");
            scanf("%i", &fechaControlada->mes);
        } while (fechaControlada->mes < 1 || fechaControlada->mes > 12);
    }
    //control de dias:
    switch (fechaControlada->mes){
        case 1:  //Enero
        case 3:  //Marzo
        case 5:  //Mayo
        case 7:  //Julio
        case 8:  //Agosto
        case 10: //Octubre    
        case 12: //Diciembre
            diasPorMes = 31;
            break;
        case 4:  //Abril
        case 6:  //Junio
        case 9:  //Septiembre
        case 11: //Noviembre
            diasPorMes = 30;    
            break;
        case 2:  //Febrero
            if (fechaControlada->anio % 400 == 0 && fechaControlada->anio % 4 == 0){
                diasPorMes = 29;
            } else {
                diasPorMes = 28;
            }
            break;
    }
    if (fechaControlada->dia <1 || fechaControlada->dia > diasPorMes){
        do {
            printf("Ingrese un dia válido: ");
            scanf("%i", &fechaControlada->dia);
        } while (fechaControlada->dia < 1 || fechaControlada->dia > diasPorMes);
    }
}

void caducidadDeMedicamento(fecha fechaActual, fecha fechaAcontrolar){
    if (fechaAcontrolar.anio < fechaActual.anio){
        printf("\n\tEl medicamento esta vencido\n");
    } else if (fechaAcontrolar.anio == fechaActual.anio){
        if (fechaAcontrolar.mes < fechaActual.mes){
            printf("\n\tEl medicamento esta vencido\n");
        } else if (fechaAcontrolar.mes == fechaActual.mes){
            if (fechaAcontrolar.dia <= fechaActual.dia){
                printf("\n\tEl medicamento esta vencido\n");
            } else {
                printf("\n\tEl medicamento aun no esta vencido\n");
            }
        } else {
            printf("\n\tEl medicamento aun no esta vencido\n");
        }
    } else {
        printf("\n\tEl medicamento aun no esta vencido\n");
    }
}