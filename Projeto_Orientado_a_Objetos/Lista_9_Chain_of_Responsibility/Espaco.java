
public class Espaco implements ProcessadorDeTexto {

	private ProcessadorDeTexto sucessor;
	
	public void setSucessor(ProcessadorDeTexto s) {
		this.sucessor = s;
	}
	
	public void run(String s) {
		int counter = 0;
		for( int i=0; i<s.length(); i++ ) {
		    if( s.charAt(i) == ' ' ) {
		        counter++;
		    } 
		}
		System.out.println("Espaços na String: "+counter);
		this.sucessor.run(s);
	}

}
