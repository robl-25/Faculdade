public class Individuo{
    private String nome;
    private int assento;

    public Individuo(String nome){
        this.nome = nome;
        this.assento = 0;
    }

    public String getNome(){
        return this.nome;
    }

    public void changeAssento(int i){
        this.assento = i;
    }

    public int getAssento(){
        return this.assento;
    }
}
