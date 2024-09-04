#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float promedio;

    printf("Cuantos alumnos son?: ");
    scanf("%d", &n);

    float *nAlumnos = (float *)malloc(n * sizeof(float));

    for(int i = 0; i < n; i++){
        printf("Ingresa la calificacion del alumno: ");
        scanf("%f", &nAlumnos[i]);
        promedio += nAlumnos[i];
    }

    promedio = promedio/n;

    printf("El promedio es: %.1f", promedio);

}