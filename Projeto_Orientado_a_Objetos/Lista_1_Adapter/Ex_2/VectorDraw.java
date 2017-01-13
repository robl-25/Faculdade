public class VectorDraw{
    public static void main(String[] args) {

        Shape s = new Shape();
        int x = s.getX();
        int height = s.getHeight();

        Adapter teste = new Adapter();

        System.out.println("O valor de x eh "+ x);

        x = teste.getX();

        System.out.println("O valor de x agora eh " + x);
    }
}
