
public class ContadorApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Contador c1 = new Contador(7);
		//c1.setContador(13);
		c1.decrementaValor();
		c1.incrementaComValorDado(15);
		c1.decrementaComValorDado(22);
		c1.incrementaValor();
		c1.visualiza();
	}

}
