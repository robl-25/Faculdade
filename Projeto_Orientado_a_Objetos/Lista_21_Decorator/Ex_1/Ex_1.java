public class Ex_1{
    public static void main(String[] args){
        DecoratorUp u = new DecoratorUp();
        DecoratorInvertido i = new DecoratorInvertido();
        DecoratorTags t = new DecoratorTags();

        System.out.println(u.getTexto());
        System.out.println(i.getTexto());
        System.out.println(t.getTexto());
    }
}
