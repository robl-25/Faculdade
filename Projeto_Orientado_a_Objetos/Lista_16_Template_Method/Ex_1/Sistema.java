import java.util.Arrays;

public class Sistema {

	public static void main(String[] args) {
		Palavras a[] = new Palavras[6];
		a[0] = new Palavras("amo");
		a[1] = new Palavras("padre");
		a[2] = new Palavras("corredor");
		a[3] = new Palavras("ama");
		a[4] = new Palavras("mari");
		a[5] = new Palavras("pou");
		
		Arrays.sort(a, new ComparaPalavras());
		
		for(int i = 0; i < a.length; i++){
			System.out.println(a[i].getPalavra());
		}
	}

}
