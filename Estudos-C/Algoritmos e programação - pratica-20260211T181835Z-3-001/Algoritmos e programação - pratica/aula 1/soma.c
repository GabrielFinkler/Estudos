#include <stdio.h>

int main(void)
{
        int val1,val2;
        int soma;

        printf("Valor do primeiro termo da soma:\n");
        scanf("%d", &val1);

        printf("Valor do segundo termo da soma:\n");
        scanf("%d", &val2);

        soma = val1 + val2;

        printf("Resultado da soma: %d",soma);
        return 0;
}
