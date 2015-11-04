
public class ContaCorrente extends Conta implements Tributavel{

	public ContaCorrente(int a, String nome) {
		super(a, nome);
		// TODO Auto-generated constructor stub
	}
	
	public double calculaTributos(){
		return 0.1;
	}
	
	public void atualiza(double taxa) {
		super.setSaldo(super.getSaldo() + super.getSaldo()* 2 * taxa);
	}
	
	public void credita(double quantia) {
		super.credita(quantia-0.1);
	}
	
	public double getSaldo(){
		return super.getSaldo();
	}
	
	public String toString(){
		return super.toString() +
		"\n - Tipo de Conta: Conta Corrente";
	}
}
