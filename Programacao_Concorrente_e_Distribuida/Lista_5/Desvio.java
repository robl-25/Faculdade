import java.lang.*;
import java.util.*;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class Desvio{
    private static double total = 0;
	
    private static class Media extends Thread{
        private double[] dados;
	    private double result;
	    private int id;
	    private double soma = 0;
	    private int MAX_THREADS;
	    private long N;
	    
	    CyclicBarrier barrier;

	    public Media(CyclicBarrier barrier, double[] dados, int id, 
	                 int MAX_THREADS, long N){
		    this.dados = dados;
		    this.id = id;
		    this.MAX_THREADS = MAX_THREADS;
		    this.N = N;
		    this.barrier = barrier;
	    }
	
	    /* Setter */
	    public void setResult(double result){
	        this.result = result;
	    }

	    /* Getter */
	    public double getResult(){
		    return this.result;
	    }

	    /* Funcao que vai fazer o trabalho pesado */
	    public void run(){
            long pos_inicial, pos_final, tamanho_local, pos;

            tamanho_local = dados.length/MAX_THREADS;
            pos_inicial = tamanho_local*id;
            pos_final = (pos_inicial + tamanho_local)-1;
            if(id == (MAX_THREADS - 1)){
                pos_final = N-1;
            }

            //System.out.println("(Thread["+id+"]) pos ["+pos_inicial+" - "+pos_final+"]");
            for(pos=pos_inicial; pos<=pos_final; pos++){
	            soma += dados[(int) pos];
            }
            result = soma;
             
            synchronized (this) {
                total += result/N;
            }

            // wait for others
            try{
                barrier.await();
            } catch (InterruptedException ex)
            {
                ex.printStackTrace();
            } catch (BrokenBarrierException ex)
            {
                ex.printStackTrace();
            }
            
            for(pos=pos_inicial; pos<=pos_final; pos++){
			    soma += Math.pow(dados[(int) pos] - total, 2);
		    }

		    /* Salva o resultado da soma */
		    result = soma;
             
            synchronized (this) {
                total += result;
            }

            // wait for others
            try{
                barrier.await();
            } catch (InterruptedException ex)
            {
                ex.printStackTrace();
            } catch (BrokenBarrierException ex)
            {
                ex.printStackTrace();
            }
            
            if(id == 0){
                result = Math.sqrt(total/(N-1));
                //System.out.println(" Resultado = " + result);
            }
	    }
    }
    
    public static void main(String args[]){
        long millis_ini = System.currentTimeMillis();
        long N = Integer.valueOf(args[0]);
        int TAM_THREADS = Integer.valueOf(args[1]), i;

        N = (int)Math.pow(10, N);

        double mediaT, resultado, soma;
        double tempo;
        long millis;
        double[] vetor = new double[(int)N];
        Random rand = new Random();

        Thread[] th1 = new Thread[TAM_THREADS];
        Media media;
        
        CyclicBarrier barrier = new CyclicBarrier(TAM_THREADS);
        
		for(i=0; i<N; i++){
            vetor[i] = rand.nextLong();
        }
        
        long millis_fim = System.currentTimeMillis();
        millis = millis_fim - millis_ini;
        //System.err.println("Tempo Serial: " + millis);

        millis_ini = System.currentTimeMillis();

        for(i=0; i<TAM_THREADS; i++){
		    media = new Media(barrier, vetor, i, TAM_THREADS, N);
		    media.start();
	    }
        millis_fim = System.currentTimeMillis();
        millis = millis_fim - millis_ini;

        System.out.printf("\t" + (millis/1000.));
    }
}
