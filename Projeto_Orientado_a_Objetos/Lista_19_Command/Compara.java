public class Compara{
    public Boolean Comparacao(String t1, String t2){
        int tam1 = t1.length();
        int tam2 = t2.length();
        int i;

        if(tam1 != tam2){
            return false;
        }

        /*for(i=0; i<tam1; i++){
            if(t1.charAt(i) != t2[i]){
                return false;
            }
        }*/

        return true;
    }
}
