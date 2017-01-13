import java.util.*;

public class BancoDeDados{
    private ArrayList<String> nome;
    private ArrayList<Integer> id;

    public BancoDeDados(){
        this.nome = new ArrayList<String> ();
        this.id = new ArrayList<Integer> ();
    }

    public int getId(int id){
        int tam = this.id.size();
        int i, pos = -1;

        for(i=0; i<tam; i++){
            if(this.id.get(i) == id){
                pos = i;
            }
        }

        return pos;

    }

    public void ImprimeTodos(){
        int tam = this.id.size();
        int i;

        for(i=0; i<tam; i++){
            System.out.printf("Id: " + this.id.get(i));
            System.out.println(" Nome: " + this.nome.get(i));
        }
    }

    public void Procura(int id){
        int pos = getId(id);

        System.out.printf("Id: " + this.id.get(pos));
        System.out.println(" Nome: " + this.nome.get(pos));
    }

    public void Delete(int id){
        int pos = getId(id);
        String n = nome.get(pos);

        this.id.remove(pos);
        this.nome.remove(pos);

        System.out.println("Remocao realizada com sucesso!!");
    }

    public void Insere(int id, String nome){
        this.id.add(id);
        this.nome.add(nome);

        System.out.println("Insercao realizada com sucesso!!");
    }
}
