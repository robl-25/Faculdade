
import java.util.Arrays;


public class testeOrdenacaoI {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ContaPoupanca p[] = new ContaPoupanca[3];
		int i;
		
		for(i=0; i<3; i++){
			p[i] = new ContaPoupanca(i);
			p[i].setNumero(i);
			p[i].setSaldo(56+(5*i));
		}
		
		Arrays.sort(p);
		
		for(i=0; i<3; i++){
			p[i].imprime();
			System.out.println("\n");
		}
	}

}
