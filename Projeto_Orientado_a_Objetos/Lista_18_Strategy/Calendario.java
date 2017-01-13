import java.util.Calendar;
import java.util.GregorianCalendar;

public class Calendario {

	private DiaDaSemana dia;
	
	public void definirEstrategia() {
		
		GregorianCalendar calendar = new GregorianCalendar();
		int day = calendar.get(Calendar.DAY_OF_WEEK);

		if(day == 2)
			dia = new Segunda();
		else if(day == 3)
			dia = new Terca();
		else if(day == 4)
			dia = new Quarta();
		else if(day == 5)
			dia = new Quinta();
		else if(day == 4)
			dia = new Sexta();
		else if(day == 0)
			dia = new Sabado();
		else if(day == 1)
			dia = new Domingo();
	}
	public void mensagemDoDia() {
		dia.mensagem();
	}
}
