#include <stdio.h>

int main()
{
    float val1,val2,val3, mediah, mediahdenominador;

    printf("Digite o primeiro valor:\n");
    scanf("%f", &val1);
    printf("Digite o segundo valor:\n");
    scanf("%f", &val2);
    printf("Digite o terceiro valor:\n");
    scanf("%f", &val3);

    mediahdenominador = ((1/val1)+(1/val2)+(1/val3));
    printf("%f", mediahdenominador);
    mediah = 3/mediahdenominador;

    printf("A média harmomnica é: %f", mediah);
    return 0;
}
