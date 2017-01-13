import java.util.*;

public class Queue{
    private ArrayList<Object> valores;

    public Queue(){
        this.valores = new ArrayList<Object> ();
    }

	public int dequeue(){
	    Object aux;
        Boolean continuar = false;
        int resp;

        aux = valores.get(0);

        if(aux instanceof ArrayListQueue){
	        ArrayListQueue aux2 = (ArrayListQueue) aux;
            resp = aux2.dequeue();

            if(aux2.isEmpty()){
                valores.remove(aux);
            }
	    }

	    else{
	        VectorQueue aux2 = (VectorQueue) aux;
            resp = aux2.dequeue();

            if(aux2.isEmpty()){
                valores.remove(aux);
            }
	    }

        return resp;
	}

    public void enqueue(Object o){
	    this.valores.add(o);
    }

    public boolean isEmpty(){
	    return this.valores.isEmpty();
    }

    public int size(){
	    return this.valores.size();
    }

    public void Imprimir(){
        int n, i;
	    Object aux;

	    n = valores.size();

	    for(i=0; i<n; i++){
	        aux = valores.get(i);

	        if(aux instanceof ArrayListQueue){
	            ArrayListQueue aux2 = (ArrayListQueue) aux;
	            aux2.Imprimir();
	        }

	        else{
	            VectorQueue aux2 = (VectorQueue) aux;
	            aux2.Imprimir();
	        }
	    }

	}
}
