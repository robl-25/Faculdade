import java.io.*;
import java.util.*;

public class Reverter extends Template{

    public String Leitura(String texto){
        return texto;
    }

    public String transformar(String texto){
        StringBuilder builder = new StringBuilder(texto);
        String reverse = builder.reverse().toString();
        return reverse;
    }
}
