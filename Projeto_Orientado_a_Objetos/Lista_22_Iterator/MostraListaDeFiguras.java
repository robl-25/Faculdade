
public class MostraListaDeFiguras {

	public static void main(String[] args) {
		ListaDeFiguras flist = new ListaDeFiguras();
		
		flist.addFigura(new Quadrado());
		flist.addFigura(new Quadrado());
		flist.addFigura(new Circulo());
		flist.addFigura(new Triangulo());
		flist.addFigura(new Circulo());
		
		ListaDeFiguras.Itr i = flist.iterator();
		
		int cont = 0;
		while (i.hasNext()) {
			Figura f = i.next();
			System.out.println(cont +" - "+ f.toString());
			cont ++;
		}
	}

}
