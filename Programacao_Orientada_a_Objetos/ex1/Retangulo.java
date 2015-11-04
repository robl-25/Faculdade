
public class Retangulo extends Figura {
	private int altura, base;
	
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
	
	//Metodos
	public double area(){
		return base * altura;
	}
	
	public double perimetro(){
		return ((2*base)+(2*altura));
	}
	
	public double relacao(){
		return base/altura;
	}
	
	public boolean quadrado(){
		if(altura == base)
			return true;
		
		return false;
	}
	
	public void imprimir(){
		System.out.println("A altura do retangulo eh: " + altura + "\n");
		System.out.println("A base do retangulo eh: " + base);
	}
}
