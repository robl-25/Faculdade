package teste;

import static org.junit.Assert.*;
import org.junit.Test;

import ProgramToRoman.intToRoman;

public class intToRomanTest {

	@Test
	public void InputMenorQueUm() {
		int entrada = 0;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "Invalid Roman Number Value";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorQueQuatroMil() {
		int entrada = 4001;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "Invalid Roman Number Value";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualAMil() {
		int entrada = 1000;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "M";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualANovecentos() {
		int entrada = 900;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "CM";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualAQuinhentos() {
		int entrada = 500;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "D";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualAQuatrocentos() {
		int entrada = 400;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "CD";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualACem() {
		int entrada = 100;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "C";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaoirQueNoventa() {
		int entrada = 91;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "XCI";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputIgualANoventa() {
		int entrada = 90;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "XC";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputIgualACinquenta() {
		int entrada = 50;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "L";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputIgualAQuarenta() {
		int entrada = 40;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "XL";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualADez() {
		int entrada = 10;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "X";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualANove() {
		int entrada = 9;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "IX";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualACinco() {
		int entrada = 5;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "V";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualAQuatro() {
		int entrada = 4;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "IV";
		assertEquals(esperado, resultado);
	}
	
	@Test
	public void InputMaiorOuIgualAUm() {
		int entrada = 1;
		String resultado = intToRoman.IntegerToRomanNumeral(entrada);
		String esperado = "I";
		assertEquals(esperado, resultado);
	}
}
