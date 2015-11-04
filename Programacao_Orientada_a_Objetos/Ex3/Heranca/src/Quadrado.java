
public class Quadrado extends Figura {
	private double lado;
	
	//Construtores
	Quadrado(){}
	
	//Set's
	public void setLado(double lado){
		this.lado = lado;
	}
	
	//Get's
	public double getLado(){
		return lado;
	}
	
	//Metodos
	public double area(){
		return (lado*lado);
	}
	
	public void Aumentar(){
		lado++;
	}
}
