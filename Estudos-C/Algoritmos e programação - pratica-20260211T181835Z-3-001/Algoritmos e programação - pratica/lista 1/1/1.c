#include <stdio.h>
#include <math.h>

int main(void)
{
    float X1,Y1,X2,Y2;
    float distquadra;
    float dist;

    printf("Digite a coordenada x e depois y do primeiro ponto:\n");
    scanf("%f", &X1);
    scanf("%f", &Y1);

    printf("Digite a coordenada x e depois y do segundo ponto:\n");
    scanf("%f", &X2);
    scanf("%f", &Y2);

    distquadra = ((pow(X2-X1,2))+((pow(Y2-Y1,2))));
    printf("%f",distquadra);
    dist = sqrt(distquadra);

    printf("A distância é:%f",dist);
}
