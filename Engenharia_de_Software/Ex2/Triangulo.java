public class Triangulo{
    private Ponto p1, p2, p3;
    
    public Triangulo(Ponto p1, Ponto p2, Ponto p3) throws Exception{
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
        
        double a = p1.Distancia(p3);
        double b = p1.Distancia(p2);
        double c = p3.Distancia(p2);
        
        if(a<=0 || b<=0 || c<=0){
            throw new Exception("Valores para os pontos incorretos");
        }
        
        if(a>b+c){
            throw new Exception("Valor da distancia 1 esta incorreta");
        }
        
        if(b>c+a){
            throw new Exception("Valor da distancia 2 esta incorreta");
        }
        
        if(c>a+b){
            throw new Exception("Valor da distancia 3 esta incorreta");
        }
    }
    
    public String Tipo(){
        double a = this.p1.Distancia(this.p3);
        double b = this.p1.Distancia(this.p2);
        double c = this.p3.Distancia(this.p2);
        
        if(a == b && b == c){
            return "O triangulo eh equilatero";
        }
        
        else if(a == b || a == c || b == c){
            return "O triangulo eh isoceles";
        }
        
        else{
            return "O triangulo eh escaleno";
        }
    }
}
