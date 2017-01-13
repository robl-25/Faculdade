public class GetComando extends Comando{
    private Banco bd;

    public GetComando(Banco bd){
        this.bd = bd;
    }

    public void Get(int id){
        bd.Procura(id);
    }
}
