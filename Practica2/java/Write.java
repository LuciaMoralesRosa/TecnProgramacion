/*****************************************************************
 * File:   Write.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase Write, subclase de Instruccion
*****************************************************************/
import java.util.*;

public class Write extends Instruccion {
    public Write()
	{
	}

    // Desapila un valor de la pila y lo muestra por la salida estándar al usuario
    @Override
    public int ejecutar(Stack<Integer> pila, int contador) 
    {
        System.out.println(pila.peek());
        pila.pop();
        return contador + 1;
    }

    // Devuelve una cadena de texto que representa la instrucción
    @Override
    public String nombre()
    {
        return "write";
    }
}