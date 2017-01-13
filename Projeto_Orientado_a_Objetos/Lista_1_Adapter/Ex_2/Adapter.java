public class Adapter extends Shape {
    public RasterBox tipo = new RasterBox(5, 36, 4, 89);

    public int getX(){
        Coords res = tipo.getTopLeft();
        return res.getXCoords();
    }
}
