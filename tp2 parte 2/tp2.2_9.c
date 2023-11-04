/*Codificar un programa en el que se solicita el ingreso de un carácter alfabético, luego presentar
por pantalla el carácter en mayúscula si el mismo fue ingresado en minúscula y viceversa. Para
resolver este ejercicio deberá implementar:
a- una función para ingresar el carácter y controlar que sea alfabético.
b- una función para devolver el carácter convertido
c-una función para mostrar por pantalla el caracter convertido(esta función no es
necesario que retorno valor)*/

char ingresarCaracter();
void mostrarTipoCaracter(char caracter);

int main(int argc, char*argv[]){
    printf("\nIngresar una letra (no se tomarán a la \"ñ\" o \"Ñ\" como letras): ");
    mostrarTipoCaracter(convertirCaracter(ingresarCaracter()));
    return 0;
}

char ingresarCaracter(){
    char caracter;
    do {
        scanf("%c", &caracter);
        if (!isalpha(caracter)){
            printf("El caracter ingresado no es una letra, ingrese un nuevo caracter: ");
            fgetchar();
        }
    } while (!isalpha(caracter));
    return caracter;
}

char convertirCaracter(char caracter){
    if (isupper(caracter)){
        caracter = tolower(caracter);
    } else {
        caracter = toupper(caracter);
    }
    return caracter;
}

void mostrarTipoCaracter(char caracter){
    printf("El caracter ingresado y convertido a mayuscula/minuscula es: \"%c\"", caracter);
}