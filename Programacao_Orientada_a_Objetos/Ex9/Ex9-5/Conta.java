
public abstract class Conta {
	private double saldo;
	private int numero;
	private String nome;
	
	//Seters
	public void setSaldo(double saldo){
		this.saldo = saldo;
	}
	public void setNumero(int numero){
		this.numero = numero;
	}
	
	public void setNome(String nome){
		this.nome = nome;
	}
	
	//Geter
	public double getNumero() { return numero; }
	public double getSaldo() { return saldo; }
	public String getNome() { return this.nome; }
	
	//Construtor
	public Conta(int a, String nome) {
		saldo=0.0;
		numero=a;
		this.nome = nome;
	}
	
	//Métodos
	public void debita(double quantia) throws ValorInvalidoException, ValorMaiorException{
		if (quantia > 0 && quantia < saldo)
			saldo -= quantia;
		else if(quantia < 0)
			throw new ValorInvalidoException("Quantia invalida!!!");
		
		else if(quantia > this.saldo)
			throw new ValorMaiorException("Quantia maior que o saldo!!!!");
		
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
	
	public String toString(){
		return " - Numero da Conta: " + this.numero +
		"\n - Nome do Cliente: " + this.nome +
		"\n - Saldo: R$" + this.saldo;
	}
}
