public class Get implements Command{
    private BancoDeDados db;

    public Get(BancoDeDados db){
        this.db = db;
    }

    public Object execute(String[] arg){
        int id = Integer.parseInt(arg[0]);

        db.Procura(id);

        return null;
    }
}
