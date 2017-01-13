
public interface Observable {

	public Integer getInd();
	public void notificar();
	public Double getTemperatura();
	public Double getPressao();
	public Double getNivel();
	public void cadastrar(Observador o);
	public void remover(Observador o);
}
