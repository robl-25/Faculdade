import java.util.*;

public class Congresso{

    private ArrayList<Individuo> membros;
    private int assentos;

    public Congresso(int assentos){
        this.membros = new ArrayList<Individuo> ();
        this.assentos = assentos;
    }

    public void addParticipantes(Individuo membro){

        if(assentos-1 >=0){
            membro.changeAssento(this.assentos);
            this.membros.add(membro);
            this.assentos -= 1;
        }
        else{
            System.out.println("Erro! Numero de participantes maior que o total de assentos.");
        }
    }

    public void addInstituicao(Instituicao inst){
        int tam = inst.getTamanho();
        int i;

        if(assentos - tam >= 0){

            ArrayList<Individuo> aux = inst.getMembros();
            Individuo aux2;

            for(i=0; i<tam; i++){
                aux2 = aux.get(i);
                aux2.changeAssento(this.assentos);
                this.membros.add(aux2);
                this.assentos--;
            }

        }
        else{
            System.out.println("Erro! Numero de participantes maior que o total de assentos.");
        }

    }

    public int TotalAssentos(){
        return this.assentos;
    }

    public int TotalParticipantes(){
        return this.membros.size();
    }

    public void printParticipantes(){
        int i;

        for(i=0; i<membros.size(); i++){
            System.out.println(membros.get(i).getNome());
        }
    }
}
