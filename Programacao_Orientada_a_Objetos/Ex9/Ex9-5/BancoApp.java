import java.io.*;


public class BancoApp {

	public static void main(String[] args){
		// TODO Auto-generated method stub
		BufferedReader br;
		Banco b = new Banco();
				
		try{
			br = new BufferedReader(new FileReader("Teste.txt"));
			b.Recupera(br);
			br.close();
		}
		catch(IOException e){
			System.out.println(e.getMessage());
		}
		
		b.exibe();
	}
}
