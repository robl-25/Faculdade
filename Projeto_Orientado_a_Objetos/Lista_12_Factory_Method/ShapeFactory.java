
public class ShapeFactory {
	
	public static Figura getFigura(String type) {
		Figura figura = new Figura();
		return figura.getFigura(type);
	}
}
