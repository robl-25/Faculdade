
public class Soma extends Thread{
	private int i[], soma, id, NTHREADS;
	
	public Soma(int vetor[], int id, int NTHREADS){
		i = vetor;
		this.soma = 0;
		this.id = id;
		this.NTHREADS = NTHREADS;
	}
	
	public void run(){
		int ini, fi, tamanho;
		
		tamanho = i.length/NTHREADS;
		ini = id*tamanho;
		fi = ini + tamanho;
		
		for(int j=ini; j<fi; j++)
			soma += i[j];
	}
	
	public int getSoma(){
		return this.soma;
	}
}
