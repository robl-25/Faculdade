
public class Contador {
	private int contador;
	
	//Contrutores
	Contador(){};
	Contador(int contador){
		this.contador = contador;
	}
	
	//Metodos	
	public void incrementaValor(){
		contador += 1;
	}
	
	public void decrementaValor(){
		contador -= 1;
	}
	
	public void incrementaComValorDado(int valor){
		contador += valor;
	}
	
	public void decrementaComValorDado(int valor){
		contador -= valor;
	}
	
	public void visualiza(){
		System.out.println("O valor do contador eh: " + contador);
	}
	
	//Set's
	public void setContador(int novo_contador){
		contador = novo_contador;
	}
	
	//Get's
	public int getContador(){
		return contador;
	}
}
