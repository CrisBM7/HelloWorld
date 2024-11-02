#include <stdio.h>

int main()
{
    /* Modificar el siguiente codigo para que el usuario meta tanto el numero de alumnos 
    como el numero de materias y en base a esos datos el usuario pueda ingresar las 
    calificaciones de cada alumno asi como sus iniciales
    El programa debera devolver el promedio junto a la inicial de cada alumno
    Y al final debera devolver el promedio del salon*/

    float calificaciones;
    char estudiantes;
    int rows;
    int cols;

    printf("Introduce el numero de alumnos: ");
    scanf("%d", &rows);
    printf("Introduce el numero de calificaciones: ");
    printf("%d", cols);

    int **estudiantes = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < calificaciones; i++)
    {
        matrix[i] = (int *)malloc(calificaciones * sizeof(calificaciones));
        if (matrix[i] == NULL)
        {
            printf("Error al asignar memoria para la fila %d\n", i);
            return 1;
        }
    }

    // Calcular y imprimir el promedio de cada alumno
    printf("\nPromedio de calificaciones:\n");
    for (int i = 0; i < 5; i++)
    {
        int suma = 0;
        for (int j = 0; j < 4; j++)
        {
            suma += calificaciones[i][j];
        }
        float promedio = suma / 4.0;
        printf("%c: %.2f\n", estudiantes[i], promedio);
    }

    return 0;
}
