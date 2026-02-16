namespace ConsoleApp1.Modelos;

internal class Album
{
    public static int ContadorDeObjetos = 0;
    public Album(string nome)
    {
        Nome = nome;
        ContadorDeObjetos++;
    }
    private List<Musica> musicas = new List<Musica>();
    public string Nome { get; }
    public int DuracaoTotal => musicas.Sum(m => m.Duracao);
    

    public void AdicionarMusica(Musica musica)
    {
        musicas.Add(musica);
    }

    public void ExibirMusicasDoAlbum()
    {
        Console.WriteLine($"Lista de músicas do album {Nome}: \n");
        foreach (var musica in musicas)
        {
            Console.WriteLine($"Música: {musica.Nome}");
        }
        Console.WriteLine($"tempo total {DuracaoTotal}");
    }
}