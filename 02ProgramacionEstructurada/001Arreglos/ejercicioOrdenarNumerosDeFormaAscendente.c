#include <stdio.h>

int main()
{
  int numero[5] = {4, 3, 1, 5, 2};
  int numeroMenor;
  int numeroMayor;

  while (numeroMayor != 6)
  {
    for (int i = 0; i < 4; i++)
    {
      if (numero[i] > numero[i + 1])
      {
        numeroMenor = numero[i + 1];
        numeroMayor = numero[i];
        numero[i] = numeroMenor;
        numero[i + 1] = numeroMayor;
      }
    }
  }

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", numero[i]);
  }

  return 0;
}