/*Se ponen a la venta entradas para un partido de fútbol internacional, cuyo precio
depende de la ubicación o tribuna, así:
○ Tribuna norte y sur cuesta 4000 pesos,
○ Tribuna este cuesta 5000 pesos y
○ Tribuna oeste cuesta 6500 pesos.
Se debe elaborar un programa que controle la venta de dichas entradas.
Se realizan N ventas, por cada venta se solicita cantidad de entradas a comprar y en qué
tribuna.
Se pide resolver utilizando funciones: :
● Controlar el ingreso de un número N positivo.
● Elaborar un menú para que el usuario elija en qué tribuna quiere comprar sus
entradas, y luego debe seleccionar la cantidad. Se recomienda usar la siguiente
definición de función
void ingresarVenta(tribunas *t);
● El porcentaje de personas que se ubicaron en la tribuna norte. El porcentaje se
mostrará en main y deberá ser obtenido haciendo uso de una función que no
retorne un valor.
● El monto total recaudado por la venta de todas las entradas
Se recomienda el uso de una estructura para ir almacenando la cantidad de entradas
vendidas en cada tribuna
typedef struct {
int tribunaNorte;
int tribunaSur;
int tribunaEste;
int tribunaOeste;
} tribunas;*/

#include <stdio.h>

typedef struct {
    int tribunaNorte;
    int tribunaSur;
    int tribunaEste;
    int tribunaOeste;
} tribunas;

int solicitarCantidad();
void ingresarVentas(int cantidad, tribunas *t);
void porcentajeTribunaN(tribunas t, float *porcentajeN);
void ventas(tribunas t, int *venta);

int main(int argc, char *argv[]){
    tribunas boletosTribunas;
    int cantidad, ventasTotales;
    float porcentajeNorte;
    boletosTribunas.tribunaEste = 0;
    boletosTribunas.tribunaNorte = 0;
    boletosTribunas.tribunaSur = 0;
    boletosTribunas.tribunaOeste = 0;
    printf("\nIndique la cantidad de entradas que se vendieron en total: ");
    cantidad = solicitarCantidad();
    ingresarVentas(cantidad, &boletosTribunas);
    porcentajeTribunaN(boletosTribunas, &porcentajeNorte);
    ventas(boletosTribunas, &ventasTotales);
    printf("El porcentaje de personas que se ubicaron en la tribuna norte es %c%.1f\n",'%', porcentajeNorte);
    printf("El monto total recaudado por la venta de todas las entradas fue $%i.00 pesos\n", ventasTotales);
    return 0;
}

int solicitarCantidad(){
    int numero;
    scanf("%i", &numero);
    while (numero <= 0){
        printf("El valor ingresado tiene que ser mayor a cero, ingrese un número positivo: ");
        scanf("%i", &numero);
    }
    return numero;
}

void ingresarVentas(int cantidad, tribunas *t){
    int boleto;
    for (int i = 1; i <= cantidad; ++i){
        printf("\n\tBoleto %i\nSeleccione el número de una de las siguientes opciones:\n1: Tribuna norte\t\t3: Tribuna este\n2: Tribuna sur\t\t\t4: Tribuna oeste", i);
        printf("\nOpción elegida: ");
        do {
            scanf("%i", &boleto);
            switch (boleto){
            case 1:
                ++t->tribunaNorte;
                break;
            case 2:
                ++t->tribunaSur;
                break;
            case 3:
                ++t->tribunaEste;
                break;
            case 4:
                ++t->tribunaOeste;
                break;
            default:
            printf("Opción inexistente, elija una de las 4 opciones disponibles: ");
            }
        } while (boleto <1 || boleto > 4);
    }
    
}

void porcentajeTribunaN(tribunas t, float *porcentajeN){
    *porcentajeN = t.tribunaNorte * 100 / (t.tribunaEste + t.tribunaNorte + t.tribunaOeste + t.tribunaSur);
}

void ventas(tribunas t, int *venta){
    *venta = 5000 * t.tribunaEste + 4000 * t.tribunaNorte + 6500 * t.tribunaOeste + 4000 * t.tribunaSur;
}