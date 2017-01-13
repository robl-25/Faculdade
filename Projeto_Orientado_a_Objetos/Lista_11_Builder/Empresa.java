public class Empresa implements Construtor{
    private Pessoa pes;
    
    public void ConstroiPes(int id, String nome){
    
        if(nome != null){
            pes.setPessoa(id, nome);
        }
        
        System.out.println("Error");
    }
    
    public void ImprimePes(){
    
        System.out.println(pes.getId());
        System.out.println(pes.getNome());
    }
}
