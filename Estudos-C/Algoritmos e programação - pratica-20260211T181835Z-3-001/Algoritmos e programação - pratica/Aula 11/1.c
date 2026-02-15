#include <stdio.h>
#include<string.h>


typedef struct {
 int dia;
 int mes;
 int ano;
} Data;
typedef struct {
 char nomeHospede[20];
 int quarto;
 Data entrada;
 float valorDiaria;
 int diarias;
 float valorTotal; //não precisa ser lido
} Reserva;

//************************************************************

void cadastrarReservas(Reserva *v, int *n)
{
    char simounao = 's';

    do{
        printf("Digite o nome do hospede:");
        getchar();
        fgets(v[*n].nomeHospede,20,stdin);
        v[*n].nomeHospede[strcspn(v[*n].nomeHospede, "\n")] = '\0';
        printf("Digite o quarto do hospede:");
        scanf("%d", &v[*n].quarto);
        printf("Digite a data de entrada(xx xx xx)");
        scanf("%d %d %d", &v[*n].entrada.dia,&v[*n].entrada.mes,&v[*n].entrada.ano);
        printf("Digite o valor da diaria:");
        scanf("%f", &v[*n].valorDiaria);
        printf("Digite o numero de diarias:");
        scanf("%d", &v[*n].diarias);
        v[*n].valorTotal = v[*n].diarias * v[*n].valorDiaria;
        (*n)++;
        printf("Deseja adcionar mais uma reserva?(s/n)");
        scanf(" %c", &simounao);

    }while(simounao == 's');


}

void listarReservas(Reserva v[], int n)
{
    int i;

    printf("# Hospede  Quarto  Entrada  Diaria  Qtde  ValorTotal \n");
    printf("------------------------------------------------------------------------- \n");
    for(i=0;i<n;i++)
    {

        printf("%d  %s  %d  %d/%d/%d  R$%.2f  %d  %.2f \n", i+1,v[i].nomeHospede,v[i].quarto,v[i].entrada.dia,v[i].entrada.mes,v[i].entrada.ano,v[i].valorDiaria,v[i].diarias,v[i].valorTotal);
    }
}

float calcularMedia(Reserva v[], int n)
{
  int i, soma = 0, media;

  for(i=0;i<n;i++)
  {
      soma += v[i].valorTotal;
  }

  media = soma / n;

  return media;

}

void listarAcimaDaMedia(Reserva v[], int n)
{
    int i;
    float media;
    media = calcularMedia(v,n);
    printf("Reservas com valor total acima do valor total medio: \n");
    for(i=0;i<n;i++)
    {
        if(v[i].valorTotal > media)
        {
            printf("%d  %s  %d  %d/%d/%d  R$%.2f  %d  %.2f \n", i+1,v[i].nomeHospede,v[i].quarto,v[i].entrada.dia,v[i].entrada.mes,v[i].entrada.ano,v[i].valorDiaria,v[i].diarias,v[i].valorTotal);

        }
    }

}


int main()
{

    int s,i,n = 0,w=0;
    float soma = 0.0;
    Reserva v[50];


    do
    {
        printf("Selecione uma opcao de 1 a 5 \n");
        printf("1. Cadastrar reservas \n");
        printf("2. Calcular valor total das reservas \n");
        printf("3. Listar as reservas \n");
        printf("4. Listar reservas acima da media \n");
        printf("5. Sair \n");
        scanf("%d", &s);

        switch(s)
        {
            case 1:
                cadastrarReservas(v,&n);
                break;
            case 2:
                for(i=0;i<n;i++)
                {
                    soma += v[i].valorTotal;
                }
                printf("O valor total de todas as reservas e: R$");
                printf("%.2f \n", soma);
                break;
            case 3:
                listarReservas(v,n);
                break;
            case 4:
                listarAcimaDaMedia(v,n);
                break;
            default:
                break;


        }

    }while(s != 5);


    return 0;
}

