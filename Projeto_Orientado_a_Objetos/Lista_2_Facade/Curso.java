public class Curso{
    private int codigo;
    private String nome;
    
    public Curso(int codigo, String nome){
        this.nome = nome;
        this.codigo = codigo;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public int getCodigo(){
        return this.codigo;
    }
}
