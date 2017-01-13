import java.util.*;
import java.io.*;

public class ClasseTexto{
    private String texto;
    private ArrayList<String> estado;
    private File arquivo;

    public ClasseTexto(String estado_final){
        int i, tam;
        char c;
        this.texto = "";
        this.estado = new ArrayList<String> ();

        try{
            arquivo = new File(estado_final);

            FileReader fr = new FileReader(arquivo);
            BufferedReader br = new BufferedReader(fr);

            while(br.ready()) {
                //lê a proxima linha
                this.estado.add(br.readLine());
            }

            br.close();
            fr.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }

        tam = this.estado.size();

        this.texto = this.estado.get(tam-1);
    }

    public void setTexto(String texto){
        this.texto = texto;
        this.estado.add(texto);
    }

    public String getTexto(){
        return this.texto;
    }

    public void Desfazer(){
        int tam = this.estado.size();

        this.estado.remove(tam-1);

        tam--;

        this.texto = this.estado.get(tam-1);

    }

    public void Encerrar(){

        try{
            FileWriter fw = new FileWriter(arquivo, true);
            BufferedWriter bw = new BufferedWriter(fw);
            int tam = this.estado.size();
            int i;

            for(i=0; i<tam; i++){
                bw.write(this.estado.get(i));
                bw.newLine();
            }

            bw.close();
            fw.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }

    }
}
