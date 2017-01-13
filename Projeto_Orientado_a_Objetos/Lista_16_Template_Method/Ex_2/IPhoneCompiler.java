
public class IPhoneCompiler extends CrossCompiler<IPhoneCompiler> {

  protected void collectSource(IPhoneCompiler p) {
    System.out.println("Colentado com o Iphone!");
  }

  protected void compileToTarget(IPhoneCompiler p) {
	  System.out.println("Compilando com o Iphone!");
  }
}