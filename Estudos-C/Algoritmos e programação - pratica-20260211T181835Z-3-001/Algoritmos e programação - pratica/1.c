#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int N, M,aux, i, j, k, l,q = 0,r,s,t,u,o, p, aleatorio, matrizZ[10][10],matrizZE[10][10], vetorInter[100];


    srand(time(NULL));

    printf("Informe M:");
    scanf("%d", &M);
    printf("Informe N:");
    scanf("%d", &N);


    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            aleatorio = -9+(rand()%(19));
            while(aleatorio == 0)
                aleatorio = -9+(rand()%(19));

            matrizZ[i][j] = aleatorio;
        }
    }
    printf("**** Matriz Z (%dx%d): \n",M,N);
    for(k = 0; k < M; k++)
    {
        for(l = 0; l < N; l++)
        {
            printf("%d ",matrizZ[k][l]);
            if(l == (N-1))
            {
                printf("\n");

            }
        }

    }
    for(o = 0; o < M; o++)
    {
        for(p = 0; p < N; p++)
        {
            matrizZE[o][p] = matrizZ[o][(N-1)-p];
        }
    }

    printf("**** Matriz Z espelhada horizontalmente: \n");
    for(r = 0; r < M; r++)
    {
        for(s = 0; s < N; s++)
        {
            printf("%d ",matrizZE[r][s]);
            if(s == (N-1))
            {
                printf("\n");

            }
        }

    }
    i = 0;

    for(t = 0; t < M; t++)
    {
        for(u = 0; u < N; u++)
        {
            vetorInter[i] = matrizZ[t][u];
            //printf("%d", vetorInter[i]);
            i++;

        }

    }

//sorting

/*
    int n = sizeof(vetorInter) / sizeof(vetorInter[0]);

    // Sort the array arr
    qsort(vetorInter, n, sizeof(vetorInter[0]), comp);

    for (int i = 0; i < n; i++)
        printf("%d ", vetorInter[i]);
    return 0;*/
}
