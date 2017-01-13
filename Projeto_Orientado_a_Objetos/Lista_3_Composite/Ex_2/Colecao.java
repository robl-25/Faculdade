import java.util.ArrayList;

public class Colecao implements Publicacao{
	
	private ArrayList<Publicacao> publicacoes = new ArrayList<Publicacao>();
	private String nome;
	
	Colecao(String nome) {
		this.nome = nome;
	}
	
	public ArrayList<Publicacao> getPublicacoes() {
		return publicacoes;
	}
	
	public void addPublicacao(Publicacao p) {
		publicacoes.add(p);
	}
	
	public String toString() {
		System.out.println(this.nome);
		for(Publicacao p : publicacoes){
			p.toString();
		}
		return "";
	}

	public int getNumPublicacoes() {
		int cont = 1;
		for(Publicacao p : publicacoes){
			cont += p.getNumPublicacoes();
		}
		return cont;
	}
	
}
