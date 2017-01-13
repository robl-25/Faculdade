
public class Retangulo implements PrototypeCapable, Figura {
	
	private String nome = null;
	
    public String getNome() {
        return nome;
    }
    public void setNome(String n) {
        this.nome = n;
    }
    public Retangulo clone() {
		try {
			Retangulo c = (Retangulo)super.clone();
			return c;
		} catch (CloneNotSupportedException e) {return null;}
	}

	public String toString() {
        return "Retangulo: " + this.nome;
    }

}
