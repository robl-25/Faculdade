import java.lang.*;
import java.io.*;

public class ComandoReader{
    private InputStream is;
    private Banco bd;

    public ComandoReader(String arq, Banco bd){
        try{
            is = new FileInputStream(arq);
        }
        catch(Exception e){
            e.printStackTrace();
        }
        this.bd = bd;
    }

    public Comando LerComando(){
        int i, tam;
        char c;
        String comando = "";
        String aux2;
        Comando resp = null;

        try{
            while((i=is.read())!=-1){
                // converts integer to character
                c=(char)i;
                comando += c;
             }

             is.close();

        }
        catch(IOException e){
            e.printStackTrace();
        }
        System.out.println(comando);

        String[] aux = comando.split(" ");
        tam = aux.length;

        for(i=0; i<tam; i++){
            resp = null;

            if(aux[i] == "new"){
               resp = new NewComando(bd);

               resp.Adiciona(Integer.parseInt(aux[i+1]), aux[i+2]);

               i+=2;
            }
            else if(aux[i] == "delete"){
               resp = new DeleteComando(bd);
               resp.Delete(Integer.parseInt(aux[i+1]));
               i++;
            }
            else if(aux[i] == "get"){
               resp = new GetComando(bd);
               resp.Get(Integer.parseInt(aux[i+1]));
               i++;
            }
            else if(aux[i] == "all"){
               resp = new GetAllComando(bd);
               resp.GetAll();
            }
            else{
               resp = new NullComando();
               resp.NullComando();
            }
        }

        return resp;
    }
}
