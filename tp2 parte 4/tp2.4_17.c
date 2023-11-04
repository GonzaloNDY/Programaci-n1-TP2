/*De un grupo de N personas se debe registrar el peso, altura y edad. Realizar un programa
que permita calcular el peso promedio, altura promedio y la edad promedio.
Utilizar funciones para:
● Verificar que N sea un número entero positivo.
● Ingresar las personas y controlar que sus atributos sean números positivos
● Calcular el promedio del peso, la altura y la edad.
Presentar por pantalla los resultados. Utilizar parámetros por valor y por referencia y
variables static si considera necesario.
Usar la siguiente estructura para almacenar la información de cada persona:
typedef struct {
float peso;
float altura;
int edad;
} persona;*/

#include <stdio.h>

typedef struct {
    float peso;
    float altura;
    int edad;
} persona;

int solicitarCantidad();
persona ingresoYcontrolPersonas();
void calcularPromedios(persona unaPersona, persona *promedio, int cantidad);

int main(int argc, char*argv[]){
    persona unaPersona, medidaPromedio;
    int cantidad;

    medidaPromedio.altura = 0;
    medidaPromedio.peso = 0;
    medidaPromedio.edad = 0;

    printf("\nIndique la cantidad de personas que registrará: ");
    cantidad = solicitarCantidad();

    printf("Ingrese los datos de las personas a controlar:\n");
    for (int i = 1; i <= cantidad; i++){
        printf("\n  Persona %i\n", i);
        unaPersona = ingresoYcontrolPersonas();
        calcularPromedios(unaPersona, &medidaPromedio, cantidad);
    }

    printf("\nA continuacion se presentan los promedios de los distintos datos ingresados:\nAltura: %.1f\nPeso: %.1f\nEdad: %i\n", medidaPromedio.altura, medidaPromedio.peso, medidaPromedio.edad);
    
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

persona ingresoYcontrolPersonas(){
    persona unaPersona;

    printf("Peso (en Kg.): ");
    unaPersona.peso = solicitarCantidad() * 1.0;

    printf("Altura (en cm.): ");
    unaPersona.altura = solicitarCantidad() * 1.0;

    printf("Edad: ");
    unaPersona.edad = solicitarCantidad();

    return unaPersona;
}

void calcularPromedios(persona unaPersona, persona *promedio, int cantidad){
    static int contador;

    promedio->altura += unaPersona.altura;
    promedio->edad +=  unaPersona.edad;
    promedio->peso += unaPersona.peso;

    contador++;
    
    if (contador == cantidad){
        promedio->altura /= cantidad;
        promedio->peso /= cantidad;
        promedio->edad /= (cantidad * 1.0);
    }
}