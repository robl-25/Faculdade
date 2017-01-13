
public class AndroidCompiler extends CrossCompiler<AndroidCompiler> {

  protected void collectSource(AndroidCompiler c) {
	  System.out.println("Colentado com o Android!");
  }

  protected void compileToTarget(AndroidCompiler c) {
	  System.out.println("Compilando com o Android!");
  }
}