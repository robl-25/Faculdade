import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class App {

	public static void main(String[] args) {
		BufferedReader sysin = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Escreva o nome da classe: ");
		String nome = null;
		try {
			nome = sysin.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		System.out.print("Escreva a mensagem: ");
		String msg = null;
		try {
			msg = sysin.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		MakeClass mtc = new MakeClass(nome, msg);
	    try {
			mtc.createIt();
		} catch (IOException e) {
			System.out.println("Deu ruim");
			e.printStackTrace();
		}
	}

}
