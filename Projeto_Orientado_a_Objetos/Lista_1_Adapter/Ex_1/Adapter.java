public class Adapter extends TextView implements Shape{
    public void getBounds(){
        getFontMetrics();
        getText();
    }
}
