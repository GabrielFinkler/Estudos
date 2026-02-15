Episodio ep1 = new(45,1,"Técnicas de facilitação");
ep1.AdicionarConvidados("Marcelo");
ep1.AdicionarConvidados("Maria");

Episodio ep2 = new(67, 2, "Técnicas de 2");
ep2.AdicionarConvidados("Fernando");
ep2.AdicionarConvidados("Marcos");
ep2.AdicionarConvidados("Flavia");

Podcast pod1 = new("Gabriel", "Um Mundo de Magia");
pod1.AdicionarEpisodio(ep1);
pod1.AdicionarEpisodio(ep2);
pod1.ExibirDetalhes();
