
public class Artigo implements Publicacao {

	private String nome;
	private String autor;
	
	Artigo(String nome, String autor) {
		this.nome = nome;
		this.autor = autor;
	}
	
	public int getNumPublicacoes() {
		return 1;
	}
	
	public String toString() {
		System.out.println("	nome: " + this.nome +" autor: "+this.autor);
		return "";
	}

}
