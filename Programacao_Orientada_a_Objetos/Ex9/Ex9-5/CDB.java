
public class CDB extends Conta implements Tributavel{
	
	public CDB(int a, String nome) {
		super(a, nome);
		// TODO Auto-generated constructor stub
	}

	public void atualiza(double taxa) {
		super.setSaldo(super.getSaldo() + super.getSaldo()* 2.5 * taxa);
	}
	
	public double calculaTributos(){
		return 42;
	}
	
	public String toString(){
		return super.toString() +
		"\n - Tipo de Conta: CDB";
	}
}
