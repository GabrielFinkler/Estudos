#include <stdio.h>
#include <string.h>

typedef struct
{
    int tipo; // código do cômodo (1..6)
    float area; // área em m²
} COMODO;
// cômodos:1=sala, 2=cozinha, 3=garagem, 4=banheiro, 5=dormitorio, 6=suite
typedef struct
{
    int codigo;
    char endereco[50];
    float areaTotal;
    float valor;
    COMODO comodos[10]; // até 10 cômodos cadastrados
    int numComodos; // quantidade efetiva em 'comodos'
} IMOVEL;

void imprimeDados(char *binario)
{
    printf("tester \n");
    FILE *arquivo;
    arquivo = fopen(binario,"rb");
    printf("tester2 \n");
    IMOVEL imo;
    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo. \n");
    }
    printf("--- CONTEUDO DO ARQUIVO --- \n");
    while(fread(&imo,sizeof(IMOVEL), 1,arquivo) == 1)
    {
        printf("%-10d %-50s %-10.2f %-10d \n",imo.codigo,imo.endereco,imo.valor,imo.numComodos);
    }

    fclose(arquivo);
    return 0;

}

void editaDado(char *binario)
{
    int codigo;
    char novoEndereco[49];
    FILE *arquivo;
    arquivo = fopen(binario,"r+b");
    IMOVEL imo;
    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo. \n");
    }
    printf("Informe o codigo do imovel a ser editado:");
    scanf("%d", &codigo);
    while(fread(&imo,sizeof(IMOVEL), 1,arquivo) == 1)
    {
        if(imo.codigo == codigo)
        {
            printf("Imovel encontrado: \n");
            printf("Codigo: %d \n", imo.codigo);
            printf("Endereco atual: %s \n", imo.endereco);
            printf("Valor: %f \n", imo.valor);
            printf("Informe o novo endereço (max 49 caracteres):");
            getchar();
            gets(novoEndereco);
            strcpy(imo.endereco,novoEndereco);
            fseek(arquivo,-sizeof(IMOVEL),1);
            fwrite(&imo,sizeof(IMOVEL),1,arquivo);



            fclose(arquivo);
            break;
        }

    }

    fclose(arquivo);
    return 0;



}

void binToTexto(char *binario,char *texto)
{
    FILE *arquivo;
    FILE *arquivo2;
    arquivo = fopen(binario,"r+b");
    arquivo2 = fopen(texto,"w");
    IMOVEL imo;
    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo. \n");
    }
    while(fread(&imo,sizeof(IMOVEL), 1,arquivo) == 1)
    {
        fprintf(arquivo2,"%d",imo.codigo);
        fprintf(arquivo2,"|");
        fprintf(arquivo2,"%s",imo.endereco);
        fprintf(arquivo2,"|");
        fprintf(arquivo2,"%f",imo.valor);
        fprintf(arquivo2,"|");
        fprintf(arquivo2,"%d",imo.numComodos);
        fprintf(arquivo2,"\n");


    }

    fclose(arquivo);
    return 0;
}

int main()
{
    char nomeDoArquivoBin[20], nomeDoArquivoTex[20];

    printf("Informe o nome do arquivo binario de imoveis:");
    fgets(nomeDoArquivoBin,20,stdin);
    nomeDoArquivoBin[strlen(nomeDoArquivoBin)-1] = '\0';
    imprimeDados(nomeDoArquivoBin);
    editaDado(nomeDoArquivoBin);
    imprimeDados(nomeDoArquivoBin);
    editaDado(nomeDoArquivoBin);
    imprimeDados(nomeDoArquivoBin);
    editaDado(nomeDoArquivoBin);
    printf("Informe o nome do arquivo texto a ser gerado:");
    getchar();
    fgets(nomeDoArquivoTex,20,stdin);
    nomeDoArquivoTex[strcspn(nomeDoArquivoTex, "\n")] = '\0';
    binToTexto(nomeDoArquivoBin,nomeDoArquivoTex);

    return 0;
}
