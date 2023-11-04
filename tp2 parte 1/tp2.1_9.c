/*Codificar un programa en el que se solicita el ingreso de N carácteres, luego presentar
por pantalla un mensaje que indique cuántos carácteres son dígitos, cuántos son letra
del alfabeto en mayúscula, cuántos son letra del alfabeto en minúscula o de otro tipo de
carácter*/

#include <stdio.h>
#include <ctype.h>

int main (int argc, char*argv[]){
    int cantCaracteres, cantNum = 0, cantLetraMayus = 0, cantLetraMinus = 0, cantSignos = 0;
    char caracter;
    printf("\nIndique la cantidad de caracteres que ingresará:\t");
    do {
        scanf("%i", &cantCaracteres);
        if (cantCaracteres <= 0){
            printf("Tiene que ser un valor mayor a cero, ingrese una cantidad válida:\t");
        }
    } while (cantCaracteres <= 0);
    
    printf("Ingrese los caracteres:\n");
    do {
        fgetc(stdin);
        scanf("%c", &caracter);
        if (isdigit(caracter))
            cantNum++;
        else if (isupper(caracter))
            cantLetraMayus++;
        else if (islower(caracter))
            cantLetraMinus++;
        else {
            cantSignos++;
        }
        cantCaracteres--;
    } while (cantCaracteres > 0);
    printf("Se ingresaron %i números, %i letras mayúsculas, %i letras minúsculas y %i signos/símbolos\n", cantNum, cantLetraMayus, cantLetraMinus, cantSignos);
    return 0;
}