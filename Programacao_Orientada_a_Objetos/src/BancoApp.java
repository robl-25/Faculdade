import java.util.Arrays;


public class BancoApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Banco b = new Banco();
		ContaPoupanca p[] = new ContaPoupanca[3];
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
		}
		
		for(i=0; i<3; i++){
			p[i] = new ContaPoupanca(i);
			//p[i].setNumero(i);
			p[i].setSaldo(56+(5*i));
		}
		
		Arrays.sort(p);
		
		for(i=0; i<3; i++){
			p[i].imprime();
			System.out.println("\n");
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
