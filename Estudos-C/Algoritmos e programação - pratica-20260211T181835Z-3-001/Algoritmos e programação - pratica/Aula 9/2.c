#include <stdio.h>


void media(char letra, float nota1, float nota2, float nota3)
{
    float media;

    switch(letra)
    {
            case 'A':
                media = (nota1 + nota2 + nota3)/3;
                printf("Media aritmetica: %.2f", media);
                break;

            case 'P':
                media = ((nota1*5) + (nota2*3) + (nota3*2))/10;
                printf("Media ponderada: %.2f", media);
                break;
    }
}

int main()
{
    float nota1, nota2, nota3;
    char tipo;

    printf("Digite as tres notas do aluno:");
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    printf("Digite o tipo de media (A = aritmetica, P = ponderada):");
    scanf(" %c", &tipo);

    media(tipo, nota1, nota2, nota3);

    return 0;
}
