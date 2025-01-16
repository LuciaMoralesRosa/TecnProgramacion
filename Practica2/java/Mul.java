/*****************************************************************
 * File:   Mul.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase Mul, subclase de Instruccion
*****************************************************************/
import java.util.*;

public class Mul extends Instruccion {
   protected int c;
   public Mul(){}

   @Override
   public int ejecutar(Stack<Integer> pila, int contador){
      int a = pila.peek();
      pila.pop();
      int b = pila.peek();
      pila.pop();
      pila.push(a*b);

      return contador + 1;
   }
   @Override
   public String nombre() {
      return "mul";
   }
}