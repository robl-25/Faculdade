
public class Retangulo {

	private Ponto ponto1;
	private Ponto ponto2;
	
	Retangulo() {
		this.ponto1 = new Ponto();
		this.ponto2 = new Ponto(2,2);
	}
	
	Retangulo(Ponto p1, Ponto p2) {
		this.ponto1 = p1;
		this.ponto2 = p2;
	}
	
	public double getArea(){
		return Math.abs(ponto1.getX() - ponto2.getX()) *
				Math.abs(ponto1.getY() - ponto2.getY());
	}
}
