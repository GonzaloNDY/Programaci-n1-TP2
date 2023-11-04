/*La empresa DATASYSTEM se encarga de realizar instalaciones de cableado estructurado. Desde la
gerencia se le pide al encargado de recursos humanos que informe cuál es el empleado que
tiene el menor salario para darle un aumento de sueldo del 10%.
Para ello se nos solicita realizar un programa en lenguaje C que permita encontrar entre los N
empleados de la empresa el de menor salario.
Para resolver implementar:
a- Solicitar al usuario que ingrese la cantidad de empleados que posee la empresa.
Mediante una función realizar el control de que la cantidad de empleados sea un valor entero
positivo.
b- Una función que permita almacenar los datos del empleado en un tipo de dato struct. El
mismo contendrá el legajo del empleado (número entero mayor que cero), la inicial del
apellido y el monto que recibe como salario (el mismo debe ser un valor positivo).
c- Una función que me permita encontrar el menor salario
d- Una función que permita proporcionarle al menor salario un aumento del 10%
e -Presentar por pantalla el menor sueldo con el aumento dado y sin el mismo*/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    int legajo;
    char apellido; //solo la inicial
    float salario;
} empleado;

float controlPositivo();
char ingresarCaracter();
empleado ingresoDatos();
void presentacion(float menorSalario);

int main(int argc, char*argv[]){
    int cantidad;
    empleado unEmpleado;
    float salarioMenor = 2147483647;

    printf("\nIndique la cantidad de empleados de la empresa: ");
    cantidad = controlPositivo();

    for (int i = 1; i <= cantidad; i++){
        printf("\n\tEmpleado %i\n", i);
        unEmpleado = ingresoDatos();
        if ( unEmpleado.salario < salarioMenor)
            salarioMenor = unEmpleado.salario;
    }

    presentacion(salarioMenor);

    return 0;
}

float controlPositivo(){
    float numero;

    do {
        scanf("%f", &numero);
        if (numero <= 0)
            printf("El valor ingresado tiene que ser mayor a cero, ingrese un nuevo valor: ");
    } while (numero <= 0);

    return numero;
}

char ingresarCaracter(){
    char caracter;
    do {
        scanf("%c", &caracter);
        if (!isalpha(caracter)){
            printf("El caracter ingresado no es una letra, intente nuevamente: ");
            fgetchar();
        }
    } while (!isalpha(caracter));
    return caracter;
}

empleado ingresoDatos(){
    empleado unEmpleado;

    printf("Legajo: ");
    unEmpleado.legajo = controlPositivo();  // La funcion controlpositivo retorna un float pero en estos casos se convierte en entero implicitamente
    fgetc(stdin);
    printf("Inicial del apellido: ");
    unEmpleado.apellido = ingresarCaracter();
    printf("Salario: ");
    unEmpleado.salario = controlPositivo();
    
    return unEmpleado;
}

void presentacion(float menorSalario){
    printf("--- El empleado con menor salario recibía %.2f antes del aumento. Despues del aumento recibirá %.2f---\n", menorSalario, menorSalario * 1.1);
}