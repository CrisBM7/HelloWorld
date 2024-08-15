#include <stdio.h>
#include <string.h>
 
int main(){
    char cadena[] = "Esto es un texto. Puede ir separado por puntos, espacios o comas.",
    delimitador[] = ",. ";
    char *token = strtok(cadena, delimitador);
    //if(token != NULL){
        while(token != NULL){
            // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
            printf("Token: %s\n", token);
            token = strtok(NULL, delimitador);
        }
    //}
}