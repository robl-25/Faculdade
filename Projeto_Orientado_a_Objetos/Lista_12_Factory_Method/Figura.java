
public class Figura {
	
	public Figura getFigura(String type) {
		if (type == "Circulo")
			return new Circulo();
		else if (type == "Quadrado")
			return new Quadrado();
		else if (type == "TrEquilatero")
			return new TrEquilatero();
		return new Figura();
	}

	public String area() {
		return "não há elemento desse tipo.";
	}
}
