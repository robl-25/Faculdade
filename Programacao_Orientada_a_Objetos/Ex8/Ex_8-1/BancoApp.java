
public class BancoApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Banco b = new Banco();
		int i;
		
		
		for(i=0; i<9; i+=3){
			b.CriaBanco(new ContaPoupanca(i));
			b.CriaBanco(new ContaCorrente(i+1));
			b.CriaBanco(new CDB(i+2));
		}
		
		for(i=0; i<9; i+=3){
			b.getConta()[i].credita(25+i);
			b.getConta()[i].atualiza(2+(i+1));
			b.getConta()[i+1].credita(5+(i+1));
			b.getConta()[i+1].atualiza(2+(i));
			b.getConta()[i+2].credita(19+(i+2));
			b.getConta()[i+2].atualiza(30+(i));
			
			try{
				b.getConta()[i].debita(3-i);
				
			}catch(IllegalArgumentException quantiaErrada){
				System.out.println("\nQuantia invalida!!!\n");
			}
		}
		
		for(i=0; i<9; i+=3){
			b.registra(b.getConta()[i]);
			b.registra(b.getConta()[i+1]);
			b.getConta()[i].imprime();
			b.getConta()[i+1].imprime();
			b.getConta()[i+2].imprime();
		}
		
		b.exibe();
	}
}
