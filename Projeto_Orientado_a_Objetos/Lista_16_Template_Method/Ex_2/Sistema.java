
public class Sistema {

	public static void main(String[] args) {
		
		System.out.println("Testando o IPhone:");
		IPhoneCompiler p = new IPhoneCompiler();
		p.crossCompile(p);
		
		System.out.println("\nTestando o android:");
		AndroidCompiler c = new AndroidCompiler();
		c.crossCompile(c);
		
	}

}
