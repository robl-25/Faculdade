
public class QuadradoApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Figura q1 = new Quadrado();
		int i;
		double s=0;
		for(i=0; i<10; i++){
			q1.setLado(Math.random());
			s += q1.area();
		}
		System.out.println("A soma eh: " + s);
	}
}
