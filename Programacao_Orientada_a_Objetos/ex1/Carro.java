package carro;

public class Carro {
	private int velocidade;
	private int vezesAcelerou,vezesFreiou;
	
	//Set's
	public void setVelocidade(int velocidade){
		this.velocidade = velocidade;
	}
	
	//Get's
	public int getVelocidade(){
		return velocidade;
	}
	
	//Metodos
	public int Acelerar(int a){
		System.out.println("Acelerando o carro para velocidade " + 
							a + " km/h\n");
		vezesAcelerou ++;
		return velocidade += a;
	}
	
	public int Frear(){
		System.out.println("Freiando o carro\n");
		vezesFreiou ++;
		return velocidade --;
	}
	
	public void vezesAcelerou(){
		System.out.println("Vezes que o carro acelerou: " + 
							vezesAcelerou + "\n");
	}
	
	public void vezesFreiou(){
		System.out.println("Vezes que o carro freiou: " + 
								vezesFreiou + "\n");
	}
}
