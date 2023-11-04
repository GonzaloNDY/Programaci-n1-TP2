/* Definir un tipo struct que contenga los siguientes atributos:
typedef struct{
char automovil; //letra que representa al automovil
float tiempo;
}participante;
Emplear esta estructura para resolver el siguiente problema: En una carrera, en donde
compiten N automóviles, se registra una letra que identifica a cada automóvil y el
tiempo que demora en llegar a la meta.
Utilizar funciones diferentes para:
● Verificar que N sea un número entero positivo.
● Ingresar un participante, controlando que el tiempo sea un real positivo. (esta función no debe retornar valor).
● Determinar cuál es élautomóvil ganador, es decir el auto que llegó utilizando el
menor tiempo posible y en qué posición se lo ingresó, con una función con la
siguiente declaración:
void determinarGanador(participante *participanteIngresado, participante *ganador, int *posicionGanador);
● Para mostrar por pantalla al automóvil ganador. Utilizar funciones de conversión
de caracteres, presente la letra en mayúscula y el tiempo que este demoró en
llegar a la meta. Revisar ctype.h*/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    char automovil; //letra que representa al automovil
    float tiempo;
} participante;

float controlPositivo();
void ingresoParticipante(participante *unparticipante);
void determinarGanador(participante *participanteIngresado, participante *ganador, int *posicionGanador);
void mostrarGanador(participante ganador, int posicion);

int main(int argc, char *argv[]){
    participante unParticipante, participanteGanador;
    int cantidad, posicionGanador = 0;
    participanteGanador.tiempo = 2146474849;
    printf("Indique la cantidad de participantes que ingresará: ");
    cantidad = controlPositivo();
    printf("Ingrese los datos de los participantes:\n");
    for (; cantidad > 0; ++cantidad){
        ingresoParticipante(&unParticipante);
        determinarGanador(&unParticipante, &participanteGanador, &posicionGanador);
    }
    mostrarGanador(participanteGanador, posicionGanador);
    return 0;
}

float controlPositivo(){
    float num;
    do {
        scanf("%f", &num);
        if (num < 0)
            printf("El valor ingresado debe ser mayor a cero, intente nuevamente: ");
    } while (num < 0);
    return num;
}

void ingresoParticipante(participante *unparticipante){
    printf("Letra que representa al auto: ");
    scanf("%c", unparticipante->automovil);
    printf("Tiempo que tardó en llegar a la meta: ");
    unparticipante->tiempo = controlPositivo();
}

void determinarGanador(participante *participanteIngresado, participante *ganador, int *posicionGanador){
    if (participanteIngresado->tiempo < ganador->tiempo){
        *ganador = *participanteIngresado;
    }
    ++*posicionGanador;
}

void mostrarGanador(participante ganador, int posicion){
    printf("El participante ganador fue ingresado en la posiciòn %i\nLa letra que representa su auto es %c", posicion, ganador.automovil);
    printf("\nSu tiempo fue %.1f\n", ganador.tiempo);
}