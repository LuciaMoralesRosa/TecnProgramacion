/*****************************************************************
 * File:   Push.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase Push, subclase de Instruccion
*****************************************************************/
import java.util.*;

public class Push extends Instruccion {
    protected int c;

    public Push(int _c)
	{
        c = _c;
	}

    // Apila la constante c en la pila
    @Override
    public int ejecutar(Stack<Integer> pila, int contador) 
    {
        pila.push(c);
        return contador + 1;
    }

    // Devuelve una cadena de texto que representa la instrucción
    @Override
    public String nombre()
    {
        return "push " + c;
    }
}