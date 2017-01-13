import java.util.*;

public class ArrayListQueue implements FIFOQueue{
    
    private ArrayList<Integer> lista;
    
    public ArrayListQueue(){
        this.lista = new ArrayList<Integer> ();
    }
    
    public int dequeue(){
        return this.lista.remove(0);
    }
    
    public void enqueue(int o){
        this.lista.add(o);
    }
    
    public boolean 	isEmpty(){
        return this.lista.isEmpty();
    }
    
    public int size(){
        return this.lista.size();
    }
    
    public void Imprimir(){
        int n, i;
        
        n = this.lista.size();
        
        for(i=0; i<n; i++){
            System.out.print(" " + this.lista.get(i));
        }
        
        System.out.println();
    }
}
