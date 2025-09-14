#include <stdio.h>

int main(void)
{
    int idade[100], i = 0, j, w = 0, reprovados = 0 ;
    float nota[100], media, maiorNota, somaIdades;
    printf("=== Cadastro de alunos === \n");

    do
    {
        printf("Digite a idade do aluno: ");
        scanf("%d", &idade[i]);

        if (idade[i]!= 0)
        {
            printf("Digite a nota final (0 a 10):");
            scanf("%f", &nota[i]);
            i++;

        }
        else
        {
            for(j = 0; j <= i; j++)
            {
                if (nota[j] > maiorNota)
                    maiorNota = nota[j];
                somaIdades = somaIdades + idade[j];
                media = somaIdades / i;
                if (nota[j] < 6.0)
                    reprovados++;


            }
            break;
        }

    }
    while (w == 0);
    printf("=== Resultado da pesquisa === \n");
    printf("a) Maior nota registrada: %f \n", maiorNota);
    printf("b) Media das idades: %f \n", media);
    reprovados = reprovados - 1;
    printf("c) Quantidade de alunos reprovados: %d",reprovados);

}
