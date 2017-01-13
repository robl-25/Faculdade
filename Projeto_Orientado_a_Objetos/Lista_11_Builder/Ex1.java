public class Ex1{
    public static void main(String[] args) {
        Empresa e = new Empresa();
        ConstroiPessoa p = new ConstroiPessoa();
        
        p.ConstroiPes(123, "Nathan");
        e.ConstroiPes(125, "Mariane");
        
        p.ImprimePes();
        e.ImprimePes();
    }
}
