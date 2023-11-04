/* Codificar un programa que solicite los datos de N usuarios y lo almacene en una
estructura como el siguiente formato:
typdef struct {
char nombre; //almacenar sólo la inicial
int dni;
}usuario;
Mostrar por pantalla los nombres de los usuarios que fueron ingresados en mayúsculas
si su dni es un número par y en minúscula si su dni es un número impar. Por ejemplo se
ingresan 3 usuarios:
Usuario: a - DNI: 145823
Usuario: t - DNI: 7845152
Usuario: P - DNI: 748452
Debe mostrar por pantalla: a , T, P*/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    char nombre; //almacenar sólo la inicial
    int dni;
}usuario;

int main (int argc, char*argv[]){
    usuario usuarioActual;
    int cantUsuarios, contador = 1;
    printf("Indique la cantidad de usuarios de usuarios que registrará: ");
    // Ciclo para verificar que se ingrese una cantidad de usuarios válida:
    do {
        if (scanf("%i", &cantUsuarios) != 1) {  // Verifica que se ingrese una cantidad válida y en formato entero
            printf("Entrada inválida. Intente de nuevo (la cantidad tiene que ser un número mayor a cero): ");
            getchar();
            continue;
        }
        if (cantUsuarios <= 0) {
            printf("Tiene que ser un valor mayor a cero, ingrese una cantidad válida:\t");
            continue;
        }
        break;
    } while (1);
    // Ciclo para pedir y verificar la validez de los datos de cada usuario:
    do {
        fgetc(stdin);
        //Inicial del nombre:
        printf("\n\tUsuario %i\nInicial del nombre:\t", contador);
        do {
            scanf("%c", &usuarioActual.nombre);
            if (!isalpha(usuarioActual.nombre)){
                fgetc(stdin);
                printf("Debe ingresar un caracter alfabetico como inicial del nombre. Intente de nuevo: ");
                continue;
            }
            break;
        } while (!isalpha(usuarioActual.nombre));
        //DNI:
        printf("DNI: ");
        do {
            if (scanf("%i", &usuarioActual.dni) != 1){   
                printf("Ingrese un DNI válido:\t");
                getchar();
                continue;
            } 
            if (usuarioActual.dni < 10000000 || usuarioActual.dni > 99999999){
                printf("Ingrese un DNI válido:\t");
                continue;
            }
            break;
        } while (1);
        if (usuarioActual.dni % 2 == 0)
            printf("El DNI es un número par, se mostrará la inicial del nombre en mayusculas:\n%c\n", toupper(usuarioActual.nombre));
        else {
            printf("El DNI es un número impar, se mostrará la inicial del nombre en minusculas:%c\n", tolower(usuarioActual.nombre));
        }
        contador++;
    } while (cantUsuarios >= contador);
    return 0;
}