

using System.Runtime.CompilerServices;
using System.Threading;

string mensagemDeBoasVindas = @"
░██████╗░█████╗░██████╗░███████╗███████╗███╗░░██╗  ░██████╗░█████╗░██╗░░░██╗███╗░░██╗██████╗░
██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗░██║  ██╔════╝██╔══██╗██║░░░██║████╗░██║██╔══██╗
╚█████╗░██║░░╚═╝██████╔╝█████╗░░█████╗░░██╔██╗██║  ╚█████╗░██║░░██║██║░░░██║██╔██╗██║██║░░██║
░╚═══██╗██║░░██╗██╔══██╗██╔══╝░░██╔══╝░░██║╚████║  ░╚═══██╗██║░░██║██║░░░██║██║╚████║██║░░██║
██████╔╝╚█████╔╝██║░░██║███████╗███████╗██║░╚███║  ██████╔╝╚█████╔╝╚██████╔╝██║░╚███║██████╔╝
╚═════╝░░╚════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░╚══╝  ╚═════╝░░╚════╝░░╚═════╝░╚═╝░░╚══╝╚═════╝░";

//List<string> listaDasBandas = new List<string>();  

Dictionary<string, List<int>> bandasRegistradas = new Dictionary<string, List<int>>(); 
    
void ExibirLogo()
{   
    Console.WriteLine(mensagemDeBoasVindas);
}

void ExibirOpicoes()
{
    ExibirLogo();
    Console.WriteLine("Selecione uma das opções abaixo: \n");
    Console.WriteLine("1 - Registrar uma banda");
    Console.WriteLine("2 - Mostrar todas as bandas");
    Console.WriteLine("3 - Avaliar uma banda");
    Console.WriteLine("4 - Mostrar a média de avaliações de uma banda");
    Console.WriteLine("5 - Sair");

    Console.Write("\nDigite a sua opção: ");    
    string opcaoEscolhida = Console.ReadLine()!;
    int opcaoEscolhidaNumerica = int.Parse(opcaoEscolhida);
    
    switch(opcaoEscolhidaNumerica)
    {
        case 1: RegistrarBanda();
            break;
        case 2: MostrarBandas();
            break;  
        case 3: AvaliarUmaBanda();
            break;
        case 4: MediaBanda();
            break;
        case 5: Console.WriteLine("Você escolheu a opção " + opcaoEscolhida);
            break;
        default: Console.WriteLine("Opção inválida");
            break;

    }

}
void RegistrarBanda()
{
    Console.Clear();
    ExibirTituloDaOpcao("Registro da banda");
    Console.Write("Digite o nome da banda que deseja registrar: ");
    string nomeDaBanda = Console.ReadLine()!;
    bandasRegistradas.Add(nomeDaBanda, new List<int>());
    Console.WriteLine($"A banda {nomeDaBanda} foi registrada com sucesso");
    Thread.Sleep(1000);
    Console.Clear();
    ExibirOpicoes();
}

void MostrarBandas()
{
    Console.Clear();
    ExibirTituloDaOpcao("Exibindo todas as bandas registradas");
    //for(int i = 0; i < listaDasBandas.Count; i++)
    //{
    //    Console.WriteLine($"{i + 1} - {listaDasBandas[i]}");
    //}
    foreach (string banda in bandasRegistradas.Keys)
    {
        Console.WriteLine($"Banda: {banda}");
    }
    Thread.Sleep(1500);
    Console.Clear();
    ExibirOpicoes();

}
void AvaliarUmaBanda()
{
    Console.Clear();
    ExibirTituloDaOpcao("Avaliar uma banda");
    Console.Write("Digite o nome da banda que deseja avaliar:");
    string banda = Console.ReadLine()!;
    if(bandasRegistradas.ContainsKey(banda))
    {
        Console.Write($"Digite a nota para a banda {banda}: ");
        string nota = Console.ReadLine()!;
        int notaInt = int.Parse(nota);
        bandasRegistradas[banda].Add(notaInt);
        Console.WriteLine($"\nA nota {notaInt} foi registrada com sucesso para a banda {banda}");
        Thread.Sleep(1000);
        Console.Clear();
        ExibirOpicoes();
            
    }
    else
    {
        Console.WriteLine("A banda não foi encontrada");
        Console.WriteLine("Digite uma tecla para voltar ao menu principal.");
        Console.ReadKey();
        Console.Clear();
        ExibirOpicoes();
    }
}

void ExibirTituloDaOpcao(string titulo)
{
    int quantidadeDeLetras = titulo.Length;
    string asteriscos = string.Empty.PadLeft(quantidadeDeLetras,'*');
    Console.WriteLine(asteriscos);
    Console.WriteLine(titulo);
    Console.WriteLine(asteriscos + "\n");
}

void MediaBanda() 
{ 
    Console.Clear();
    ExibirTituloDaOpcao("Média da Banda");
    Console.Write("Digite o nome da banda que deseja verificar a média:");
    string banda = Console.ReadLine()!;
    int somaNotas = 0;

    if (bandasRegistradas.ContainsKey(banda) && bandasRegistradas[banda].Count != 0)
    {
        for (int i = 0;i < bandasRegistradas.Count;i++)
        {
             somaNotas += bandasRegistradas[banda][i];
        }
        int mediaNotas = somaNotas / bandasRegistradas.Count;
        Console.WriteLine($"\nA media das notas da banda é {mediaNotas}");
        Thread.Sleep(1000);
        Console.Clear();
        ExibirOpicoes();

    }
    else if(bandasRegistradas.Count != 0)
    {
        Console.WriteLine("A banda não possui notas.");
        Console.WriteLine("Digite uma tecla para voltar ao menu principal.");
        Console.ReadKey();
        Console.Clear();
        ExibirOpicoes();
    } else
    {
        Console.WriteLine("A banda não foi encontrada");
        Console.WriteLine("Digite uma tecla para voltar ao menu principal.");
        Console.ReadKey();
        Console.Clear();
        ExibirOpicoes();
    }
}

ExibirOpicoes();    