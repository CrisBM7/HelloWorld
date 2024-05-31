#include <stdio.h>

int main()
{
    // Declarar e inicializar el arreglo bidimensional
    float calificaciones[5][4] = {
        {8.5, 9.0, 7.8, 9.2},  // Calificaciones de Juan
        {7.5, 8.0, 7.0, 8.5},  // Calificaciones de María
        {9.5, 10.0, 9.0, 9.8}, // Calificaciones de Pedro
        {6.5, 7.0, 7.5, 8.0},  // Calificaciones de Ana
        {8.5, 8.8, 8.4, 9.0}   // Calificaciones de Luis
    };

    // Nombres de los estudiantes
    char estudiantes[5] = {'J', 'M', 'P', 'A', 'L'};

    //Tu codigo aqui

    float promedioAlumnos [5] = {0,0,0,0,0};

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            promedioAlumnos[i] = calificaciones[i][j] + promedioAlumnos[i];
        }
        promedioAlumnos[i] = promedioAlumnos[i]/4;
    }

    printf("Calificaciones promedio\n");

    for (int i = 0; i < 5; i++){
        printf("%c: %.2f", estudiantes[i], promedioAlumnos[i]);
        printf("\n");
    }





    
    return 0;
}
