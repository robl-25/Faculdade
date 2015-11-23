import java.util.Random;

public class ProdutoEscalar implements Runnable {

    static int n = 100000, nT = 1, intervalo;
    private final int id;
    static double[] vet1, vet2;
    static double resultado;

    public static void main(String[] args) throws InterruptedException {
        n = Integer.parseInt(args[0]);
        nT = Integer.parseInt(args[1]);

        intervalo = n / nT;
        resultado = 0;

        vet1 = new double[n];
        vet2 = new double[n];

        Random rand = new Random();

        for (int i = 0; i < n; i++){
            vet1[i] = rand.nextDouble();
            vet2[i] = rand.nextDouble();
        }

        long tempoInicial = System.currentTimeMillis();

        Thread[] th = new Thread[nT];
        ProdutoEscalar[] pe = new ProdutoEscalar[nT];
        for(int i = 0; i < nT; i++){
            pe[i] = new ProdutoEscalar(i);
            th[i] = new Thread(pe[i]);
            th[i].start();
        }

        for(int i = 0; i < nT; i++){
            th[i].join();
        }

        double tempoFinal = System.currentTimeMillis() - tempoInicial;
        tempoFinal = tempoFinal/1000;

        System.out.print(tempoFinal + " ");
    }

    public ProdutoEscalar(int id)
    {
        this.id = id;
    }

    @Override
    public void run(){
        soma();
    }

    private synchronized void incrementa(double result){
        resultado += result;
    }

    private void soma(){
        int ini = intervalo * id;
        int fim = ini + intervalo;

        double soma = 0;

        while(ini < fim){
            soma += vet1[ini] * vet2[ini];
            ini++;
        }
        incrementa(soma);
    }
}
