import java.io.*;

public class Duplicar extends Template{

    public String Leitura(String texto){
        return texto;
    }

    public String transformar(String texto){
        texto = texto + texto;
        return texto;
    }
}
