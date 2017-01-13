import java.util.Comparator;

public class ComparaPalavras implements Comparator<Object> {
	
	@Override
	public int compare(Object a, Object b) {
		char a1 = ((Palavras)a).getPalavra().charAt(((Palavras)a).getPalavra().length() - 1);;
		char b1 = ((Palavras)b).getPalavra().charAt(((Palavras)b).getPalavra().length() - 1);;
		if (a1 > b1) return 1;
		if (a1 < b1) return -1;
		return 0;
	}

}
