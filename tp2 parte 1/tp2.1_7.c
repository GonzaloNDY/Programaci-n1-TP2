/*Escribir un programa que muestre el resultado de la ecuación de tercer grado y=ax^3+bx^2+cx+d
para un valor x. Para ello, debe leer el valor de los
coeficientes (a,b,c y d) y el valor de x, todos estos son valores enteros positivos .Mostrar
por pantalla el resultado de la evaluación de la ecuación resultante*/

#include <stdio.h>
#include <math.h>

int main( int argc, char*argv[]){
    float a, b, c, d, x;
    printf("\n\tPrograma para calcular ecuaciones de tercer grado (y = ax^3 + bx^2 + cx + d)\n");
    printf("\nA continuacion tendra que ingresar valores positivos para 'a', 'b', 'c' y 'd' \na: ");
    do {
        scanf("%f", &a);
        if (a <= 0)
            printf("Tiene que ingresar un valor positivo para el coeficiente 'a': ");
    } while (a <= 0);
    printf("b: ");
    do {
        scanf("%f", &b);
        if (b <= 0)
            printf("Tiene que ingresar un valor positivo para el coeficiente 'b': ");
    } while (b <= 0);
    printf("c: ");
    do {
        scanf("%f", &c);
        if (c <= 0)
            printf("Tiene que ingresar un valor positivo para el coeficiente 'c': ");
    } while (c <= 0);
    printf("d: ");
    do {
        scanf("%f", &d);
        if (d <= 0)
            printf("Tiene que ingresar un valor positivo para la constante 'd': ");
    } while (d <= 0);
    printf("", a, b, c, d);
    printf("Para poder resolver la ecuación tendrá que asignarle un valor a la variable 'x'\nx: ");
    do {
        scanf("%f", &x);
        if (x <= 0)
            printf("Tiene que ingresar un valor positivo para la variable 'x': ");
    } while (x <= 0);
    printf("El resultado de y = %0.fx^3 + %0.fx^2 + %0.fx + %0.f, con x = %.0f, es: y = %2.f\n", a, b, c, d, x, a*pow(x, 3)+b*pow(x, 2)+c*x+d);
    return 0;
}