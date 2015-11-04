
public class Building implements CarbonFootprint{
	private int pessoas, numeroLampadas;
	private boolean energiaRenovavel, usoAr;
	private double aux;
	
	//Seters
	public void setPessoas(int pessoas){
		this.pessoas = pessoas;
	}
	public void setEnergia(boolean EnergiaRenovavel){
		this.energiaRenovavel = EnergiaRenovavel;
	}
	public void setNumeroLampadas(int numeroLampadas){
		this.numeroLampadas = numeroLampadas;
	}
	public void setUsoAr(boolean usoAr){
		this.usoAr = usoAr;
	}
	
	//Geters
	public int getPessoas(){
		return pessoas;
	}
	public int getNuLampadas(){
		return numeroLampadas;
	}
	public boolean getEnergia(){
		return energiaRenovavel;
	}
	public boolean getUsoAr(){
		return usoAr;
	}
	@Override
	public double calculaCarbonFootprint() {
		// TODO Auto-generated method stub
		aux = pessoas*0.6;
		aux += numeroLampadas*0.1;
		//aux += pessoas*usoAr*0.2;
		//aux -= energiaRenovavel*0.5;
		return aux;
	}
}
