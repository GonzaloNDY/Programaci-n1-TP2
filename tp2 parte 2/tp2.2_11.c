/* Implementar un programa que permita determinar si una fecha es válida, para esto :
a- Implementar una función permita el ingreso de una fecha y que retorne la misma al
programa principal.
b- Implementar una función para controlar la validez de la fecha: día entre 1 y 31, mes
entre 1 y 12, año mayor a 1900. Puede además controlar para cada mes la cantidad de
días que corresponden.
c- Implementar una función para mostrar una fecha con el formato dd/mm/aaaa, por
ejemplo 10/4/2022.
Almacenar la fecha en un dato tipo estructura con el siguiente formato:
typdef struct{
int dia;
int mes;
int anio;
}fecha;  */

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} fecha;

fecha ingresoFecha();
fecha controlFecha(fecha fechaAcontrolar);
void mostrarFecha(fecha fechaAmostrar);

int main(int argc, char*argv[]){
    fecha unaFecha;
    printf("\n\tPrograma para ingresar y mostrar una fecha\n");
    unaFecha = controlFecha(ingresoFecha());
    mostrarFecha(unaFecha);
    return 0;
}

fecha ingresoFecha(){
    fecha fechaIngresada;
    printf("\nA continuacion, ingrese una fecha\nDia: ");
    scanf("%i", &fechaIngresada.dia);
    printf("Mes: ");
    scanf("%i", &fechaIngresada.mes);
    printf("Año: ");
    scanf("%i", &fechaIngresada.anio);
    return fechaIngresada;
}

fecha controlFecha(fecha fechaAcontrolar){
    fecha fechaControlada;
    int diasPorMes;
    fechaControlada = fechaAcontrolar;

    // Control del año:
    while (fechaControlada.anio < 1900){
        printf("Ingrese un año válido (tiene que ser mayor a 1900): ");
        scanf("%i", &fechaControlada.anio);
    }

    // Control del mes:
    while (fechaControlada.mes < 1 || fechaControlada.mes > 12){
        printf("Ingrese un mes valido: ");
        scanf("%i", &fechaControlada.mes);
    }

    // Control del dia:
    switch (fechaControlada.mes){
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
            if (fechaControlada.anio % 400 == 0 && fechaControlada.anio % 4 == 0){
                diasPorMes = 29;
            } else {
                diasPorMes = 28;
            }
            break;
    }

    while (fechaControlada.dia <1 || fechaControlada.dia > diasPorMes){
        printf("Ingrese un dia válido: ");
        scanf("%i", &fechaControlada.dia);
    }

    return fechaControlada;
}

void mostrarFecha(fecha fechaAmostrar){
    printf("\t\tLa fecha ingresada y validada es: %i/%i/%i\n", fechaAmostrar.dia, fechaAmostrar.mes, fechaAmostrar.anio);
}