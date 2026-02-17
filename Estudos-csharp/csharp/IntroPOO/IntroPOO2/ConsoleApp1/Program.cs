using ConsoleApp1.Menus;
using ConsoleApp1.Modelos;
using System.Runtime.CompilerServices;

Banda ira = new Banda("Ira!");
Banda beatles = new Banda("The Beatles");
ira.AdicionarNota(new Avaliacao(10));
ira.AdicionarNota(new Avaliacao(8));
ira.AdicionarNota(new Avaliacao(6));

Dictionary<int, Menu> opcoes = new();
opcoes.Add(1, new MenuRegistrarBanda());
opcoes.Add(2, new MenuRegistrarAlbum());
opcoes.Add(3, new MenuMostrarBanda());
opcoes.Add(4, new MenuAvaliarBanda());
opcoes.Add(5, new MenuExibirDetalhes());



string mensagemDeBoasVindas = @"
░██████╗░█████╗░██████╗░███████╗███████╗███╗░░██╗  ░██████╗░█████╗░██╗░░░██╗███╗░░██╗██████╗░
██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗░██║  ██╔════╝██╔══██╗██║░░░██║████╗░██║██╔══██╗
╚█████╗░██║░░╚═╝██████╔╝█████╗░░█████╗░░██╔██╗██║  ╚█████╗░██║░░██║██║░░░██║██╔██╗██║██║░░██║
░╚═══██╗██║░░██╗██╔══██╗██╔══╝░░██╔══╝░░██║╚████║  ░╚═══██╗██║░░██║██║░░░██║██║╚████║██║░░██║
██████╔╝╚█████╔╝██║░░██║███████╗███████╗██║░╚███║  ██████╔╝╚█████╔╝╚██████╔╝██║░╚███║██████╔╝
╚═════╝░░╚════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░╚══╝  ╚═════╝░░╚════╝░░╚═════╝░╚═╝░░╚══╝╚═════╝░";

  

Dictionary<string, Banda> bandasRegistradas = new (); 
bandasRegistradas.Add(ira.Nome, ira);
bandasRegistradas.Add(beatles.Nome, beatles); 

void ExibirLogo()
{   
    Console.WriteLine(mensagemDeBoasVindas);
}

void ExibirOpicoes()
{
    ExibirLogo();
    Console.WriteLine("Selecione uma das opções abaixo: \n");
    Console.WriteLine("1 - Registrar uma banda");
    Console.WriteLine("2 - Registram um álbum");
    Console.WriteLine("3 - Mostrar bandas registradas");
    Console.WriteLine("4 - Avaliar uma banda");
    Console.WriteLine("5 - Exibir detalhes");

    Console.Write("\nDigite a sua opção: ");
    string opcaoEscolhida = Console.ReadLine()!;
    int opcaoEscolhidaNumerica = int.Parse(opcaoEscolhida);

    if (opcoes.ContainsKey(opcaoEscolhidaNumerica))
    {
        Menu menuASerExibido = opcoes[opcaoEscolhidaNumerica];
        menuASerExibido.Executar(bandasRegistradas);
        ExibirOpicoes();    
    }
    else
    {
        Console.WriteLine("Opção inválida");
    }
}
ExibirOpicoes();    