
public class RetanguloApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Retangulo R1 = new Retangulo();
		R1.setAltura(12);
		R1.setBase(33);
		System.out.println("A area do retangulo eh: " + R1.area());
		R1.imprimir();
		System.out.println("O perimetro do retangulo eh: " + R1.perimetro());
		System.out.println("O retangulo eh quadrado? " + R1.quadrado());
		System.out.println("A relacao da base pela altura eh: " 
							+ R1.relacao());
	}

}
