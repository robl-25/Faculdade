import  org.junit.Test;
import  org.junit.Assert.*;
import org.hamcrest.CoreMatchers.is;

public  class  Teste{
    private Ponto p1, p2, p3;
    private Triangulo t;
    
    public Teste(){
        this.p1.setX(0);
        this.p1.setY(0);
        this.p2.setX(3);
        this.p2.setY(0);
        this.p3.setX(0);
        this.p3.setY(3);
        
        try{
            this.t(p1,p2,p3);
        } catch(Exception e){
            System.out.print("Nao eh triangulo");
        }
    }
    
    @Test
    public  void  testDistancia(){
        double  result = p1.Distancia(p2);
        assertEquals(3.0, result);
    }
    
    @Test
    public  void  testTipo(){
        try{
            string  result = t.Tipo();
            assertEquals("O triangulo eh isoceles", result);
        } catch(Exception e){
            System.out.print("Erro");
        }
    }
}
