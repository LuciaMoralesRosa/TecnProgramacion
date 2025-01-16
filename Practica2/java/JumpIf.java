/*****************************************************************
 * File:   JumpIf.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase JumpIf, subclase de Instruccion
*****************************************************************/
import java.util.*;

public class JumpIf extends Instruccion {

    protected int l;

    public JumpIf(int _l)
	{
        l = _l;
	}

    // Desapila la cima de la pila, y si su valor es mayor o igual que cero salta la ejecución del programa a la línea l
    @Override
    public int ejecutar(Stack<Integer> pila, int contador) 
    {
        // Desapila el ultimo numero de la pila
        int a = pila.peek();
        pila.pop();
        
        // Si a>=0 salta a l, sino, continua a la siguiente instruccion
        if (a >= 0) {
            return l;
        }
        else 
            return contador + 1;
    }

    // Devuelve una cadena de texto que representa la instrucción
    @Override
    public String nombre()
    {
        return "jumpif " + l;
    }
}