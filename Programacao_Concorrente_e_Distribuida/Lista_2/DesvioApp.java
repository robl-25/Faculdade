import java.util.*;
import java.lang.*;

public class DesvioApp{
    public static void main(String args[]){
        long millis_ini = System.currentTimeMillis();
        Integer N = Integer.valueOf(args[0]);
        int TAM_THREADS = Integer.valueOf(args[1]), i;

        N = (int)Math.pow(10, N);

        double mediaT, resultado, soma;
        double tempo;
        long millis;
        double[] vetor = new double[(int)N];
        Random rand = new Random();

        Thread[] th1 = new Thread[TAM_THREADS];
        Thread[] th2 = new Thread[TAM_THREADS];

        Media[] media = new Media[TAM_THREADS];
		    Desvio[] desvio = new Desvio[TAM_THREADS];

        for(i=0; i<N; i++){
            vetor[i] = rand.nextLong();
        }
        long millis_fim = System.currentTimeMillis();
        millis = millis_fim - millis_ini;
        //System.err.println("Tempo Serial: " + millis);

        millis_ini = System.currentTimeMillis();

        for(i=0; i<TAM_THREADS; i++) {
            media[i] = new Media(vetor, i, TAM_THREADS);
            th1[i] = new Thread(media[i]);
            th1[i].start();
        }

        /* Aguarda as threads finalizarem */
    		soma = 0;
    		for(int id=0; id<TAM_THREADS; id++){
    			try{
    				th1[id].join();
    			}
    			catch(Exception e){
    				System.out.println("Erro");
    			}
    			soma += media[id].getResult();
    		}

            mediaT = soma/N;

            /* Dispara as threads para calculo do desvio */
    		for(i=0; i<TAM_THREADS; i++){
    			desvio[i] = new Desvio(vetor, i, TAM_THREADS, mediaT);
    			th2[i] = new Thread(desvio[i]);
    			th2[i].start();
    		}

    		/* Aguarda as threads finalizarem */
    		soma = 0;
    		for(i=0; i<TAM_THREADS; i++){
    			try{
    				th2[i].join();
    			}
    			catch(Exception e){
    				System.out.println("Erro");
    			}
    			soma += desvio[i].getResult();
    		}

    		/* Calcula o resultado final */
    		resultado = Math.sqrt(soma/(N-1));
        millis_fim = System.currentTimeMillis();
        millis = millis_fim - millis_ini;

        System.out.printf("\t" + (millis/1000.));
    }
}
