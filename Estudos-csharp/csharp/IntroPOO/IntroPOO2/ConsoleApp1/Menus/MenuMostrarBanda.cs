using ConsoleApp1.Menus;
using ConsoleApp1.Modelos;

internal class MenuMostrarBanda : Menu
{
    public override void Executar(Dictionary<string, Banda> bandasRegistradas)
    {
            base.Executar(bandasRegistradas);
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
    }
}