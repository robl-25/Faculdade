public class Pessoa{
    private int id;
    private String nome;
    
    public void setPessoa(int id, String nome){
        this.id = id;
        this.nome = nome;
    }
    
    public int getId(){
        return this.id;
    }
    
    public String getNome(){
        return this.nome;
    }
}
