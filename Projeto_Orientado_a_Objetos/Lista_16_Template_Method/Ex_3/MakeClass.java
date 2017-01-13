import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import javax.tools.JavaCompiler;
import javax.tools.ToolProvider;


public class MakeClass {
	private String nome;
	private String msg;
	private String arquivo;
 
	MakeClass(String nome, String msg) {
		this.nome = nome;
		this.msg = msg;
		this.arquivo = "src/"+ nome +".java";
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public String getArquivo() {
		return this.arquivo;
	}
	
	public void createIt() throws IOException {
		File sourceFile = new File(this.arquivo);
	      FileWriter writer = new FileWriter(sourceFile);
	      writer.write("public class "+this.nome+" extends Postman { \n" +
	      " public void enviaMensagem() { \n"
	          + " System.out.println(\""+this.msg+"\");\n"
	      + " }\n" + "}");
	      writer.close();

	      // Compila o arquivo
	      JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
	      compiler.run(null, null, null, this.arquivo);
		  System.out.println("Arquivo: ("+this.arquivo+") compilado com sucesso!");
	      try {
			runIt();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (InstantiationException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		}
	}
	
	@SuppressWarnings("resource")
	public void runIt() throws MalformedURLException, ClassNotFoundException, InstantiationException, IllegalAccessException {
		URLClassLoader classLoader = new URLClassLoader(new URL[]{new File("./").toURI().toURL()});
		Class<?> loadedClass = classLoader.loadClass("src."+nome);
		Object obj = loadedClass.newInstance();
		if (obj instanceof Postman) {
            // Cast to the DoStuff interface
            Postman stuffToDo = (Postman)obj;
            // Run it baby
            stuffToDo.enviaMensagem();
        } else {
        	System.out.println("blá");
        }
	  }
}
