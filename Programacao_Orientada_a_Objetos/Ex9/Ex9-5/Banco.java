import java.io.*;
import java.util.*;

public class Banco {

	private double total;
	private Map<String, Conta> conta;
	
	//Construtor
	public Banco(){ 
		total = 0;
	}
	
	//Metodos
	public void CriaBanco(Conta c) throws ExcecaoElementoJaExistente{
		
		this.total += c.getSaldo();
		this.conta.put(c.getNome(), c);
		
	}
	
	public void registra(Conta c){
		total += c.getSaldo();
	}
	public void exibe(){
		System.out.println("O total de saldo eh: " + total);
	}
	
	public Conta buscaPorNome(String nome){
		
		return this.conta.get(nome);
	}
	
	public void Salva(PrintWriter pw){
		for(Conta conta: this.conta.values()){
			pw.println(conta.toString() + "\n");
		}
	}
	
	public void Recupera(BufferedReader br) throws IOException{
		String input, nome, tipo;
		int numero;
		float saldo;
		
		input = br.readLine();
		while(input != null){
			
			numero = Integer.valueOf(Arrays.asList(input.split(":")).get(1).trim());
			input = br.readLine();
			
			nome = Arrays.asList(input.split(":")).get(1).trim();
			input = br.readLine();
			
			saldo = Float.valueOf(Arrays.asList(input.split("\\$")).get(1).trim());
			input = br.readLine();
			
			tipo = Arrays.asList(input.split(":")).get(1).trim();
			input = br.readLine();
			input = br.readLine();
			
			if(tipo.equals("Conta Corrente")){
				this.conta.put(nome, new ContaCorrente(numero, nome));
				this.conta.get(nome).credita(saldo + 0.1);
			}
			else if(tipo.equals("Poupanca")){
				this.conta.put(nome, new ContaPoupanca(numero, nome));
				this.conta.get(nome).credita(saldo);
			}
			else if(tipo.equals("CDB")){
				this.conta.put(nome, new CDB(numero, nome));
				this.conta.get(nome).credita(saldo);
			}
		}
	}
}
