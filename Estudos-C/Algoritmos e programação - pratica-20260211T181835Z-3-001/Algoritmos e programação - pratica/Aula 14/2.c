#include <stdio.h>


int somaImpares(int *vetor, int soma, int contador)
{
    if(contador<0){
        printf("teste contador");
        return soma;
    }
    if (vetor[0] % 2 != 0 )
    {

        soma = soma + vetor[0];
        contador--;
        return somaImpares(vetor + 1, soma, contador);

    }
        contador--;
        return somaImpares(vetor + 1, soma , contador);


}

int main()
{
    int vetor[5], soma = 0, contador = 4;


    printf("Digite os 5 elementos do vetor:");
    scanf("%d %d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4]);
    soma = somaImpares(vetor, soma, contador);
    printf("Somo dos elementos impares: %d", soma);

    return 0;
}
