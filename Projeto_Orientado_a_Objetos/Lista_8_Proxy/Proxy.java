public class Proxy{
    private SujeitoReal sr;
    
    public Proxy(){
        this.sr = new SujeitoReal();
    }
    
    public int getO(){
        System.out.println("Direcionando para o SujeitoReal a chamada getO...");
        return sr.getO();
    }
    
    public void setO(int o){
        System.out.println("Direcionando para o SujeitoReal a chamada setO...");
	    sr.setO(o);;
	}
}
