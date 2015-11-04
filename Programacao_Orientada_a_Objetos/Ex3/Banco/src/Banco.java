
public class Banco {
	private double total;
	
	//Construtor
	public Banco(){ 
		total = 0;
	}
	
	private Conta[] conta = new Conta[10];
	
	
	
	//Metodos
	public void registra(Conta c){
		total += c.getSaldo();
	}
	public void exibe(){
		System.out.println("O total de saldo eh: " + total);
	}
	public Conta[] getConta() {
		return conta;
	}
	public void setConta(Conta[] conta) {
		this.conta = conta;
	}
	
}
