
public class ContaPoupanca extends Conta {
	
	public ContaPoupanca(int a){
		super(a);		
	}
	
	public void atualiza(double taxa) {
		super.atualiza(3*taxa); 
	}
	
	public double getSaldo(){
		return super.getSaldo();
	}
}
