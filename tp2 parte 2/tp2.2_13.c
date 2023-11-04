/*Codificar un programa en el que se solicita el ingreso del peso y la talla de N personas, utilizando
una estructura para contener peso y talla. Debe mostrar por pantalla cuál es la persona que
tiene mayor peso y talla. Para resolver debe emplear una función que use parámetros por valor
tipo estructura y que retorne una estructura*/

#include <stdio.h>

typedef struct{
    float peso;
    float talla;
} medidas;

int controlPositivo();
medidas ingresarMedidas();
medidas controlMedidas(medidas persona, medidas medidaMayor);

int main(float argc, char*argv[]){
    medidas mayorMedida;
    mayorMedida.peso = -2147483647;
    mayorMedida.talla = -2147483647;
    int cantidad;
    printf("\nIndique la cantidad de personas a controlar: ");
    cantidad = controlPositivo();
    for (int i = 1; i <= cantidad; i++){
        printf("\n\tTalla y peso de la persona %i\n", i);
        mayorMedida = controlMedidas(ingresarMedidas(), mayorMedida);
    }
    printf("\nLa persona con mayor peso mide %.1f kilos\nLa persona con mayor altura mide %.1f centimetros\n", mayorMedida.peso, mayorMedida.talla);
    return 0;
}

int controlPositivo(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El valor ingresado tiene que ser mayor a cero, ingrese un nuevo valor: ");
    } while (numero <= 0);
    return numero;
}

medidas ingresarMedidas(){
    medidas persona;
    printf("Talla (en cm.): ");
    persona.talla = controlPositivo();
    printf("Peso (en kg.): ");
    persona.peso = controlPositivo();
    return persona;
}

medidas controlMedidas(medidas persona, medidas medidaMayor){
    if (persona.peso > medidaMayor.peso){
        medidaMayor.peso = persona.peso;
    }
    if (persona.talla > medidaMayor.talla){
        medidaMayor.talla = persona.talla;
    }
    
    return medidaMayor;
}