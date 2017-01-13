public class Ex_2{
    public static void main(String[] args){
        Banco bd = new Banco();
        ComandoReader cr = new ComandoReader("teste",bd);
        cr.LerComando();
    }
}
