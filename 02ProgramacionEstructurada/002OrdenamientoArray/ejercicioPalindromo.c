#include <stdio.h>

int main()
{
  char palabra[9] = {'r', 'y', 'c', 'o', 'n', 'o', 'c', 'e', 'r'};
  char comparacion[9];
  char letra;
  int j;
  int salida;
  int salida2 = 9;

  for (int i = 8; i >= 0; i--)
  {
    letra = palabra[i];
    comparacion[j] = letra;
    j++;
  }
  for (int e = 0; e < salida2; e++)
  {
    if (palabra[e] == comparacion[e])
    {
      salida = 1;
    }
    else
    {
      e = 0;
      salida2 = 0;
      salida = 0;
    }
  }

  if (salida == 1)
  {
    printf("Es palindromo");
  }
  else
  {
    printf("No es palindromo");
  }

  return 0;
}