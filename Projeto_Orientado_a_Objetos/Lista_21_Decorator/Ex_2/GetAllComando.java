public class GetAllComando extends Comando{
    private Banco bd;

    public GetAllComando(Banco bd){
        this.bd = bd;
    }

    public void GetAll(){
        bd.TodosElementos();
    }
}
