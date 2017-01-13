import java.util.*;
import java.lang.*;
import java.io.*;

public class DecoratorInvertido{
    private MetodoSimples texto;

    public DecoratorInvertido(){
        this.texto = new MetodoSimples();
    }

    public String getTexto(){
        String aux = texto.getTexto();
        String aux2 = new StringBuilder(aux).reverse().toString();

        return aux2;
    }
}
