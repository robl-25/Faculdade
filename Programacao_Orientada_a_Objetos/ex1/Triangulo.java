
public class Triangulo extends Figura {
	private int base, altura;
	
	//Construtores
	Triangulo(){}
	Triangulo(int base, int altura){
		this.base = base;
		this.altura = altura;
	}
	
	//Metodos
	public double area(){
		return (base * altura)/2;
	}
	public void mostra(){
		System.out.println("A base mede: "+ base + " e altura mede: "+ altura);
	}
	
	//Set's
	public void setAltura(int nova_altura){
		altura = nova_altura;
	}
	public void setBase(int nova_base){
		base = nova_base;
	}
	
	//Get's
	public int getAltura(){
		return altura;
	}
	public int getBase(){
		return base;
	}
}
