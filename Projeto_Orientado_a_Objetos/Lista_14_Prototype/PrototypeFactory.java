import java.util.HashMap;

public class PrototypeFactory {

	public static class ModelType {
		public static final String RETANGULO = "retangulo";
		public static final String QUADRADO = "quadrado";
		public static final String CIRCULO = "circulo";
	}
	private static HashMap<String, PrototypeCapable> prototipos = new HashMap<String, PrototypeCapable>();
	
	static {
		prototipos.put(ModelType.CIRCULO, new Circulo());
		prototipos.put(ModelType.QUADRADO, new Quadrado());
		prototipos.put(ModelType.RETANGULO, new Retangulo());
	}
	
	public static PrototypeCapable getInstance(final String s) throws CloneNotSupportedException {
		return ((PrototypeCapable) prototipos.get(s)).clone();
	}
}
