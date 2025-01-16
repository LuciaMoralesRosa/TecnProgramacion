/*****************************************************************
 * File:   Add.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase Add, subclase de Instruccion
*****************************************************************/
import java.util.*;

public class Add extends Instruccion {
    public Add()
	{
	}

    // Desapila dos valores de la pila y apila su suma
    @Override
    public int ejecutar(Stack<Integer> pila, int contador) 
    {
        // Desapila los ultimos dos numeros de la pila
        int a = pila.peek();
        pila.pop();
        int b = pila.peek();
        pila.pop();
        // Los suma y apila el resultado
        pila.push(a+b);
        return contador + 1;
    }

    // Devuelve una cadena de texto que representa la instrucción
    @Override
    public String nombre()
    {
        return "add";
    }
}