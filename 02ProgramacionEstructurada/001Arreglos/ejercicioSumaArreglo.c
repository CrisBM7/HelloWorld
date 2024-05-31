#include <stdio.h>

int main()
{
    int suma[5] = {1, 2, 3, 4, 5};
    int total = 0;

    for(int i = 0; i < 5; i++){
        total = suma[i] + total;
    }
    printf("%d ", total);

    return 0;
}