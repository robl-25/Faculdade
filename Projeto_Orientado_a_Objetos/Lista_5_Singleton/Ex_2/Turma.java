import java.util.*;

public class Turma{

    private ArrayList< Aluno > alunos;
    private Curso curso;
    
    public Turma(){
        this.alunos = new ArrayList< Aluno > ();
    }
    
    public void setCurso(Curso curso){
        this.curso = curso;
    }
    
    public Curso getCurso(){
        return curso;
    }
    
    public ArrayList< Aluno > getAlunos(){
        return alunos;
    }
    
    public void addAluno(Aluno aluno){
        this.alunos.add(aluno);
    }
    
}
