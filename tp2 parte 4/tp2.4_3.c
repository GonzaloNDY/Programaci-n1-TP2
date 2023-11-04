/*Presentar por pantalla los N primeros números primos. Para esto utilice una función que
me devuelva el siguiente número primo, esta debe almacenar el anterior primo
mostrado en una variable estática.
int siguientePrimo();*/

#include <stdio.h>

int solicitarCantidad();
int siguientePrimo();

int main(int argc, char*argv[]){
    int cantidad;
    printf("\nIndique la cantidad de primos que se mostrarán en pantalla: ");
    cantidad = solicitarCantidad();
    printf("\nLos primeros %i numeros primos son:\n", cantidad);
    for (;cantidad > 0; cantidad--){
        printf("\t%i\n", siguientePrimo());
    }
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

int siguientePrimo(){
    static int primo = 1;
    int flag;
    do {
        flag = 1;
        primo++;
        for (int i = 2; i * i <= primo; i++){
            if (primo % i == 0)
                flag = 0;
        }
    } while (flag == 0);
    return primo;
}