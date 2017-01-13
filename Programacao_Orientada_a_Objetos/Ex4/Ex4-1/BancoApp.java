import java.io.*;


public class BancoApp {

	public static void main(String[] args){
		// TODO Auto-generated method stub
		Banco b = new Banco();
		int i;
		PrintWriter pw;
		
		for(i=0; i<9; i+=3){
			try{
				b.CriaBanco(new ContaPoupanca(i));
				b.CriaBanco(new ContaCorrente(i+1));
				b.CriaBanco(new CDB(i+2));
			}catch(ExcecaoElementoJaExistente elementoJaExiste){
				System.out.println(elementoJaExiste.getMessage());
			}
			
		}
		
		b.getConta()[0].setNome("Pamela");
		b.getConta()[1].setNome("Maria");
		b.getConta()[2].setNome("João");
		b.getConta()[3].setNome("Fernando");
		b.getConta()[4].setNome("Paulo");
		b.getConta()[5].setNome("Carla");
		b.getConta()[6].setNome("Lara");
		b.getConta()[7].setNome("Nathan");
		
		
		for(i=0; i<9; i+=3){
			b.getConta()[i].credita(2+i);
			b.getConta()[i].atualiza(2+(i+1));
			b.getConta()[i+1].credita(5+(i+1));
			b.getConta()[i+1].atualiza(2+(i));
			b.getConta()[i+2].credita(19+(i+2));
			b.getConta()[i+2].atualiza(30+(i));
			
			try{
				b.getConta()[i].debita(80);
				
			}catch(ValorInvalidoException quantiaErrada){
				System.out.println(quantiaErrada.getMessage());
			}
			catch(ValorMaiorException quantiaMaior){
				System.out.println(quantiaMaior.getMessage());
			}
		}
		
		for(i=0; i<9; i+=3){
			b.registra(b.getConta()[i]);
			b.registra(b.getConta()[i+1]);
			b.getConta()[i].imprime();
			b.getConta()[i+1].imprime();
			b.getConta()[i+2].imprime();
		}
		
		try{
			pw = new PrintWriter(new FileWriter("Teste.txt"));
			b.Salva(pw);
			pw.close();
		}
		catch(IOException e){
			System.out.println(e.getMessage());
		}
		
		b.exibe();
	}
}
