namespace ConsoleApp1.Modelos;

public class Album : IAvaliavel
{
    public static int ContadorDeObjetos = 0;
    private List<Avaliacao> notas = new(); 
    public Album(string nome)
    {
        Nome = nome;
        ContadorDeObjetos++;
    }
    private List<Musica> musicas = new List<Musica>();
    public string Nome { get; }
    public int DuracaoTotal => musicas.Sum(m => m.Duracao);

    public double Media 
    {
        get
        {
            if (notas.Count == 0) return 0;
            else notas.Average(a => a.Nota);
        }
    }

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

    public void AdicionarNota(Avaliacao nota)
    {
        notas.Add(nota);
    }
}