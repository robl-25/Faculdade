import java.util.*;
import java.lang.*;

public class OrdenaApp{
  public static void main(String args[]){
    //Atributos
    long millis_ini, millis, millis_fim;
    Integer N = Integer.valueOf(args[0]);
    int TAM_THREADS = Integer.valueOf(args[1]), i;

    //N = (int)Math.pow(10, N);

    int id,j;
    int[][] matriz = new int[(int) N][(int) N];
    Random rand = new Random();

    Thread[] th = new Thread[TAM_THREADS];
    Ordena[] or = new Ordena[TAM_THREADS];

    //Popula a matriz
    for(id=0; id<N; id++){
        for(j=0; j<N; j++){
          matriz[id][j] = (int) rand.nextInt(10);
        }
    }

    //Comeca a calcular o tempo
    millis_ini = System.currentTimeMillis();

    //Divide a matriz
    for(id=0; id<TAM_THREADS; id++){
      or[id] = new Ordena(matriz, id, TAM_THREADS);
      th[id] = new Thread(or[id]);
      th[id].start();
    }

    //Espera todas as threads terminarem
    for(id=0; id<TAM_THREADS; id++){
      try{
        th[id].join();
      }
      catch(Exception e){
        System.out.println("Erro");
      }
    }

    //Finaliza o tempo
    millis_fim = System.currentTimeMillis();
    millis = millis_fim - millis_ini;
    System.out.printf("\t" + (millis/1000.));
  }
}
