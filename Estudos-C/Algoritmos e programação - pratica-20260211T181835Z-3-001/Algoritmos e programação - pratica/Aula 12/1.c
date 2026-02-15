#include <stdio.h>
#include <string.h>
#define TAM_VENDAS 100

typedef struct {
 int dia;
 int mes;
 int ano;
} DATA;
typedef struct {
 int codigoProduto;
 DATA dataVenda;
 int quantidade;
 float precoUnitario;
} VENDA;

void cadastraVendas(VENDA *v, int *n)
{
    int n3 = 0,i;

    printf("Quantas vendas deseja cadastrar (maximo 100)? \n");
    scanf("%d", &n3);
    for(i=0;i<n3;i++)
    {
        printf("--- Venda %d --- \n", i+1);
        printf("Codigo do produto:");
        scanf("%d", &v[i].codigoProduto);
        printf("Data da venda (dia mes ano):");
        scanf("%d %d %d", &v[i].dataVenda.dia, &v[i+(*n)].dataVenda.mes, &v[i+(*n)].dataVenda.ano);
        printf("Quantidade:");
        scanf("%d", &v[i].quantidade);
        printf("Preco unitario:");
        scanf("%f", &v[i].precoUnitario);
    }
    (*n) = (*n) + n3;
}

void criaArquivo(char nomeArquivo[], VENDA *v, int n)
{
    FILE *arquivo;
    int i,l;
    printf(" --- %d",n);
    arquivo = fopen(nomeArquivo,"wb");
    if (arquivo == NULL)
    {
        printf("Erro. \n");


    }else{
        printf("Arquivo criado com sucesso. \n");

        l = fwrite(&n,sizeof(int),1,arquivo);
        if(l !=1)
            printf("erro \n");
        fwrite(v,sizeof(VENDA),n,arquivo);
    }


}

int leArquivo(char nomeArquivo[],VENDA *v)
{
    FILE *arquivo;
    int n;
    //tem algo errado aqui n sei oq é
    arquivo = fopen(nomeArquivo,"rb");
    if (arquivo == NULL)
    {
        printf("Erro. \n");


    }else{
        printf("Arquivo criado com sucesso. \n");
        fread(&n,sizeof(int),1,arquivo);
        fread(v,sizeof(VENDA),n,arquivo);
        printf("O numero de vendas lidas é: %d", n);
    }

    return n;

}

int insereVenda(VENDA *v, int n)
{
        printf("--- Inserindo nova venda (posicao %d) --- \n",n+1);
        printf("Codigo do produto:");
        scanf("%d", &v[1+n].codigoProduto);
        printf("Data da venda (dia mes ano):");
        scanf("%d %d %d", &v[n+1].dataVenda.dia, &v[n+1].dataVenda.mes, &v[n+1].dataVenda.ano);
        printf("Quantidade:");
        scanf("%d", &v[n+1].quantidade);
        printf("Preco unitario:");
        scanf("%f", &v[n+1].precoUnitario);
        n = n+1;
        return n;
}

void imprimeDados(VENDA *v, int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("Venda %d: %d \n", n+1);
        printf("Codigo produto: %d \n", v[i].codigoProduto);
        printf("Data : %d %d %d \n", v[i].dataVenda.dia,v[i].dataVenda.mes,v[i].dataVenda.ano);
        printf("Quantidade: %d \n", v[i].quantidade);
        printf("Preco unitário: %d \n", v[i].precoUnitario);
    }

}

void escreveArquivo()
{

}

int main()
{
    int n = 0,n2 = 0;
    char nomeDoArquivo[20],nomeDoArquivo2[20];
    VENDA v[TAM_VENDAS], v2[TAM_VENDAS];

    cadastraVendas(v,&n);
    printf("Digite o nome do arquivo binario para CRIAR:(Ate 20 caracteres)");
    getchar();
    fgets(nomeDoArquivo,20,stdin);
    nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = '\0';
    criaArquivo(nomeDoArquivo,v,n);
    printf("Digite o nome do arquivo binario para LER:(Ate 20 caracteres)");
    getchar();
    fgets(nomeDoArquivo2,20,stdin);
    nomeDoArquivo2[strcspn(nomeDoArquivo2, "\n")] = '\0';
    n2 = leArquivo(nomeDoArquivo2,v2);
    imprimeDados(v2,n2);
    n2 = insereVenda(v2,n2);
    imprimeDados(v2,n2);



    return 0;
}
