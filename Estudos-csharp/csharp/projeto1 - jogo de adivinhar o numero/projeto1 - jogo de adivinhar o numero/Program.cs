using System;

Console.WriteLine("Bem vindo ao jogo do adivinhe o numero");

Random gerador = new Random();

int numeroAleatorio = gerador.Next(1, 100);
int loop = 1;

Console.Write("Digite seu primeiro chute(0 - 100):");

do
{
    string chute = Console.ReadLine();
    int chuteN = int.Parse(chute);
    if (chuteN == numeroAleatorio)
    {
        Console.WriteLine("Parabéns você acertou o numero aleatório");
        loop = 0;
    }else if( chuteN < numeroAleatorio)
    {
        Console.WriteLine("O numero chutado é menor que o número correto");
        loop = 1;
    }
    else if(chuteN > numeroAleatorio)
    {
        Console.WriteLine("O número chutado é maior que o número correto");
         loop = 1;
    }else
    {
        Console.WriteLine("Você digitou uma resposta invalida");
        loop = 1;
    }

} while (loop == 1);