import java.util.*;

public class Ponto{
    private double x, y;
    
    public Ponto(double x, double y){
        this.x = x;
        this.y = y;
    }
    
    //Sets
    public void setX(double x){
        this.x = x;
    }
    
    public void setY(double y){
        this.y = y;
    }
    
    //Gets
    public double getX(){
        return this.x;
    }
    
    public double getY(){
        return this.y;
    }
    
    public double Distancia(Ponto p){
        double d;
        
        d = Math.sqrt(Math.pow(p.x - this.x,2) + Math.pow(p.y - this.y,2));
        
        return d;
    }
}
