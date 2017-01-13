
public class Circulo {

	private Ponto ponto1;
	private int raio;
	
	Circulo() {
		this.ponto1 = new Ponto();
		this.raio = 1;
	}
	
	Circulo(Ponto p, int raio) {
		this.ponto1 = p;
		this.raio = raio;
	}
	
	public double area(){
		return Math.PI * Math.pow(raio,2);
	}
	
	public Ponto getPonto() {
		return ponto1;
	}
}
