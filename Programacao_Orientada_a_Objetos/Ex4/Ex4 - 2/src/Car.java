
public class Car implements CarbonFootprint{
	private int capacidade;
	private float cilindrada;
	private String modelo, combustivel;
	private double aux;
	
	//Seters
	public void setCapacidade(int capacidade){
		this.capacidade = capacidade;
	}
	public void setCilidrada(float cilindrada){
		this.cilindrada = cilindrada;
	}
	public void setModelo(String modelo){
		this.modelo = modelo;
	}
	public void setCombustivel(String combustivel){
		this.combustivel = combustivel;
	}
	
	//Geters
	public int getCapacidade(){
		return capacidade;
	}
	public float getCilidrada(){
		return cilindrada;
	}
	public String getModelo(){
		return modelo;
	}
	public String getCombustivel(){
		return combustivel;
	}
	@Override
	public double calculaCarbonFootprint() {
		aux = cilindrada*0.7 + capacidade*0.1;
		return aux;
	}
}
