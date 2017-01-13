public class Aluno{
    private int matricula;
    private String nome;
    
    public Aluno(int ra, String nome){
        this.matricula = ra;
        this.nome = nome;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public int getMatricula(){
        return this.matricula;
    }
}
