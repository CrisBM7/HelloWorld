#include <stdio.h>

/****Tu funcion aqui*****/

float sacarProm(float num[]){
    float promedio = 0;
    for(int i = 0; i<5; i++){
        promedio = promedio + num[i];
    }
    promedio = promedio/5;
    return promedio;
}

int main() {
    int numAlumnos = 5;
    int numMaterias = 5;
    float calificaciones[numAlumnos][numMaterias];
    float promedios[numAlumnos];
    float promedioGeneral = 0;

    // Captura de calificaciones
    for (int i = 0; i < numAlumnos; i++) {
        printf("Ingresa las calificaciones para el alumno %d:\n", i + 1);
        for (int j = 0; j < numMaterias; j++) {
            printf("Calificacion de la materia %d: ", j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }

    /****Tu codigo aqui*****/
    for(int i = 0; i < 5; i++){
        sacarProm(calificaciones[i]);
        promedios[i] = sacarProm(calificaciones[i]);
    }


    for(int i = 0; i < 5; i++){
        sacarProm(promedios);
        promedioGeneral = sacarProm(promedios);
    }



    // Mostrar resultados
    printf("\nPromedios de los alumnos:\n");
    for (int i = 0; i < numAlumnos; i++) {
        printf("Alumno %d: %.2f\n", i + 1, promedios[i]);
    }
    printf("\nPromedio general del salon: %.2f\n", promedioGeneral);

    return 0;
}
