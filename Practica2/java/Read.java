/*****************************************************************
 * File:   Read.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase Read, subclase de Instruccion
*****************************************************************/
import java.util.*;
import java.util.Scanner;

public class Read extends Instruccion {
    public Read()
	{
	}

    // Pide un valor al usuario por la entrada estándar y lo apila
    @Override
    public int ejecutar(Stack<Integer> pila, int contador) 
    {
        int num;
        Scanner scanner = new Scanner(System.in);
        // Pide el numero
        System.out.print("? ");
        System.out.flush();
        num = scanner.nextInt();
        // Apila el numero
        pila.push(num);
        return contador + 1;
    }

    // Devuelve una cadena de texto que representa la instrucción
    @Override
    public String nombre()
    {
        return "read";
    }
}
