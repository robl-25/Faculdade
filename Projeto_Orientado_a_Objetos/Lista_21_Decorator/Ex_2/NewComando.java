public class NewComando extends Comando{
    private Banco bd;

    public NewComando(Banco bd){
        this.bd = bd;
    }

    public void Adiciona(int id, String nome){
        bd.Adiciona(id, nome);
    }

}
