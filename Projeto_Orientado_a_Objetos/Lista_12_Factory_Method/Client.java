
public class Client {
	
	public static void main(String[] args) {
		
		Figura figura = ShapeFactory.getFigura("Circulo");
		System.out.println(figura.area());
		
		figura = ShapeFactory.getFigura("Quadrado");
		System.out.println(figura.area());
		
		figura = ShapeFactory.getFigura("TrEquilatero");
		System.out.println(figura.area());
		
		figura = ShapeFactory.getFigura("oi");
		System.out.println(figura.area());
	}
}
