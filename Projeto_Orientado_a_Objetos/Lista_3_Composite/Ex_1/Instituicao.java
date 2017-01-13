import java.util.*;

public class Instituicao{

    private ArrayList<Individuo> membros;

    public Instituicao(){
        this.membros = new ArrayList<Individuo> ();
    }

    public void addMembros(Individuo membro){
        this.membros.add(membro);
    }

    public int getTamanho(){
        return membros.size();
    }

    public ArrayList<Individuo> getMembros(){
        return membros;
    }

}
