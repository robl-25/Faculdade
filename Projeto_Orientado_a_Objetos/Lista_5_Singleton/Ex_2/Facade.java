import java.util.*;

public class Facade{
    private Escola escola;
    private ArrayList< Turma > turmas;
	private static Facade k = null;

    private Facade(Escola escola){
        this.escola = escola;
        this.turmas = new ArrayList< Turma > ();
    }
	
	public static Facade constroi(Escola escola){

		if(k == null){
			k = new Facade(escola);
		}

		return k;
	}

    public void matricular(int codAluno, int codCurso, Turma turma){

        int pos = 0;
        pos = turmas.lastIndexOf(turma);

        if(pos == -1 || turma == null){
            turma = new Turma();
            Curso c = escola.getCurso(codCurso);
            turma.setCurso(c);
            turmas.add(turma);
            pos = turmas.lastIndexOf(turma);
        }

        Aluno rex = escola.getAluno(codAluno);
        turmas.get(pos).addAluno(rex);

    }

    public void exibirStatus(Turma turma){

        System.out.println(turma.getCurso().getNome());
        ArrayList< Aluno > alunos = turma.getAlunos();

        for (int i = 0; i < alunos.size(); i++) {
            System.out.println(alunos.get(i).getNome());
        }
        System.out.println();
    }

    public void addAluno(int ra, String nome){
        Aluno aluno = new Aluno(ra, nome);
        escola.addAluno(aluno);
    }

    public void addCurso(int codigo, String nome){
        Curso curso = new Curso(codigo, nome);
        this.escola.addCurso(curso);
    }

    public void addTurma(Turma t){
        this.turmas.add(t);
    }

}
