#include<stdio.h>

int main(void)
{
    int A, B, n, multiplo, i;

    printf("Digite o valor de A:");
    scanf("%d", &A);
    printf("Digite o valor de B:");
    scanf("%d", &B);
    printf("Digite o valor de n:");
    scanf("%d", &n);

    multiplo = n;

    for(i = n; multiplo % A != 0 || multiplo % B != 0; i++)
    {
        multiplo = i;

    }
    printf("O primeiro multiplo comum de %d e %d a partir de %d eh: %d", A, B, n, multiplo);

    return 0;
}
