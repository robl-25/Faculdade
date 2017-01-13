public class Ex_1{
    public static void main(String[] args) {
        int tam = args.length;
        int i;
        BancoDeDados db = new BancoDeDados();
        Insere in = new Insere(db);
        Deletar d = new Deletar(db);
        Get g = new Get(db);
        All a = new All(db);
        String[] aux = new String[2];
        Compara com = new Compara();

        //System.out.println(tam);

        for(i=0; i<tam; i++){

            if(args[i].compareTo("new") == 0){
                aux[0] = args[i+1];
                aux[1] = args[i+2];

                in.execute(aux);
                i+=2;
            }
            else if(args[i].compareTo("delete") == 0){
                aux[0] = args[i+1];
                d.execute(aux);
                i++;
            }
            else if(args[i].compareTo("all") == 0){
                a.execute(null);
            }
            else if(args[i].compareTo("get") == 0){
                aux[0] = args[i+1];

                d.execute(aux);
                i++;
            }
        }
    }
}
