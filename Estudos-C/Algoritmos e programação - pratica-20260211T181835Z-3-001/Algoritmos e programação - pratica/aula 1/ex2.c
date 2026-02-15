#include <stdio.h>

int main(void)
{
    int Ano;
    int Idade;

    printf("Entre com o ano de seu nascimento:\n");
    scanf("%d", &Ano);

    Idade = 2025 - Ano;
    printf("Voce tem %d anos", Idade);

    return 0;
}
