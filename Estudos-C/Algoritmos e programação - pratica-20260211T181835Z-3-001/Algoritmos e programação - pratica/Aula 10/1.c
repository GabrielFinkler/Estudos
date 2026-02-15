#include <stdio.h>
#include <string.h>

void cifra(char *s1, char *s2, char *s3)
{
    int i, j;
    for(i = 0; i<strlen(s1); i++)
    {
        for(j = 0;j < 50; j++)
        {
            if(s1[i] == s2[j])
                    s1[i] = s3[j];
        }

    }

}


int main()
{
    char s1[50], s2[50], s3[50];
    int i = 0;

    printf("Digite o texto original (s1):");
    fgets(s1, 50, stdin);
    printf("Digite os caracteres a substituir (s2):");
    fgets(s2, 50, stdin);
    printf("Digite os caracteres substitutos (s3):");
    fgets(s3, 50, stdin);

    cifra(&s1, &s2, &s3);

    printf("Texto cifrado: ");
    for(i=0;i<strlen(s1)-1;i++)
        printf("%c", s1[i]);


    return 0;
}
