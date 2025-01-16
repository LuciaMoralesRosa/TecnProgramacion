/*****************************************************************
 * File:   Programa.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase Programa
*****************************************************************/
import java.util.*;

class Programa
{
	// Vector de instrucciones
	protected Instruccion instrucciones[];
	// Numero de instrucciones
	protected int nInstrucciones;

    //Constructor
	public Programa()
	{
		instrucciones = new Instruccion[0];
		nInstrucciones = 0;
	};

	public void ejecutar(Stack<Integer> pila)
	{
		System.out.println("Ejecutar: ");
		int contador = 0;
		while (contador < nInstrucciones) {
			// Se le asigna al contador el numero devuelto de la ejecución de la instrucción
			contador = instrucciones[contador].ejecutar(pila, contador);
		}
		System.out.println("");
	}

	public void listar()
	{
		System.out.println("Programa: ");
		for (int contador = 0; contador < nInstrucciones; contador++) {
			System.out.println(contador + ". " + instrucciones[contador].nombre());
		}
		System.out.println("");
	}
}
