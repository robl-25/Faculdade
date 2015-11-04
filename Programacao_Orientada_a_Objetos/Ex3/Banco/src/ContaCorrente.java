
public class ContaCorrente extends Conta {
	
	public ContaCorrente(int a){
		super(a);		
	}
	
	public void atualiza(double taxa) {
		super.atualiza(2*taxa); 
	}
	
	public void credita(double quantia) {
		super.credita(quantia-0.1);
	}
	
	public double getSaldo(){
		return super.getSaldo();
	}
}
