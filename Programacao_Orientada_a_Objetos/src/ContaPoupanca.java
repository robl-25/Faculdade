
public class ContaPoupanca extends Conta implements Comparable<ContaPoupanca>{
	
	private String nomeDoCliente;
	
	public ContaPoupanca(int a) {
		super(a);
		// TODO Auto-generated constructor stub
	}
	
	public void setNome(String nomeDoCliente){
		this.nomeDoCliente = nomeDoCliente;
	}
	
	public String getNome(){
		return this.nomeDoCliente;
	}
	
	public void atualiza(double taxa) {
		super.setSaldo(super.getSaldo() + super.getSaldo()* 3 * taxa);
	}
	
	public int compareTo(ContaPoupanca c){

		return this.nomeDoCliente.compareTo(c.getNome());
	}
}
