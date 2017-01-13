//import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class TestaOrdenacao {

	public static void main(String[] args) {
		int i;
		List<ContaPoupanca> conta = new LinkedList<>();
		
		for(i=0; i<3; i++){
			conta.add(new ContaPoupanca(i));
			conta.get(i).setSaldo(56+(5*i));
		}
		
		Collections.sort(conta);//Ordena
		Collections.reverse(conta);//Reverte a ordem
		Collections.shuffle(conta);//Embaralha os elementos
		Collections.rotate(conta, 1);//Rotaciona os elementos uma posicao
		
		for(i=0; i<3; i++){
			conta.get(i).imprime();
			System.out.println("\n");
		}
	}
}

//Nao eh preciso alterar coisa alguma para que o codigo funcione trocando o
//ArraysList pelo LinkedList.
