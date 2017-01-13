public class Ex1{
    public static void main(String[] args){
        ClasseTexto t = new ClasseTexto("estado_final");

        System.out.println(t.getTexto());

        t.setTexto("Ola mundo");
        t.setTexto("Projeto Orientado a Objetos");

        System.out.println(t.getTexto());

        t.Desfazer();

        System.out.println(t.getTexto());
    }
}
