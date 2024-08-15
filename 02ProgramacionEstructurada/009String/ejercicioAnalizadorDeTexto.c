#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_LENGTH_SENTENCE 10000

void encNumPal(char *sentence, int *wordCount) {
    char delimitador[] = " ,¿?¡!.:\n";
    char sentenceCopy[MAX_LENGTH_SENTENCE];
    strcpy(sentenceCopy, sentence);
    char *token = strtok(sentenceCopy, delimitador);

    while (token != NULL) {
        (*wordCount)++;
        token = strtok(NULL, delimitador);
    }
}

void encPalLarg(char *sentence, char *longestWord) {
    char delimitador[] = " ,¿?¡!.:\n";
    char sentenceCopy[MAX_LENGTH_SENTENCE];
    strcpy(sentenceCopy, sentence);
    char *token = strtok(sentenceCopy, delimitador);
    int tokenLength;
    int tokenLengthBef = 0;

    while (token != NULL) {
        tokenLength = strlen(token);
        if (tokenLength > tokenLengthBef) {
            strcpy(longestWord, token);
            tokenLengthBef = tokenLength;
        }
        token = strtok(NULL, delimitador);
    }
}

void buscPal(char *sentence, char *wordToFind, int *found) {
    char delimitador[] = " ,¿?¡!.:\n";
    char sentenceCopy[MAX_LENGTH_SENTENCE];
    strcpy(sentenceCopy, sentence);
    char *token = strtok(sentenceCopy, delimitador);
    int resultado;

    *found = 0;

    while (token != NULL) {
        resultado = strcasecmp(wordToFind, token);
        if (resultado == 0) {
            *found = 1;
            break;
        }
        token = strtok(NULL, delimitador);
    }
}

int main() {
    char sentence[MAX_LENGTH_SENTENCE] = "Ser o no ser, esa es la cuestión: ¿Qué es más noble para el alma? ¿Sufrir los golpes y dardos de la ultrajante fortuna o tomar las armas contra un mar de adversidades, y, haciéndoles frente, acabar con ellas? Morir es dormir; no más; y con el sueño decir que terminamos el dolor del corazón y los mil quebrantos que heredan la carne: ¡es un fin devotamente apetecible! Morir es dormir: dormir, tal vez soñar. ¡Sí, ahí está el obstáculo! Pues en ese sueño de la muerte, ¿qué sueños pueden venir cuando nos hayamos desprendido de este torbellino mortal, es algo que debe hacernos reflexionar! Eso es lo que hace que nuestras calamidades se prolonguen tanto tiempo. Pues ¿quién soportaría los azotes y el escarnio del tiempo, la opresión del tirano, las afrentas del soberbio, las angustias del amor despreciado, la tardanza de la ley, la insolencia del cargo y los desdenes que el paciente mérito recibe de los indignos, cuando uno mismo podría resolverlo con un simple estilete? ¿Quién llevaría esas cargas, gimiendo y sudando bajo el peso de una vida fatigosa, si no fuera por el temor de algo después de la muerte, ese país inexplorado de cuyos confines ningún viajero retorna, y que desconcierta nuestra voluntad y nos hace soportar los males que tenemos antes que volar a otros que no conocemos? Así la conciencia hace cobardes a todos nosotros; y así el matiz original de la resolución queda oscurecido con la pálida sombra del pensamiento, y empresas de gran envergadura y valor por esta razón se desvían de su curso y pierden el nombre de acción. ¡Silencio! La bella Ofelia. ¡Ninfa, en tus oraciones recuerda todos mis pecados!";
    char longestWord[MAX_LENGTH];
    char wordToFind[MAX_LENGTH];
    int wordCount = 0;
    int found = 0;

    printf("%s\n\n", sentence);

    printf("\nIngresa una palabra para buscar: ");
    fgets(wordToFind, sizeof(wordToFind), stdin);

    // Eliminar el carácter de nueva línea
    size_t len = strlen(wordToFind);
    if (len > 0 && wordToFind[len - 1] == '\n') {
        wordToFind[len - 1] = '\0';
    }

    buscPal(sentence, wordToFind, &found);
    encNumPal(sentence, &wordCount);
    encPalLarg(sentence, longestWord);

    printf("\nNúmero de palabras: %d", wordCount);
    printf("\nPalabra más larga: %s", longestWord);

    if (found == 1) {
        printf("\nSe encontró la palabra \"%s\".\n", wordToFind);
    } else {
        printf("\nNo se encontró la palabra \"%s\".\n", wordToFind);
    }

    return 0;
}

