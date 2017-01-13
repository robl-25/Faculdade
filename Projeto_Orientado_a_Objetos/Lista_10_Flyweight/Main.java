import java.util.Random;

public class Main {

	public static void main(String[] args) {
		FlyWeightFactory fw = new FlyWeightFactory();
		
		Random random = new Random();
		
		System.out.println("Números gerados:");
		for(int j = 0; j < 10; j++) {
			for(int i = 0; i < 10; i++) {
				System.out.print(fw.getNumero(random.nextInt(9)).getString());
			}
			System.out.println("");

		}
		System.out.println("\nNumeros instanciados = " + fw.getSize());

	}

}
