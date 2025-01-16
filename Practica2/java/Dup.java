/*****************************************************************
 * File:   Dup.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase Dup, subclase de Instruccion
*****************************************************************/
import java.util.*;

public class Dup extends Instruccion {
    public Dup()
	{
	}

    // Duplica la cima de la pila
    @Override
    public int ejecutar(Stack<Integer> pila, int contador) 
    {
        // Copia el ultimo elemento apilado
        int a = pila.peek();
        // Apila el elemento
        pila.push(a);
        return contador + 1;
    }

    // Devuelve una cadena de texto que representa la instrucción
    @Override
    public String nombre()
    {
        return "dup";
    }
}