import org.junit.Assert;
import org.junit.Test;
import static org.hamcrest.CoreMatchers.*;


public class SalarioTest {

	private static final double epsilon = 0.1;

	// Critério: Salário-base > 2000
	@Test
	public void maiorQue2000InPoint() {
		double entrada = 2002.0;
		double esperado = 150.5;
		Assert.assertEquals(esperado, ir.Salario.calculaIR(entrada), epsilon);
	}
	
	@Test
	public void maiorQue2000OutPoint() {
		double entrada = 1000.0;
		double esperado = -100.0;
		Assert.assertThat(esperado, not(ir.Salario.calculaIR(entrada)));
	}
	
	@Test
	public void maiorQue2000OnPoint() {
		double entrada = 2000.0;
		double esperado = 150.0;
		Assert.assertThat(esperado, not(ir.Salario.calculaIR(entrada)));
	}
	
	@Test
	public void maiorQue2000OffPoint() {
		double entrada = 2000.1;
		double esperado = 150.025;
		Assert.assertEquals(esperado, ir.Salario.calculaIR(entrada), epsilon);
	}
	
	// Critério: Salário-base > 1000
	@Test
	public void maiorQue1000InPoint() {
		double entrada = 1002.0;
		double esperado = 0.3;
		Assert.assertEquals(esperado, ir.Salario.calculaIR(entrada), epsilon);
	}
	
	@Test
	public void maiorQue1000OutPoint() {
		double entrada = 150.0;
		double esperado = -127.5;
		Assert.assertThat(esperado, not(ir.Salario.calculaIR(entrada)));
	}
	
	@Test
	public void maiorQue1000OnPoint() {
		double entrada = 1000.0;
		double esperado = 0.0;
		Assert.assertThat(esperado, not(ir.Salario.calculaIR(entrada)));
	}
	
	@Test
	public void maiorQue1000OffPoint() {
		double entrada = 1000.1;
		double esperado = 0.015;
		Assert.assertEquals(esperado, ir.Salario.calculaIR(entrada), epsilon);
	}
	
	// Critério: Salário-base <= 2000
	@Test
	public void menorOuIgualA2000InPoint() {
		double entrada = 1500.0;
		double esperado = 75.0;
		Assert.assertEquals(esperado, ir.Salario.calculaIR(entrada), epsilon);
	}
	
	@Test
	public void menorOuIgualA2000OutPoint() {
		double entrada = 2002.0;
		double esperado = 150.3;
		Assert.assertThat(esperado, not(ir.Salario.calculaIR(entrada)));
	}
	
	@Test
	public void menorOuIgualA2000OnPoint() {
		double entrada = 2000.0;
		double esperado = 150.0;
		Assert.assertEquals(esperado, ir.Salario.calculaIR(entrada), epsilon);
	}
	
	@Test
	public void menorOuIgualA2000OffPoint() {
		double entrada = 2000.1;
		double esperado = 150.015;
		Assert.assertThat(esperado, not(ir.Salario.calculaIR(entrada)));
	}
	
	// Critério: Salário-base <= 1000
	@Test
	public void menorOuIgualA1000InPoint() {
		double entrada = 150.0;
		double esperado = 0.0;
		Assert.assertEquals(esperado, ir.Salario.calculaIR(entrada), epsilon);
	}
	
	@Test
	public void menorOuIgualA1000OutPoint() {
		double entrada = 1300.0;
		double esperado = 0.0;
		Assert.assertThat(esperado, not(ir.Salario.calculaIR(entrada)));
	}
	
	@Test
	public void menorOuIgualA1000OnPoint() {
		double entrada = 1000.0;
		double esperado = 0.0;
		Assert.assertEquals(esperado, ir.Salario.calculaIR(entrada), epsilon);
	}
	
	@Test
	public void menorOuIgualA1000OffPoint() {
		double entrada = 1000.1;
		double esperado = 0.0;
		Assert.assertThat(esperado, not(ir.Salario.calculaIR(entrada)));
	}

}
