class Podcast
{
    private List<Episodio> podcast = new List<Episodio>();
    public Podcast(string host, string nome)
    {
        Host = host;
        Nome = nome;    
    }

    public string Host { get; }
    public string Nome { get; }
    public int TotalEpisodios => podcast.Count;

    public void AdicionarEpisodio(Episodio episodio)
    {
        podcast.Add(episodio);
    }

    public void ExibirDetalhes()
    {
        Console.WriteLine($"Podcast {Nome} apresentado por {Host} \n");
        foreach (Episodio episodio in podcast.OrderBy(e=>e.Ordem))
        {
            Console.WriteLine(episodio.Resumo);
        }
        Console.WriteLine($"Este podcast possui {TotalEpisodios} episódios.");
    }
}