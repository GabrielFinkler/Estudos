#include <stdio.h>
#include <ctype.h>


void AchaPrimeiraMaiuscula(char frase[])
{

    if(isupper(frase[0]) != 0)
    {
        printf("%c", frase[0]);
    }else if(frase[0] == '\0')
    {
        printf("\0");
    }else
    {

        AchaPrimeiraMaiuscula(frase + 1);

    }

}

int main()
{
    int n = 0;
    char frase[50];

    printf("Entre uma string:");
    gets(frase);
    AchaPrimeiraMaiuscula(frase);



}
