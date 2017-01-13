public class Ex_1{
    public static void main(String[] args) {

        Escola escola = new Escola();
        MatriculaGUI matriculas = new MatriculaGUI(escola);
        Aluno aluno = new Aluno(86952, "Maria");
        Curso curso = new Curso(123, "Projeto Orientado a Objetos");

        escola.addAluno(aluno);
        escola.addCurso(curso);

        System.out.println("Usando GUI...");

        Turma t = matriculas.matricular(86952, 123, null);
        matriculas.exibirStatus(t);

        System.out.println("Usando Facade...");

        Facade faixa = new Facade(escola);

        faixa.addAluno(86943, "Pedro");
        faixa.addCurso(123, "Projeto Orientado a Objetos");
        faixa.addTurma(t);
        faixa.matricular(86943, 123, t);
        faixa.exibirStatus(t);
    }
}
