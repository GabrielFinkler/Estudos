#include <stdio.h>

int main(void)
{

    int n ,i;

    float soma, j;

    soma = 0;


    printf("Digite o valor de n:");
    scanf("%d", &n);

    printf("Serie: ");

    for(i = 1; i <= n; i++)
    {

        printf("1/%d ", i);

        j = i;

        if(i % 2 == 0)
        {
            if(i != n)
            {
                printf("+ ");
            }
            soma = soma - (1/j);
        }
        else
        {
            if(i != n)
            {
                printf("- ");
            }
            soma = soma + (1/j);
        }

    }
    printf("\nResultado S = %f", soma);
}
