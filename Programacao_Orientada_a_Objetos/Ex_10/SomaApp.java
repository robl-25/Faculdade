
public class SomaApp {

	public static void main(String[] args) throws InterruptedException {
		int i[] = new int[1000];
		int NTHREADS = 4;
		int SomaTotal = 0;
		
		for(int j=0; j<1000; j++)
			i[j] = 1;
		
		Soma vetor[] = new Soma[NTHREADS];
		
		for(int j=0; j<NTHREADS; j++){
			vetor[j] = new Soma(i,j,NTHREADS);
			vetor[j].start();
		}
		
		for(int j=0; j<NTHREADS; j++)
			vetor[j].join();
		
		for(int j=0; j<NTHREADS; j++)
			SomaTotal += vetor[j].getSoma();
		
		System.out.println("A soma total eh: " + SomaTotal);
	}

}
