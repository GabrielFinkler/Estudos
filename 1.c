#include <stdio.h>


int main(void)
{
    float saldo, saque, saldoAtual;
    int i=0;

    printf("Digite o saldo inicial da conta:");
    scanf("%f", &saldo);


    do{

        printf("Digite o valor do saque (0 para encerrar):");
        scanf("%f", &saque);
        ++i;
        if (saque == 0 || saque > saldo)
        {
            i = i - 1;
            printf("=== Operacao invalida === \n");
            printf("Quantidade de saques realizados: %d \n", i);
            printf("Saldo final: %f", saldo);
            break;
        }else
        saldo = saldo - saque;
        printf("Saque realizado com sucesso! \n");
        printf("Saldo atual: %f \n", saldo);

    }while(saldo > saque && saque <= saldo);

    return 0;
}
