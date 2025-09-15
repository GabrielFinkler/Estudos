/*Escreva um programa que permita a entrada das seguintes varia veis de um funciona rio de uma empresa: ano de
nascimento, valor sala rio, ano de admissa o na empresa, opça o que deseja calcular (1, 2 ou 3). A opça o selecionada
deve direcionar para o ca lculo desejado conforme segue:
Opça o 1) Imprime o cálculo do imposto de renda segundo a regra: para sala rios maiores ou iguais a R$ 10.000
aplica-se 25% de imposto; para sala rios entre R$ 5.000 e R$ 10.000 15%; e para sala rios menores ou iguais a R$
5000 aplica-se 10%.
Opça o 2) Imprime o valor do desconto do plano de saúde que e calculado segundo a regra: empregados com
sala rios maiores ou iguais a R$ 10.000 ou que tenham ano de nascimento menor que 1975 tem desconto de 2%
sobre valor do sala rio. Demais casos tem desconto de 1.5%.
Opça o 3) Imprime o próximo ano em que receberá aumento de sala rio. De acordo com a polí tica da empresa
o aumento e concedido a cada 3 anos. Usando o ano de admissa o o programa deve calcular o nu mero de aumentos
ja recebidos e qual seria o ano do pro ximo aumento.
Utilize obrigatoriamente SWITCH CASE para o menu de opço es.*/

#include <stdio.h>


int main(void)
{
    int nasc, admi, cod, aumentosRecebidos, anosTrabalhados;

    float salario, renda, saude;

    printf("Digite o ano de nascimento:");
    scanf("%d", &nasc);

    printf("Digite o valor de salario:");
    scanf("%f", &salario);

    printf("Digite o ano de admissão:");
    scanf("%d", &admi);

    printf("Escolhe a opção que deseja calcular(1, 2 ou 3):\n");
    printf("1 - Calcular imposto de renda. \n");
    printf("2 - Calcular desconto do plano de saúde. \n");
    printf("3 - Calcular próximo ano de aumento salarial. \n");
    scanf("%d", &cod);

    switch(cod)
    {
        case 1:
            if(salario >= 10000)
            {
              renda = salario * 0.25;
              printf("Imposto de renda devido: %f", renda);
            }
            else if (salario > 5000 && salario < 10000)
            {
              renda = salario * 0.15;
              printf("Imposto de renda devido: %f", renda);
            }
            else
            {
              renda = salario * 0.10;
              printf("Imposto de renda devido: %f", renda);
            }
            break;
        case 2:
            if(salario >= 10000 || nasc < 1975)
            {
                saude = salario * 0.02;
                printf("Desconto do plano de saúde: %f", saude);
            }
            else
            {
                saude = salario * 0.015;
                printf("Desconto do plano de saúde: %f", saude);
            }
            break;
        case 3:
            anosTrabalhados = 2025 - admi;
            aumentosRecebidos = (anosTrabalhados) / 3;

            if (anosTrabalhados < 3)
               {
               if(anosTrabalhados == 0)
                {
                     printf("Ultimo ano de aumento salarial: 2025 \n");
                     printf("Próximo ano de aumento salarial: 2028 \n");
                }
                else if(anosTrabalhados == 1)
                    {
                        printf("Ultimo ano de aumento salarial: - \n");
                        printf("Próximo ano de aumento salarial: 2027 \n");
                    }
                else if(anosTrabalhados == 2)
                    {
                        printf("Ultimo ano de aumento salarial: - \n");
                        printf("Próximo ano de aumento salarial: 2026 \n");
                    }
               }

            else if(anosTrabalhados % 3 == 0)
               {
                   printf("Ultimo ano de aumento salarial: 2025 \n");
                   printf("Próximo ano de aumento salarial: 2028 \n");
               }
            else if(anosTrabalhados % 3 == 1)
                {
                    printf("Ultimo ano de aumento salarial: 2022 \n");
                    printf("Próximo ano de aumento salarial: 2025 \n");
                }
            else if(anosTrabalhados % 3 == 2)
                {
                    printf("Ultimo ano de aumento salarial: 2023 \n");
                    printf("Próximo ano de aumento salarial: 2026 \n");
                }

            else
                {
                    printf("Ultimo ano de aumento salarial: 2024 \n");
                    printf("Próximo ano de aumento salarial: 2027 \n");
                }

            printf("Numero de anos trabalhados: %d \n", anosTrabalhados);
            printf("Numero de aumentos recebidos: %d \n", aumentosRecebidos);

            break;


    }





}
