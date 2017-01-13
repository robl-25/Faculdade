//import org.junit.runner.JUnitCore.*;

public class TrianguloApp{
    public static void main(String[] args) {
        Ponto p1, p2, p3;
        Triangulo t;
    
        p1 = new Ponto(0,-5);
        p2 = new Ponto(3,5);
        p3 = new Ponto(0,-2);
        
        System.out.print("A distancia do p1 para o p2 eh " + p1.Distancia(p2));
        System.out.print("\n");
        System.out.print("A distancia do p1 para o p3 eh " + p1.Distancia(p3));
        System.out.print("\n");
        System.out.print("A distancia do p2 para o p3 eh " + p2.Distancia(p3));
        System.out.print("\n");
        
        try{
            t = new Triangulo(p1,p2,p3);
            System.out.print(t.Tipo());
            System.out.print("\n");
        } catch(Exception e){
            System.out.print("Nao eh triangulo");
            System.out.print("\n");
        }
    }
}
