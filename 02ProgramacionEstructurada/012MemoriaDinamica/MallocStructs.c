#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void miFflush()
{
    while (getchar() != '\n')
        ;
}

// Definicion de la estructura Estudiante
typedef struct
{
    char name[50];
    int grade;
} Student;

int main()
{
    int n;

    // Preguntar cuantos estudiantes se desean registrar
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    // Asignar memoria para n estudiantes
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Rellenar la informacion de los estudiantes
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        miFflush();
        fgets(students[i].name, sizeof(students[i].name), stdin);
        strtok(students[i].name, "\n");

        printf("Ingrese la calificacion del estudiante %d: ", i + 1);
        scanf("%d", &students[i].grade);
    }

    // Imprimir la informacion de los estudiantes
    printf("\nInformacion de los estudiantes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Estudiante %d - Nombre: %s\tCalificacion: %d\n", i + 1, students[i].name, students[i].grade);
    }

    // Liberar la memoria asignada
    free(students);

    return 0;
}
