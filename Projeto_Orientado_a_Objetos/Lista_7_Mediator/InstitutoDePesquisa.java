import java.util.ArrayList;
import java.util.HashMap;

public class InstitutoDePesquisa implements Observador {

	private HashMap<Integer, ArrayList<Double>> dados = new HashMap<Integer, ArrayList<Double>>(); // [0] temperatura / [1] pressao / [2] nivel
	private HashMap<Integer, Observable> PCs = new HashMap<Integer, Observable>();
	private boolean notificar;
	
	InstitutoDePesquisa() {
		this.notificar = true;
	}
	
	public void setNotificar(boolean a) {
		this.notificar = a;
	}
	
	public void atualizar(Integer i) {
		if (this.notificar) {
			Observable PC = this.PCs.get(1);
			this.dados.get(i).add(0, PC.getTemperatura());
			this.dados.get(i).add(1, PC.getPressao());
			this.dados.get(i).add(2, PC.getNivel());
		}
	}
	
	public void getString() {
		for (Integer key : PCs.keySet()) {
			System.out.println("Estacão: "+this.PCs.get(key)+"\nTemperatura: "+this.dados.get(key).get(0)+
					"\n	Pressao: "+this.dados.get(key).get(1)+"\n	Nível: "+this.dados.get(key).get(2) +"\n");
		}
		
	}
	
	public void cadastrar(Observable o) {
		this.PCs.put(o.getInd(), o);
		ArrayList<Double> a = new ArrayList<Double>();
		a.add(0, o.getTemperatura());
		a.add(1, o.getPressao());
		a.add(2, o.getNivel());
		this.dados.put(o.getInd(), a);
		o.cadastrar(this);
	}
	
	public void remover(Observable o) {
		this.PCs.remove(o.getInd());
		this.dados.remove(o.getInd());
		o.remover(this);
	}

}
