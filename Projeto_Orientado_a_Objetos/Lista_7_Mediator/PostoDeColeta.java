import java.util.ArrayList;

public class PostoDeColeta implements Observable{
	
	private ArrayList<Observador> observadores = new ArrayList<Observador>();
	private Integer ind;
	private Double temperatura;
	private Double pressao;
	private Double nivel;
	private static Integer cont = 0;
	
	PostoDeColeta() {
		this.ind = cont;
		PostoDeColeta.cont++;
	}
	
	PostoDeColeta(Double t, Double p, Double n) {
		this.ind = cont;
		PostoDeColeta.cont++;
		this.temperatura = t;
		this.pressao = p;
		this.nivel = n;
	}
	
	public Integer getInd() {
		return this.ind;
	}
	public void setTemperatura(Double temperatura) {
		this.temperatura = temperatura;
	}
	public void setPressao(Double pressao) {
		this.pressao = pressao;
	}
	public void setNivel(Double nivel) {
		this.nivel = nivel;
	}
	public Double getTemperatura() {
		return temperatura;
	}
	public Double getPressao() {
		return pressao;
	}
	public Double getNivel() {
		return nivel;
	}
	public void cadastrar(Observador o) {
		this.observadores.add(o);
	}
	public void remover(Observador o) {
		this.observadores.remove(o);
	}
	public void notificar(){
		for(Observador o:this.observadores) {
			o.atualizar(this.ind);
		}
	}
	
}
