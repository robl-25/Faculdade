
public class ValorInvalidoException extends RuntimeException {
	private String frase;
	
	public ValorInvalidoException(String rase){
		super(rase);
	}
	
	public void setFrase(String frase){
		this.frase = frase;
	}
	
	public String getFrase(){
		return this.frase;
	}
}
