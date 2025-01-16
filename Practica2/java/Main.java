/*****************************************************************
 * File:   Main.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Fichero main
*****************************************************************/
import java.util.*;

class Main
{
	public static void main(String[] args)
	{
		int N = 2;
		Programa programas[] = new Programa[N];
		Stack<Integer> pila = new Stack<Integer>();

		// Lista de programas
		programas[0] = new Suma();
		programas[1] = new CuentaAtras();
		//...

		// Ejecucion de todos los programas
		for (int i = 0; i<N; i++) {
			programas[i].listar();
			programas[i].ejecutar(pila);
		}
	}
}
