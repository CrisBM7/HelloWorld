#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    char buffer[256];

    // Apertura del archivo en modo "a+"
    file = fopen("mi_archivo.txt", "a+");
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escritura en el archivo
    fprintf(file, "Nueva linea de texto\n");

    // Coloca el puntero al principio del archivo para la lectura
    rewind(file);

    // Lectura del archivo
    printf("Contenido del archivo:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    // Cierre del archivo
    if (fclose(file) != 0)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }

    return 0;
}
