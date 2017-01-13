public class DeleteComando extends Comando{
    private Banco bd;

    public DeleteComando(Banco bd){
        this.bd = bd;
    }

    public void Delete(int id){
        bd.Delete(id);
    }
}
