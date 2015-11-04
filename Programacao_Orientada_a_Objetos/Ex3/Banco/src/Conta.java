
public class Conta {
	protected double saldo;
	protected int numero;
		
	//Get's
	public double getNumero() { return numero; }
	public double getSaldo() { return saldo; }
	
	//Construtor
	public Conta(int a) {
		saldo=0.0;
		numero=a;
	}
	
	//Métodos
	public void debita(double quantia) {
		if (quantia > 0)
			saldo -= quantia;
		else
			System.err.println("não se pode debitar uma quantia negativa.");
	}

	public void credita(double quantia) {
		if (quantia>0)
			saldo +=quantia;
		else
			System.err.println("não se pode creditar uma quantia negativa.");
	}

	public void atualiza(double taxa) {
		this.saldo += this.saldo * taxa; 
	}

	public void imprime() {
		System.out.println( "Conta " + numero + ": " + "saldo = " + saldo );
	}
}
