#include <stdio.h>

int main(void)
{
        int val1,val2,val3;
        int soma;
        int produto;

        printf("Valor do primeiro termo da soma:\n");
        scanf("%d", &val1);

        printf("Valor do segundo termo da soma:\n");
        scanf("%d", &val2);

        printf("Valor do terceiro termo da soma:\n");
        scanf("%d", &val3);


        soma = val1 + val2 + val3;

        produto = val1 * val2 * val3;

        printf("Resultado da soma: %d\n",soma);
        printf("Resultado da multiplicação: %d\n",produto);
        return 0;
}
