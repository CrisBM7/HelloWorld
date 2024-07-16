#include <stdio.h>

int obtenerMCD(int num1, int num2){
    int cociente;
    int residuo = 1;
    while(residuo != 0){
        cociente = num1 / num2;
        residuo = num1 % num2;
        num1 = num2;
        num2 = residuo;
    }
    return num1;
};

int obtenerMCM(int num1, int num2){
    int mult = num1*num2;
    int mCD = obtenerMCD(num1, num2);
    int resultado = mult/mCD;
    return resultado;
};

int main() {
    int a;
    int b;
    int mCD;
    int mCM;

    printf("Introduce tu primer numero: ");
    scanf("%d", &a);
    printf("Introduce el segundo numero: ");
    scanf("%d", &b);

    mCD = obtenerMCD(a,b);
    mCM = obtenerMCM(a, b);

    printf("El MCD de %d y %d es: %d\n", a, b, mCD);
    printf("El MCM de %d y %d es: %d", a, b, mCM);

    
    return 0;
}