/*Una materia solicitó a la cátedra crear un bolillero para sorteo de temas en exámenes,
para cumplir con este pedido se debe desarrollar un programa que genere un número
aleatorio entre dos valores enteros positivos a y b, los cuales hacen referencia al rango
de números de temas que entran en el sorteo. Se pide ingresar el rango de temas en la
variables a - b y mostrar el tema que salió en el sorteo. Por ejemplo:
Tema a = 2 , b=10 , implican en el sorteo entran los temas desde el 2 al 10 inclusive. Al
generar un número aleatorio el mismo debe estar contenido entre esos valores*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char*argv[]){
    int temaA, temaB, control, contador = 1;
    srand(time(NULL));
    printf("\n\tPrograma para sortear temas de exámenes\n");
    do {
        printf("\nA continuación tendrá que indicar el rango para el sorteo nº %i (desde \"a\" hasta \"b\")\na: ", contador);
        do{
            if (scanf("%i", &temaA) != 1)   //verifica que se ingrese un número entero válido
                printf("Entrada inválida. Intente de nuevo (\"a\" tiene que ser un número): ");
                getchar();
                continue;
        } while (scanf("%i", &temaA) != 1);
        printf("b: ");
        do {
            if (scanf("%i", &temaB) != 1)   //verifica que se ingrese un número entero válido
                printf("Entrada inválida. Intente de nuevo (\"b\" tiene que ser un número): ");
                getchar();
                continue;
            if (temaB <= temaA)
                printf("\"b\" tiene que ser mayor que \"a\" ingrese un nuevo valor para \"b\": ");
        } while (scanf("%i", &temaB) != 1 || temaB <= temaA);
        printf("Tema otorgado aleatoriamente:\n-------- %i --------\n", rand() % temaB + temaA);
        printf("Para finalizar el programa ingrese \"0\", para realizar otro sorteo ingrese cualquier número: ");
        if (scanf("%i", &control) != 1){
            printf("Entrada inválida. Finalizando el programa\n");
            break;
        }
        contador++;
    } while (control != 0);
    return 0;
}