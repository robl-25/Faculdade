
public class ShapeFactory {

	public Figura getFigura(String tipo) {
		if (tipo.equalsIgnoreCase("CIRCULO")) {
			return new Circulo();
		} else if (tipo.equalsIgnoreCase("QUADRADO")) {
			return new Quadrado();
		} else if(tipo.equalsIgnoreCase("RETANGULO")) {
			return new Retangulo();
		}
		return null;
	}
	
	public Circulo createCirculo(Circulo c) {
		Circulo a = c.clone();
		return a;
	}
}
