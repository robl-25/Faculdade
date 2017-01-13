import java.util.*;

public class VectorQueue implements FIFOQueue{

    private Vector<Integer> vetor;
    
    public VectorQueue(){
        this.vetor = new Vector<Integer> ();
    }
    
    public int dequeue(){        
        return this.vetor.remove(0);
    }
    
    public void enqueue(int o){
        this.vetor.add(o);
    }
    
    public boolean 	isEmpty(){
        return this.vetor.isEmpty();
    }
    
    public int size(){
        return this.vetor.size();
    }
    
    public void Imprimir(){
        int n, i;
        
        n = this.vetor.size();
        
        for(i=0; i<n; i++){
            System.out.print(" " + this.vetor.get(i));
        }
        
        System.out.println();
    }
}
