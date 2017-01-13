
public class Ponto implements ProcessadorDeTexto {

	public void run(String s) {
		int counter = 0;
		for( int i=0; i<s.length(); i++ ) {
		    if( s.charAt(i) == '.' ) {
		        counter++;
		    } 
		}
		System.out.println("Pontos na String: "+counter);
	}

}
