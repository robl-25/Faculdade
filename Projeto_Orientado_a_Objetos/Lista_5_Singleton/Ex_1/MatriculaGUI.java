import java.util.*;

public class MatriculaGUI{
    private Escola escola;

    public MatriculaGUI(Escola escola){
        this.escola = escola;
    }

    public Turma matricular(int codAluno, int codCurso, Turma turma){

        if (turma == null){
            turma = new Turma();
            Curso c = escola.getCurso(codCurso);
            turma.setCurso(c);
        }

        Aluno rex = escola.getAluno(codAluno);
        turma.addAluno(rex);

        return turma;
    }

    public void exibirStatus(Turma turma){

        System.out.println(turma.getCurso().getNome());
        ArrayList< Aluno > alunos = turma.getAlunos();

        for (int i = 0; i < alunos.size(); i++) {
            System.out.println(alunos.get(i).getNome());
        }
        System.out.println();
    }
}
