import java.util.*;
import java.lang.*;
import java.io.*;

public class DecoratorUp{
    private MetodoSimples texto;

    public DecoratorUp(){
        this.texto = new MetodoSimples();
    }

    public String getTexto(){
        return texto.getTexto().toUpperCase();
    }
}
