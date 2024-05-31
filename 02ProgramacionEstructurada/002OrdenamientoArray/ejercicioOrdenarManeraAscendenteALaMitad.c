#include <stdio.h>
#define N 10

int main()
{
    int numOrdenados[N] = {33, 25, 36, 46, 75, 61, 70, 8, 9, 10};
    int temp;
    
    for(int i = 0; i < N; i++ ){
        temp = numOrdenados[i];
        int j = i - 1;
        while (j >= 0 && numOrdenados[j] > temp)
        {
            numOrdenados[j + 1] = numOrdenados[j];
            j = j - 1;
        }
        numOrdenados[j + 1] = temp;
    }
    
    int extra;
    int j = 9;
    for(int i = N/2; i < 7; i++){
        extra = numOrdenados[i];
        numOrdenados[i] = numOrdenados[j];
        numOrdenados[j] = extra;
        j--;
    }
    
    for(int i = 0; i < N; i++){
       printf("%d ", numOrdenados[i]); 
    }

    return 0;
}