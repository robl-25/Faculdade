
public class Banco {

	private double total;
	private int i=0, j;
	private Conta[] conta = new Conta[9];
	
	//Construtor
	public Banco(){ 
		total = 0;
	}
	
	//Metodos
	public void CriaBanco(Conta c){
		conta[i] = c;
		i++;
	}
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
	
	public Conta buscaPorNome(String nome){
		
		for(j=0; j<i; j++){
			if(conta[j] instanceof ContaPoupanca){
				ContaPoupanca c = (ContaPoupanca) conta[i];
				if(c.getNome().equals(nome)){
					return conta[j];
				}
			}
		}
		return null;
	}
}
