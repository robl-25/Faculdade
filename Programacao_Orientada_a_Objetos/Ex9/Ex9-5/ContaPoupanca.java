
public class ContaPoupanca extends Conta implements Comparable<ContaPoupanca>{
	
	public ContaPoupanca(int a, String nome){
		super(a, nome);
		// TODO Auto-generated constructor stub
	}
	
	public void atualiza(double taxa) {
		super.setSaldo(super.getSaldo() + super.getSaldo()* 3 * taxa);
	}
	
	public int compareTo(ContaPoupanca c){

		if(getSaldo() < c.getSaldo())
			return -1;
		
		else if(getSaldo() == c.getSaldo())
			return 0;
		
		else
			return 1;
	}
	
	public double calculaTributos(){
		return 0;
	}
	
	public String toString(){
		return super.toString() +
		"\n - Tipo de Conta: Conta Poupanca";
	}
}
