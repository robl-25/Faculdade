import java.awt.Point;

public class Circulo implements Figura, PrototypeCapable {

	private Point origem;
	private double raio;
	
	Circulo(){
		this.origem = new Point();
		this.raio = 1;
	}
	Circulo (Point p, Integer r) {
		this.origem = p;
		this.raio = r;
	}
	public void setRaio(double a) {
		this.raio = a;
	}
	
	public Circulo clone() {
		try {
			Circulo c = (Circulo)super.clone();
			c.origem = (Point) origem.clone();
			return c;
		} catch (CloneNotSupportedException e) {return null;}
	}
	public String toString() {
		return "====Circulo====\n Origem: "+this.origem.toString()+"\n raio: "+this.raio;
	}

}
