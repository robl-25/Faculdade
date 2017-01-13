import java.util.*;

public class Nome_Sobre implements Nomes{
    public ArrayList< String > nome;

    public Nome_Sobre(){
        this.nome = new ArrayList< String > ();
    }

    public void Leitura(String nome){
        this.nome.add(nome);
    }

    public void Imprime(){
        int tam = this.nome.size();
        int i;

        for(i=0; i<tam; i++){
            System.out.println(this.nome.get(i));
        }

    }
}
