
public class BancoApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Banco b = new Banco();
		int i;
		
		for(i=0; i<10; i+=2){
			b.getConta()[i] = new ContaCorrente(i);
			b.getConta()[i].credita(25+i);
			b.getConta()[i].atualiza(2+(i+1));
			b.getConta()[i+1] = new ContaPoupanca(i+1);
			b.getConta()[i+1].credita(25+(i+1));
			b.getConta()[i].atualiza(2+(i));
		}
		
		for(i=0; i<10; i+=2){
			b.registra(b.getConta()[i]);
			b.registra(b.getConta()[i+1]);
			b.getConta()[i].imprime();
			b.getConta()[i+1].imprime();
		}
		
		b.exibe();
	}

}