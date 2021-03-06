
public class Desenho {	
	public static void main(String[] args){
		Figura[] a = new Figura[9];
		Quadrado auxQ;
		Triangulo auxT;
		Retangulo auxR;
		int i;
		double b;
		
		for(i=0; i<9; i+=3){
			a[i] = (Figura) new Quadrado();
			a[i+1] = (Figura) new Triangulo();
			a[i+2] = (Figura) new Retangulo();
		}
		
		//Verifica que tipo eh e chama a funcao dele
		for(i=0; i<9; i++){
			if(a[i] instanceof Quadrado){
				auxQ = (Quadrado) a[i];
				auxQ.setLado(10);
				b = auxQ.area();
				auxQ.setLado(b);
				auxQ.Aumentar();
				System.out.println("\n");
				System.out.println("A area do quadrado eh " + auxQ.area());
				System.out.println("O lado do quadrado eh " + auxQ.getLado());
			}
			
			else if(a[i] instanceof Triangulo){
					auxT = (Triangulo) a[i];
					auxT.setAltura(12);
					auxT.setBase(9);
					System.out.println("\n");
					auxT.mostra();
					System.out.println ("A area do triangulo eh: " + 
											auxT.area());
				}
			else if(a[i] instanceof Retangulo){
				auxR = (Retangulo) a[i];
				auxR.setAltura(12);
				auxR.setBase(33);
				System.out.println("\n");
				System.out.println("A area do retangulo eh: " + auxR.area());
				auxR.imprimir();
				System.out.println("O perimetro do retangulo eh: " + 
									auxR.perimetro());
				System.out.println("O retangulo eh quadrado? " + 
									auxR.quadrado());
				System.out.println("A relacao da base pela altura eh: " + 
									auxR.relacao());
			}
		}	
	}
}
