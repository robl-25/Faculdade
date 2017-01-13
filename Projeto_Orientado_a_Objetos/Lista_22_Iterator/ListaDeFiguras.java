import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class ListaDeFiguras {
	private List<Figura> list = new ArrayList<Figura>();
	
	public class Itr {
		private Iterator<Figura> iterator = list.iterator();
		public boolean hasNext() {
			return iterator.hasNext();
		}
		public Figura next() {
			return (Figura) iterator.next();
		}
	}
	
	public void addFigura(Figura f) {
		list.add(f);
	}
	public Figura get(int index) {
		return (Figura) list.get(index);
	}
	public ListaDeFiguras.Itr iterator() {
		return new Itr();
	}
	public int size() {
		return list.size();
	}
}
