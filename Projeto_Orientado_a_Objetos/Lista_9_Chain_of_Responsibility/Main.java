import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String[] args) {
		A a = new A();
		Espaco e = new Espaco();
		Ponto p = new Ponto();
		a.setSucessor(e);
		e.setSucessor(p);
		
		String texto = new String(new Scanner(System.in).nextLine());
		
		a.run(texto);
	}

}
