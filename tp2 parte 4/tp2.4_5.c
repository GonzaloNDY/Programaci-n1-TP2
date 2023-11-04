/*Se ingresan N números enteros. Determinar el mayor de los valores ingresados.
Ejemplo: N = 7, Se ingresan: -12, 5, -8, 30, 0, -20, 15
Mayor valor: 30.
Controlar que el valor de N sea positivo. Usar una función que emplee variables static
para encontrar el mayor. Verificar también el resultado si ingreso todos números
negativos*/


#include <stdio.h>

int solicitarCantidad();
int controlMayorNum();

int main(int argc, char *argv[]){
    int cantidad, mayorNum, bandera = 0;
    printf("\nIndique la cantidad de números a controlar: ");
    cantidad = solicitarCantidad();
    printf("Ingrese los números a controlar:\n");
    for (;cantidad > 0; cantidad--){
        mayorNum = controlMayorNum();
        if (mayorNum >= 0){
            bandera = 1;
        }
    }
    if (bandera == 0){
        printf("Todos los números ingresados fueron negativos. ");
    }
    printf("El mayor número ingresado es: %i\n", mayorNum);
    
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

int controlMayorNum(){
    static int numMayor = -2147483648;
    int num;
    scanf("%i", &num);
    if (numMayor < num){
        numMayor = num;
    }
    return numMayor;
}