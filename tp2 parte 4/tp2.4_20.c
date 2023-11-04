/*Un proveedor de tecnología, registra sus ventas diarias en un sistema diseñado para
solicitar DNI del cliente, monto de la venta y el medio de pago de la misma ('t' para
tarjeta de crédito o débito, 'e' para pago en efectivo y 'c' para cuenta corriente).
Almacenar la venta en un dato tipo estructura con el siguiente formato:
typedef struct {
    int dni;
    float monto;
    char medio_pago;
} venta;
La carga de ventas diarias finaliza al ingresar el caracter F
Al finalizar cada día el encargado necesita saber:
○ El total por cada medio de pago y el total vendido en el dia. El sistema debe
mostrar en la función principal los distintos totales. Para esto realizar la siguiente
función:
float totalVenta( venta *v, float totalT,float *totalE, float *totalC);
○ El importe de venta más alto y a que cliente perteneció.
El sistema debe comparar cada vez que se ingresa una venta, si es la mayor venta
ingresada, para poder mostrarla al final del ingreso. Realizar la siguiente función:
void ventaMayor(venta ventaIngresada, venta *ventaMayor);
○ El porcentaje de ingresos que representa cada condición, esto el sistema se lo
muestra en la función principal con una función que no retorna valor y que tiene
la siguiente declaración: void porcentajes(float total, float individual, float
*porcentaje);*/

#include <stdio.h>

typedef struct {
    int dni;
    float monto;
    char medio_pago;  //t = tarjeta, e = efectivo, c = cuenta corriente
} venta;

float totalVenta( venta *v, float totalT,float *totalE, float *totalC);
void ventaMayor(venta ventaIngresada, venta *ventaMayor);
void porcentajes(float total, float individual, float *porcentaje);

int main(int argc, char *argv[]){
    venta ventaDiaria, mayorVenta;
    char finalizar;
    float totalT = 0, totalE = 0, totalC = 0, totalVentas, porcentajeT, porcentajeE, porcentajeC;
    mayorVenta.monto = -2746474849;
    printf("\n\tIngrese los datos de las ventas diarias\n\n");
    do {
        totalT = totalVenta(&ventaDiaria, totalT, &totalE, &totalC);
        ventaMayor(ventaDiaria, &mayorVenta);
        printf("Presione \"F\" para finalizar el programa, presione otra letra para continuar: ");
        fgetc(stdin);
        scanf("%c", &finalizar);
    } while (finalizar != 'F');
    totalVentas = totalC + totalE + totalT;
    porcentajes(totalVentas, totalC, &porcentajeC);
    porcentajes(totalVentas, totalE, &porcentajeE);
    porcentajes(totalVentas, totalT, &porcentajeT);
    printf("\nLa mayor venta fue la realizada al cliente de dni: %i, por un monto de $%.2f\n", mayorVenta.dni, mayorVenta.monto);
    printf("Las ventas totales fueron de $%.2f\n", totalVentas);
    printf("El porcentaje de ventas con tarjeta de credito es %c%.3f\n", '%', porcentajeT);
    printf("El porcentaje de ventas con dinero en efectivo es %c%.3f\n", '%',porcentajeE);
    printf("El porcentaje de ventas con cuenta corriente es %c%.3f\n", '%', porcentajeC);
    return 0;
}

float totalVenta( venta *v, float totalT,float *totalE, float *totalC){
    static int contador = 1;
    printf("\nDNI del cliente nro %i: ", contador);
    scanf("%i", &v->dni);
    printf("Monto total de la venta nro %i: ", contador);
    scanf("%f", &v->monto);
    do{
        fgetc(stdin);
        printf("Medio de pago (E: efectivo, C = cuenta corriente, T: tarjeta): ");
        scanf("%c", &v->medio_pago);
    }while(v->medio_pago != 't' && v->medio_pago != 'e' && v->medio_pago != 'c' && v->medio_pago != 'T' && v->medio_pago != 'E' && v->medio_pago != 'C');
    if (v->medio_pago == 't' || v->medio_pago == 'T'){
        totalT += v->monto;
    } else if (v->medio_pago == 'e' || v->medio_pago == 'E'){
        *totalE = *totalE + v->monto;
    } else {
        *totalC = *totalC + v->monto;
    }
    contador++;
    return totalT;
}

void ventaMayor(venta ventaIngresada, venta *ventaMayor){
    if (ventaIngresada.monto > ventaMayor->monto)
        *ventaMayor = ventaIngresada;
}

void porcentajes(float total, float individual, float *porcentaje){
    *porcentaje = individual * 100 / total;
}