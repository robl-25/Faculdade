
public class Quadrado implements Figura,PrototypeCapable {

	private String nome = null;
	
	public String getNome() {
		return this.nome;
	}
	public void setNome(String n) {
		this.nome = n;
	}
	public Quadrado clone() {
		try {
			Quadrado c = (Quadrado)super.clone();
			return c;
		} catch (CloneNotSupportedException e) {return null;}
	}

	public String toString() {
		return "Quadrado: " + this.nome;
	}
}
