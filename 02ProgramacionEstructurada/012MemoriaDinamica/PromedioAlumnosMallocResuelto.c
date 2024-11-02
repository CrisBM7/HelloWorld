#include <stdio.h>
#include <stdlib.h>

/*Modificar el siguiente codigo para que el usuario meta tanto el numero de alumnos 
como el numero de materias y en base a esos datos el usuario pueda ingresar las 
calificaciones de cada alumno asi como sus iniciales
El programa debera devolver el promedio junto a la inicial de cada alumno
Y al final debera devolver el promedio del salon*/

void miFflush()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    int nA, nM;
    float suma, promedioTotal;
    float **calificaciones;
    char *estudiantes;

    printf("Numero de Alumnos: ");
    scanf("%d", &nA);
    printf("Numero de Materias: ");
    scanf("%d", &nM);

    // Asignar memoria para un array de punteros a int (filas)
    calificaciones = (float **)malloc(nA * sizeof(float *));
    if (calificaciones == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Asignar memoria para cada fila (columnas)
    for (int i = 0; i < nM; i++)
    {
        calificaciones[i] = (float *)malloc(nM * sizeof(float));
        if (calificaciones[i] == NULL)
        {
            printf("Error al asignar memoria para la fila %d\n", i);
            return 1;
        }
    }

    // Asignar memoria para iniciales de los alumnos
    estudiantes = (char *)malloc(nA * sizeof(char));
    if (calificaciones == NULL)
    {
        printf("Error al asignar memoria para las iniciales de los alumnos %d\n");
        return 1;
    }

    // Capturar inicialesy calificaciones
    printf("\nPromedio de calificaciones:\n");
    for (int i = 0; i < nA; i++)
    {
        printf("Inicial de alumno %d: ", i + 1);
        miFflush();
        scanf("%c", &estudiantes[i]);

        suma = 0;
        for (int j = 0; j < nM; j++)
        {
            printf("Calificacion %d de alumno %c: ", j + 1, estudiantes[i]);
            scanf("%f", &calificaciones[i][j]);
            suma += calificaciones[i][j];
        }
        float promedio = suma / nM;
        printf("%c: %.2f\n", estudiantes[i], promedio);
    }

    // Calcular y imprimir el promedio de cada alumno
    promedioTotal = 0;
    printf("\nPromedio de calificaciones:\n");
    for (int i = 0; i < nA; i++)
    {
        suma = 0;
        for (int j = 0; j < nM; j++)
        {
            suma += calificaciones[i][j];

            promedioTotal += calificaciones[i][j];
        }
        float promedio = suma / nM;
        printf("%c: %.2f\n", estudiantes[i], promedio);
    }
    promedioTotal = promedioTotal / (nA * nM);

    printf("\nPromedio total: %.2f\n", promedioTotal);

    // Liberar la memoria asignada
    for (int i = 0; i < nA; i++)
    {
        free(calificaciones[i]); // Liberar cada fila
    }
    free(calificaciones); // Liberar el array de punteros
    return 0;
}
