public class Deletar implements Command{
    private BancoDeDados db;

    public Deletar(BancoDeDados db){
        this.db = db;
    }

    public Object execute(String[] arg){
        int id = Integer.parseInt(arg[0]);

        db.Delete(id);

        return null;
    }
}
