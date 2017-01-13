
public class GatoQuantico {
	
	private Estado estado;
	
	public void setEstado(Estado estado) {
		this.estado = estado;
	}
	
	public void miar() {
		estado.miar();
	}
}
