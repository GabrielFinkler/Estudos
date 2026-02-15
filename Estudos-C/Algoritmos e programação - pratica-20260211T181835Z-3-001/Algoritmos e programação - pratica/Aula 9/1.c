#include <stdio.h>
#include <math.h>

void isQuadradoPerfeito(int n)
{
    float raiz;
    int m;

    raiz = sqrt(n);
    m = floor(raiz);
    if(pow(m,2) == n)
    {
        printf("%d e quadrado perfeito", n);
    }else
        printf("%d nao e quadrado perfeito", n);

}

int main()
{
    int n;


    printf("Digite um numero inteiro nao negativo:");
    scanf("%d", &n);
    isQuadradoPerfeito(n);


    return 0;
}
