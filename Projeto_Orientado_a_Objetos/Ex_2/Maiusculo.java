import java.io.*;

public class Maiusculo extends Template{

    public String Leitura(String texto){
        return texto;
    }

    public String transformar(String texto){
        return texto.toUpperCase();
    }
}
