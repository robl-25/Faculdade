import java.util.*;

public class Banco{
    private ArrayList<Integer> id;
    private ArrayList<String> nome;

    public Banco(){
        this.id = new ArrayList<Integer> ();
        this.nome = new ArrayList<String> ();
    }

    public void Adiciona(int id, String nome){
        this.id.add(id);
        this.nome.add(nome);

        System.out.println("Elemento adicionado com sucesso!");
    }

    public void Procura(int id){
        int pos = this.id.lastIndexOf(id);

        System.out.println("ID: " + this.id.get(pos) + " Nome: " + this.nome.get(pos));
    }

    public void TodosElementos(){
        int tam = this.id.size();
        int i;

        for(i=0; i<tam; i++){
            System.out.println("ID: " + this.id.get(i) + " Nome: " + this.nome.get(i));
        }
    }

    public void Delete(int id){
        int pos = this.id.lastIndexOf(id);

        this.id.remove(pos);
        this.nome.remove(pos);

        System.out.println("Elemento removido com sucesso!");
    }
}
