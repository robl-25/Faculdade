
public class Bicycle implements CarbonFootprint{
	private String modelo, acessorios;
	
	//Seters
	public void setModelo(String modelo){
		this.modelo = modelo;
	}
	public void setAcessorios(String acessorios){
		this.acessorios = acessorios;
	}
	
	//Geters
	public String getModelo(){
		return modelo;
	}
	public String getAcessorios(){
		return acessorios;
	}
	@Override
	public double calculaCarbonFootprint() {
		// TODO Auto-generated method stub
		return 0;
	}
}
