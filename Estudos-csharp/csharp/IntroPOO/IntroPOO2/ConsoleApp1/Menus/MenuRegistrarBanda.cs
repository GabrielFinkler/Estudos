using ConsoleApp1.Modelos;

namespace ConsoleApp1.Menus;

internal class MenuRegistrarBanda : Menu 
{
    public override void Executar(Dictionary<string, Banda> bandasRegistradas)
    {
        base.Executar(bandasRegistradas);
        ExibirTituloDaOpcao("Registro da banda");
        Console.Write("Digite o nome da banda que deseja registrar: ");
        string nomeDaBanda = Console.ReadLine()!;
        Banda banda = new(nomeDaBanda);
        bandasRegistradas.Add(nomeDaBanda, banda);
        Console.WriteLine($"A banda {nomeDaBanda} foi registrada com sucesso");
        Thread.Sleep(1000);
        Console.Clear();
    }
}
