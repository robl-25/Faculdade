
public class Sistema {

	public static void main(String[] args) {
		GatoQuantico gq = new GatoQuantico();
		
		Estado e1 = new EstadoVivo();
		gq.setEstado(e1);
		gq.miar();
		
		Estado e2 = new EstadoMorto();
		gq.setEstado(e2);
		gq.miar();
		
		Estado e3 = new EstadoQuantico();
		gq.setEstado(e3);
		gq.miar();
	}

}
