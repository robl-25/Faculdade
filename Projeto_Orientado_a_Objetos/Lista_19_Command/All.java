public class All implements Command{
    private BancoDeDados db;

    public All(BancoDeDados db){
        this.db = db;
    }

    public Object execute(String[] arg){

        db.ImprimeTodos();

        return null;
    }
}
