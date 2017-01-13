
public class Main {

	public static void main(String[] args) {
		ShapeFactory sf = new ShapeFactory();
		
		Quadrado q1 = (Quadrado) sf.getFigura("QUADRADO");
		Circulo c1 = (Circulo) sf.getFigura("CIRCULO");
		Retangulo r1 = (Retangulo) sf.getFigura("RETANGULO");
		
		r1.setNome("retangulo1");
		Retangulo r2 = r1.clone();
		
		System.out.println(r2.toString());
		
		System.out.println(q1.toString());
		q1.setNome("quadradoooo");
		Quadrado q2 = q1.clone();
		
		System.out.println(q2.toString());
	
		c1.setRaio(12.0);
		
		Circulo c2 = c1.clone();
		
		System.out.println(c2.toString());
		c1.setRaio(1);
		System.out.println(c1.toString());
	}
}
