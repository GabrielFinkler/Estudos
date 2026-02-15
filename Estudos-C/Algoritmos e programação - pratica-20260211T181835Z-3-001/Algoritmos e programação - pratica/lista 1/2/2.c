#include <stdio.h>

int main()
{
    float reais,taxa,dolar;

    printf("Digite o valor em reais:\n");
    scanf("%f", &reais);
    printf("Valor do dólar no dia de hoje:\n");
    scanf("%f", &taxa);

    dolar = reais/taxa;

    printf("O valor em dólares é %f.", dolar);

}
