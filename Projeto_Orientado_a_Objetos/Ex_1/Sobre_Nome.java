import java.io.*;
import java.util.*;

public class Sobre_Nome implements Nomes{
    public ArrayList< String > nome;

    public Sobre_Nome(){
        this.nome = new ArrayList< String > ();
    }

    public void Leitura(String nome){

        String texto = "";
        String nome2 = nome.replace(",", "");
        String[] aux = nome2.split(" ");
        int tam = 2;
        int i;

        for(i=tam-1; i>=0; i--){
            texto += aux[i];
            texto += " ";
        }

        this.nome.add(texto);
    }

    public void Imprime(){
        int tam = this.nome.size();
        int i;

        for(i=0; i<tam; i++){
            System.out.println(this.nome.get(i));
        }

    }
}
