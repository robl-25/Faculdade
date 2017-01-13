public class Ex1{
    public static void main(String[] args){
        String texto = "Hello World";
        Template ma = new Maiusculo();
        Template mi = new Minusculo();
        Template r = new Reverter();
        Template d = new Duplicar();

        System.out.println(ma.transformar(texto));
        System.out.println(mi.transformar(texto));
        System.out.println(r.transformar(texto));
        System.out.println(d.transformar(texto));
    }
}
