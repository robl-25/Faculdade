public class RasterBox {
    private Coords topLeft, bottomRight;

    public RasterBox(int x1, int y1, int x2, int y2){
        topLeft = new Coords(x1, y1);
        bottomRight = new Coords(x2, y2);
    }

    public Coords getTopLeft(){
        return topLeft;
    }

    public Coords getBottomRight() {
        return bottomRight;
    }
}
