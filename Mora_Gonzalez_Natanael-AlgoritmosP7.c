#include <stdio.h>
#include <string.h>

void compressString(const char *word, char *comp) {
    int i = 0, count;
    char currentChar;
    char buffer[12]; // almacena longitud y carácter 
    comp[0] = '\0';  // Inicializa la cadena comprimida vacía

    while (word[i] != '\0') {
        currentChar = word[i];
        count = 0;

        // Contar la cantidad de repeticiones del carácter actual, con un límite de 9
        while (word[i] == currentChar && count < 9) {
            count++;
            i++;
        }//while

        // Construir la representación comprimida del segmento y agregarla al resultado
        snprintf(buffer, sizeof(buffer), "%d%c", count, currentChar);
        strcat(comp, buffer);
    }//while
}//compressString

int main() {
    char word[100];     // Entrada
    char comp[200];     // Salida comprimida

    // Pedimos al usuario la cadena de entrada
    printf("Ingresa la cadena a comprimir: ");
    scanf("%s", word);

    // Llamamos a la función de compresión
    compressString(word, comp);

    // Mostramos el resultado comprimido
    printf("Cadena original: %s\n", word);
    printf("Cadena comprimida: %s\n", comp);
    
    return 0;
}
