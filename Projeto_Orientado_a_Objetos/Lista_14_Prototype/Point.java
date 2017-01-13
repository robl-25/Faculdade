
public class Point implements Figura, PrototypeCapable {

	private Integer x;
	private Integer y;
	
	Point() {
		this.x = 0;
		this.y = 0;
	}
	
	Point(Integer x, Integer y) {
		this.x = x;
		this.y = y;
	}
	
	public void setX(Integer i) {
		this.x = i;
	}
	public void setY(Integer i) {
		this.y = i;
	}
	public Point clone() {
		try {
			Point c = (Point)super.clone();
			return c;
		} catch (CloneNotSupportedException e) {return null;}
	}
	public String toString() {
		return "("+this.x+", "+this.y+")";
	}
}
