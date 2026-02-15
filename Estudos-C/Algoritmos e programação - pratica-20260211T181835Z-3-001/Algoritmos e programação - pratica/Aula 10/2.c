#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void matrizAleatoria(int m, int n, int min, int max, int matriz[][20])
{

    int i,j;

    srand(time(NULL));
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            matriz[i][j] = min + (rand()%((max-min)+1));

        }
    }

}

void imprimeMatriz(int m, int n, int matriz[][20])
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0;j < n; j++)
        {
            printf("%d ",matriz[i][j]);

            if(j == n-1)
                printf("\n");
        }
    }
}

float vetorMaiorMedia(int matriz[][20], int *vetor, int m, int n, int *v)
{
    int i, j, soma = 0;
    float media,contador = 0.0;


    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            soma = soma + matriz[i][j];
            contador++;
        }
    }
    media = soma / contador;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(((float)matriz[i][j]) > media)
                {vetor[(*v)] = matriz [i][j];
                (*v)++;
                }
        }
    }




    return media;
}
int main()
{

    int m, n, min, max, i, v = 0;
    int matriz[20][20], vetor[400];
    float media;

    printf("Informe m e n:");
    scanf("%d %d", &m, &n);

    printf("Informe o intervalo [inicio, fim] para popular M:");
    scanf("%d %d", &min, &max);

    matrizAleatoria(m,n,min,max, matriz);
    imprimeMatriz(m,n, matriz);
    media = vetorMaiorMedia(matriz, &vetor, m, n, &v);
    printf("Media de M = %.2f", media);
    printf("Vetor V (valores unicos de M > media):");

    for(i = 0; i < v; i++)
        printf("%d", vetor[i]);




    return 0;
}
