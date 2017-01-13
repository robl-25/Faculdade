
public class Main {

	public static void main(String[] args) {
		
		Colecao jornal = new Colecao("Science");
		Colecao caderno = new Colecao("Brazilian Science");
		Colecao revista = new Colecao("Machine Learning");
		
		Artigo a1 = new Artigo("bla1", "Pedro");
		Artigo a2 = new Artigo("bla2", "Nathan");
		Artigo a3 = new Artigo("bla3", "Fabio");
		Artigo a4 = new Artigo("bla4", "Ricardo");
		
		jornal.addPublicacao(caderno);
		caderno.addPublicacao(revista);
		jornal.addPublicacao(a1);
		caderno.addPublicacao(a2);
		revista.addPublicacao(a3);
		revista.addPublicacao(a4);
		
		jornal.toString();
		System.out.println("número de publicações: " +jornal.getNumPublicacoes());
	}

}
