
public class CarbonFootprintApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CarbonFootprint[] c = new CarbonFootprint[6];
		int i;
		
		for(i=0; i<6; i+=3){
			c[i] = new Car();
			//c[i].setCapacidade(5);
			c[i+1] = new Bicycle();
			c[i+2] = new Building();
		}
		
		
	}

}
