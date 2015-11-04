import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;

public class TestaPerfomance {
	public static void main(String[] args) {
		System.out.println("Iniciando...");
		Collection<Integer> teste = new ArrayList<>();
		long inicio = System.currentTimeMillis();

		int total = 30000;

		for (int i = 0; i < total; i++) {
		teste.add(i);
		}

		for (int i = 0; i < total; i++) {
		teste.contains(i);
		}

		long fim = System.currentTimeMillis();
		long tempo = fim - inicio;
		System.out.println("Tempo gasto com ArrayList: " + tempo + " ms");
		
		Collection<Integer> teste_I = new LinkedList<>();
		
		inicio = System.currentTimeMillis();
		total = 30000;

		for (int i = 0; i < total; i++) {
		teste_I.add(i);
		}

		for (int i = 0; i < total; i++) {
		teste_I.contains(i);
		}

		fim = System.currentTimeMillis();
		tempo = fim - inicio;
		System.out.println("\nTempo gasto com LinkedList: " + tempo + " ms");
		
		Collection<Integer> teste_II = new HashSet<>();
		
		inicio = System.currentTimeMillis();
		total = 30000;

		for (int i = 0; i < total; i++) {
		teste_II.add(i);
		}

		for (int i = 0; i < total; i++) {
		teste_II.contains(i);
		}

		fim = System.currentTimeMillis();
		tempo = fim - inicio;
		System.out.println("\nTempo gasto com HashSet: " + tempo + " ms");
	}
}
