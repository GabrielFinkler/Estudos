#include <stdio.h>
#include <math.h>

int main(void)
{
    float pNumero, sNumero, resultado;
    char o;

    while ( o != '0')
    {
        printf("Selecione a operacao a ser realizadas: \n");
        printf("+ : Soma \n");
        printf("- : Subtracao \n");
        printf("* : Multiplicacao \n");
        printf("/ : Divisao \n");
        printf("P : Potenciacao \n");
        printf("R : Raiz quadrada \n");
        printf("0 : Finalizar \n");
        scanf(" %c", &o);
        switch(o)
        {
            case '+' :
                printf("Digite o primeiro numero: ");
                scanf("%f", &pNumero);
                printf("Digite o segundo numero: ");
                scanf("%f", &sNumero);
                resultado = pNumero + sNumero;
                printf("%.2f + %.2f = %.2f \n", pNumero, sNumero, resultado);
                break;
            case '-' :
                printf("Digite o primeiro numero: ");
                scanf("%f", &pNumero);
                printf("Digite o segundo numero: ");
                scanf("%f", &sNumero);
                resultado = pNumero - sNumero;
                printf("%.2f - %.2f = %.2f \n", pNumero, sNumero, resultado);
                break;
            case '*' :
                printf("Digite o primeiro numero: ");
                scanf("%f", &pNumero);
                printf("Digite o segundo numero: ");
                scanf("%f", &sNumero);
                resultado = pNumero * sNumero;
                printf("%.2f * %.2f = %.2f \n", pNumero, sNumero, resultado);
                break;
            case '/' :
                printf("Digite o primeiro numero: ");
                scanf("%f", &pNumero);
                printf("Digite o segundo numero: ");
                scanf("%f", &sNumero);
                resultado = pNumero / sNumero;
                printf("%.2f / %.2f = %.2f \n", pNumero, sNumero, resultado);
                break;
            case 'P':
                printf("Digite o primeiro numero: ");
                scanf("%f", &pNumero);
                printf("Digite o segundo numero: ");
                scanf("%f", &sNumero);
                resultado = pow(pNumero,sNumero);
                printf("%.2f ** %.2f = %.2f \n", pNumero, sNumero, resultado);
                break;
            case 'R':
                printf("Digite o numero: ");
                scanf("%f", &pNumero);
                resultado = sqrt(pNumero);
                printf("A raiz de %.2f e %.2f. \n", pNumero, resultado);
                break;
            default:
                printf("Operacao invalida \n");
                break;
        }

    }
    printf("Calculadora finalizada");
    return 0;
}
