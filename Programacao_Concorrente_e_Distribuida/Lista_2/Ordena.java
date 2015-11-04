import java.util.*;

public class Ordena implements Runnable{
  //Atributos
  private int[][] matriz;
  private int id, MAX_THREADS;

  public Ordena(int[][] matriz, int id, int MAX_THREADS){
    this.matriz = matriz;
    this.id = id;
    this.MAX_THREADS = MAX_THREADS;
  }

  public int[][] getMatriz(){
    return this.matriz;
  }

  public void run(){
    int i, pos;
    int tam_parcial;

    tam_parcial = matriz.length/MAX_THREADS;
    pos = (id*tam_parcial);

    for(i=pos; i<(pos + tam_parcial); i++){
      Arrays.sort(matriz[i]);
    }
  }
}
