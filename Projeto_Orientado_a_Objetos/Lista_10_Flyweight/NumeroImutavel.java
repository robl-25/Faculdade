
public class NumeroImutavel implements Numeros {

	Integer num;
	public NumeroImutavel(Integer num) {
		this.num = num;
	}
	public boolean equal(Object obj) {
		if (this.num == ((NumeroImutavel)obj).num) {
			return true;
		}
		else return false;
	}
	public String getString() {
		return num.toString();
	}

}
