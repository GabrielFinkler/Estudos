#include <stdio.h>

int main(void)
{
    int idade [100] = {-1}, i = 0, j, reprovados, somaIdades = 0;
    float nota [100] = {-1}, media, maiorNota;
    for(j = 0; j <100; j++){
        idade[j] = -1;
    }
    printf("=== Cadastro de alunos === \n");

    do{
       printf("Digite a idade do aluno: ");
       scanf("%d", &idade [i]);
       if(idade[i] == 0)
       {
           printf("=== Resultado da pesquisa ===");
           printf("a) Maior nota registrada: %d \n", maiorNota);
           printf("b) Media das idades: %d \n", media);
           printf("c) Quantidade de alunos reprovados: %d \n", reprovados);
       }else
       {
            printf("Digite a nota final(0 a 10): ");
            scanf("%d", &nota [i]);
            if (nota[i] > maiorNota)
                maiorNota = nota[i];
            somaIdades = somaIdades + idade[i];
            media = somaIdades / i;
            if (nota[i] < 6.0)
                reprovados++;
            i++;

       }

    }while(idade != 0);

}
