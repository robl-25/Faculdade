import java.io.*;

public class I2{
    public static void copia(String origem, String destino) {
        BufferedReader ler = null;
        BufferedWriter escreve = null;
        
        try{
            String linha;
            
            ler = new BufferedReader(new FileReader(origem));
            escreve = new BufferedWriter(new FileWriter(destino));
            
            while(linha = ler.readLine() != null){
                escreve.write(linha);
            }
            escreve.write("\n");
        }catch(IOException e){
            e.printStackTrace();
        } finally{
            try{
                if(ler != null){
                    ler.close();
                }
                if(escreve != null){
                    escreve.close();
                }
            }catch(IOException ex){
                ex.printStackTrace();
            }
        }
        
    }
}

//Tempo total: 1h
