
public class Main {

	public static void main(String[] args) {
		InstitutoDePesquisa I1 = new InstitutoDePesquisa();
		InstitutoDePesquisa I2 = new InstitutoDePesquisa();
		I1.setNotificar(false);
		
		PostoDeColeta P1 = new PostoDeColeta(11.3, 15.2, 18.9);
		PostoDeColeta P2 = new PostoDeColeta(5.1, 20.4, 19.3);
		PostoDeColeta P3 = new PostoDeColeta(222.1, 10.4, 200.0);
		
		I1.cadastrar(P1);
		I1.cadastrar(P2);
		
		I2.cadastrar(P2);
		I2.cadastrar(P3);
		
		System.out.println("======Instituto 1======");
		I1.getString();
		System.out.println("======Instituto 2======");
		I2.getString();
		
		P2.setPressao(15.0);
		P2.notificar();
		
		System.out.println("======Instituto 1======");
		I1.getString();
		System.out.println("======Instituto 2======");
		I2.getString();
	}

}
