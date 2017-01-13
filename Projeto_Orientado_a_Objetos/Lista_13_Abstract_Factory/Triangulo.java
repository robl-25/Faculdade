
public class Triangulo {
	
	private Ponto ponto1;
	private Ponto ponto2;
	private Ponto ponto3;
	
	Triangulo() {
		this.ponto1 = new Ponto();
		this.ponto2 = new Ponto(0,2);
		this.ponto3 = new Ponto(1,1);
	}
	
	Triangulo(Ponto p1, Ponto p2, Ponto p3) {
		this.ponto1 = p1;
		this.ponto2 = p2;
		this.ponto3 = p3;
	}
	
	public double area() {
		return Math.abs(ponto1.getX()*(ponto2.getY() - ponto3.getY()) +
				ponto2.getX()*(ponto3.getY() - ponto1.getY()) +
				ponto3.getX()*(ponto1.getY() - ponto2.getY()))/2;
	}
}
