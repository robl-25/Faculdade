public class Insere implements Command{
    private BancoDeDados db;

    public Insere(BancoDeDados db){
        this.db = db;
    }

    public Object execute(String[] arg){
        int id = Integer.parseInt(arg[0]);
        String nome = arg[1];

        db.Insere(id, nome);

        return null;
    }
}
