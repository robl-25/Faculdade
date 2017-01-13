import java.util.*;

public class Escola{
    private ArrayList< Curso > cursos;
    private ArrayList< Aluno > alunos;

    public Escola(){
        this.cursos = new ArrayList< Curso > ();
        this.alunos = new ArrayList< Aluno > ();
    }

    public void addCurso(Curso curso){
        this.cursos.add(curso);
    }

    public void addAluno(Aluno aluno){
        this.alunos.add(aluno);
    }

    public Curso getCurso(int codigo){

        int pos = 0, cod = 0;
        Curso curso_aux;

        for(int i = 0; i<cursos.size(); i++){

            curso_aux = cursos.get(i);
            cod = curso_aux.getCodigo();

            if(cod == codigo){
                pos = i;
                i = cursos.size();
            }
        }

        return cursos.get(pos);
    }

    public Aluno getAluno(int codigo){

        int pos = 0, cod = 0;
        Aluno aluno_aux;

        for(int i = 0; i<alunos.size(); i++){

            aluno_aux = alunos.get(i);
            cod = aluno_aux.getMatricula();

            if(cod == codigo){
                pos = i;
                i = alunos.size();
            }
        }

        return alunos.get(pos);
    }

}
