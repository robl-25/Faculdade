import java.util.*;

public class ClasseTexto{
    private String texto;
    private ArrayList<String> estado;

    public ClasseTexto(){
        this.texto = "";
        this.estado = new ArrayList<String> ();
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
}
