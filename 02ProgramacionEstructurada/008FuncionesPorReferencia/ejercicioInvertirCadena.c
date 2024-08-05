#include <stdio.h>

void invertirCadena(char *cad)
{
    int num = 11;
    char temp;
    char temp2;
    for(int i = 0; i < 6; i++){
       temp = cad[i];
       temp2 = cad[num];
       cad[i] = temp2;
       cad[num] = temp;
        num--;
    }
}

int main()
{
    char cad[12] = {'H', 'o', 'l', 'a', ',', ' ', 'M', 'u', 'n', 'd', 'o', '!'};


    printf("Cadena original: ");

    for(int i = 0; i < 12; i++){
        printf("%c", cad[i]);
    }

    invertirCadena(&cad);

    printf("\nCadena modificada: "); 

    for(int i = 0; i < 12; i++){
        printf("%c", cad[i]);
    }
    return 0;
}