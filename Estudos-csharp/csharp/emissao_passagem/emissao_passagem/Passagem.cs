using System.Collections.Concurrent;

class Passagem
{
    public Passagem(string nome, string destino)
    {
        Nome = nome;
        Destino = destino;
    }

    public string Nome { get; set; }
    public string Destino { get; set; }

    public void MostrarBilhete()
    {
        Console.WriteLine($"Nome do passageiro: {Nome}");
        Console.WriteLine($"Destino da viagem: {Destino}");
    }
}