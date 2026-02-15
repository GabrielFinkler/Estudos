#include <stdio.h>

void triangulo(int lado1, int lado2, int lado3)
{
    int tria;

    if(lado1 >= lado2+lado3)
        tria = 0;
    else if(lado2 >= lado3+lado1)
        tria = 0;
    else if(lado3 >= lado1+lado2)
        tria = 0;
    else
        tria = 1;
    if(tria == 1)
    {
        printf("Forma um triangulo. \n");
        if(lado1 == lado2 && lado1 == lado3)
            printf("Tipo: Equilatero \n");
        else if(lado1 != lado2 && lado1!= lado3)
                printf("Tipo: Escaleno \n");
        else
            printf("Tipo: Isoceles \n");


    }else
        printf("Nao forma um triangulo. \n");

}

int main()
{
    int lado1, lado2, lado3;
    char sn;

    do
    {
        printf("Digite os tres lados do triangulo:");
        scanf("%d %d %d", &lado1, &lado2, &lado3);
        triangulo(lado1, lado2, lado3);

        printf("Deseja verificar outro triangulo? (S/N):");
        scanf(" %c", &sn);
    }while(sn == 'S');


    return 0;
}
