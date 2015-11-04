package carro;

public class CarroApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Carro c1 = new Carro();
		c1.setVelocidade(15);
		c1.Acelerar(3);
		c1.Frear();
		c1.Frear();
		c1.Frear();
		c1.Acelerar(9);
		c1.vezesAcelerou();
		c1.vezesFreiou();
	}

}
