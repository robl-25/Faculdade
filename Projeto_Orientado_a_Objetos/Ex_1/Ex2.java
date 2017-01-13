import java.io.*;
import java.util.*;

public class Ex2{
    public static void main(String[] args) {
        ArrayList<String> nomes = new ArrayList<String>();
        Nome_Sobre ns = new Nome_Sobre();
        Sobre_Nome sn = new Sobre_Nome();

        nomes.add("Pedro Paulo");
        nomes.add("Renato, Eduardo");
        nomes.add("Marcos Eduardo");

        int tam = nomes.size();
        int i;

        for(i=0; i<tam; i++){
            if(nomes.get(i).indexOf(",") == -1){
                ns.Leitura(nomes.get(i));
            }
            else{
                sn.Leitura(nomes.get(i));
            }
        }

        ns.Imprime();
        sn.Imprime();
    }
}
