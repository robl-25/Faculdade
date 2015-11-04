
public abstract class Conta {
	private double saldo;
	private int numero;
	
	//Seters
	public void setSaldo(double saldo){
		this.saldo = saldo;
	}
	public void setNumero(int numero){
		this.numero = numero;
	}
	
	//Geter
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
			throw new ValorInvalidoException("Quantia invalida!!!");
	}

	public void credita(double quantia) {
		if (quantia>0)
			saldo +=quantia;
		else
			System.err.println("não se pode creditar uma quantia negativa.");
	}

	public abstract void atualiza(double taxa);

	public void imprime() {
		System.out.println( "Conta " + numero + ": " + "saldo = " + saldo );
	}
}
