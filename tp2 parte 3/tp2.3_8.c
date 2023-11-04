/*Codificar un programa que solicite los datos de N usuarios y los almacene en una
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
Debe mostrar por pantalla: a , T, P
Para ello usar funciones para:
● int solicitarCantidad(): solicita el ingreso de N y controla que sea positivo, en caso
contrario volver a solicitarlo.
● Ingresar a cada persona. Esta función debe cumplir con la siguiente declaración:
usuario ingresarUsuario();
● Mostrar los nombres de cada persona segun fueron ingresados en mayúsculas si su dni
es un número par y en minúscula si su dni es un número impar. Esta función debe
cumplir con la siguiente declaración: void mostrarInicial(usuario user);*/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    char nombre; //almacenar sólo la inicial
    int dni;
} usuario;

int solicitarCantidad();
usuario ingresarUsuario();
int esPar(int num);
void mostrarInicial(usuario user);

int main(int argc, char*argv[]){
    int cantidad;
    printf("\nIndique la cantidad de usuarios que se ingresaran: ");
    cantidad = solicitarCantidad();
    printf("\nDatos de los usuarios:\n");
    for (int i = 1; i <= cantidad; i++){
        printf("\n\tUsuario %i\n", i);
        mostrarInicial(ingresarUsuario());
    }
    return 0;
}

int solicitarCantidad(){
    int numero;
    do {
        scanf("%i", &numero);
        if (numero <= 0)
            printf("El valor ingresado tiene que ser mayor a cero, ingrese un nuevo valor: ");
    } while (numero <= 0);
    return numero;
}

usuario ingresarUsuario(){
    usuario unUsuario;
    printf("Inicial del nombre: ");
    do {
        fgetc(stdin);
        scanf("%c", &unUsuario.nombre);
        if (!isalpha(unUsuario.nombre))
            printf("La inicial del nombre tiene que ser un caracter alfabetico, ingresela nuevamente: ");
    } while (!isalpha(unUsuario.nombre));
    printf("DNI: ");
    scanf("%i", &unUsuario.dni);
    return unUsuario;
}

int esPar(int num){
    if(num % 2 == 0 && num != 0){
        return 1;
    } else
        return 0;
}

void mostrarInicial(usuario user){
    if (esPar(user.dni))
        printf("--- %c ---\n", toupper(user.nombre));
    else
        printf("--- %c ---\n", tolower(user.nombre));
}