#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 51
int main(void)
{
    int i, w = 0, j, m, n,b;
    char frases[5][N];
    char frasesMin[5][N];
    char busca[51];
    char buscaMin[51];

    printf("Digite 5 frases (cada uma com ate 50 caracteres): \n");
    for(i = 0; i <= 4; i++)
    {
        printf("Frase %d: ", i+1);
        gets(frases[i]);
    }

    do
    {
        printf("Digite a string de busca (ou 'sair' para encerrar):");
        gets(busca);
        if(strcmp(busca,"sair") == 0)
        {
            printf("Encerrando... \n");
            break;
        }

        else
        {
            for(m = 0 ; m <= 4; m++)
            {
                for(j = 0 ; frases[m][j] != '\0'; j++)
                {
                    frasesMin[m][j]= (char)tolower(frases[m][j]);

                }
            }
            for(n = 0 ; n <= strlen(busca); n++)
            {
                buscaMin[n] = (char)tolower(busca[n]);


            }

            for(b = 0 ; b <= 4; b++)
            {

                if(strstr(frasesMin[b],buscaMin) != NULL )
                {

                    printf("%s \n", frases[b]);
                }
            }



        }


    }
    while(w == 0);

    return 0;
}
