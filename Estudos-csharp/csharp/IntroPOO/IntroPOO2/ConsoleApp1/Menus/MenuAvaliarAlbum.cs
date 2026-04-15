using ConsoleApp1.Modelos;

namespace ConsoleApp1.Menus;

internal class MenuAvaliarAlbum : Menu
{
    public override void Executar(Dictionary<string, Banda> bandasRegistradas)
    {
        base.Executar(bandasRegistradas);
        ExibirTituloDaOpcao("Avaliar álbum");
        Console.Write("Digite o nome do álbum que deseja avaliar:");
        string nomeDaBanda = Console.ReadLine()!;
        if (bandasRegistradas.ContainsKey(nomeDaBanda))
        {
            Banda banda = bandasRegistradas[nomeDaBanda];
            Console.Write($"Digite a nota para a banda {nomeDaBanda}: ");
            string nota = Console.ReadLine()!;
            banda.AdicionarNota(Avaliacao.Parse(nota));
            Console.WriteLine($"\nA nota {nota} foi registrada com sucesso para a banda {nomeDaBanda}");
            Thread.Sleep(1000);
            Console.Clear();

        }
        else
        {
            Console.WriteLine("A banda não foi encontrada");
            Console.WriteLine("Digite uma tecla para voltar ao menu principal.");
            Console.ReadKey();
            Console.Clear();
        }
}
