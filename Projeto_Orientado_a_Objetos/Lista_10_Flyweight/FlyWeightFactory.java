import java.util.HashMap;

public class FlyWeightFactory {

	HashMap<Integer, Numeros> numeros = new HashMap<Integer, Numeros>();
	
	public Numeros getNumero(Integer a) {
		NumeroImutavel num = new NumeroImutavel(a);
		if (numeros.containsKey(num)){
			return numeros.get(num);
		}
		
		numeros.put(a, num);
		return num;
	}
	public int getSize(){
		return numeros.size();
	}
}
