class Episodio
{
    public Episodio(int duracao, int ordem, string titulo)
    {
        Duracao = duracao;
        Ordem = ordem;  
        Titulo = titulo;
    }

    private List<string> convidados = new List<string>();
    public int Duracao { get; }
    public int Ordem { get; }
    public string Titulo { get; }
    public string Resumo => $"{Ordem}. {Titulo} ({Duracao}) min {string.Join(", ", convidados)}";
    


    public void AdicionarConvidados(string convidado)
    {
        convidados.Add(convidado); 
    }
}