public class Cliente{
    public static void main(String[] args){
        Queue novo = new Queue();
        ArrayListQueue aux1 = new ArrayListQueue ();
        VectorQueue aux2 = new VectorQueue ();
        int i;

        for(i=0; i<10; i++){
            aux1.enqueue(i);
        }

        for(i=-10; i<0; i++){
            aux2.enqueue(i);
        }

        novo.enqueue(aux1);
        novo.enqueue(aux2);

        for(i=0; i<11; i++){
            System.out.println("Removendo o " + novo.dequeue());
            novo.Imprimir();
        }

        System.out.println("O tamanho do Queue eh " + novo.size());

        /*System.out.println("O queue eh vazio? " + novo.isEmpty());
        System.out.println("Removendo o " + novo.dequeue());
        System.out.println("O tamanho do Queue eh " + novo.size());

        novo.Imprimir();
        System.out.println("Removendo o " + novo.dequeue());
        novo.Imprimir();*/
    }
}
