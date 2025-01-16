/*****************************************************************
 * File:   Nodo.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   13 abril 2023
 * Coms:   Implementación de la clase Nodo
*****************************************************************/

class Nodo{
   //atributos
   String name;
   int tam;

   //Constructor
   public Nodo(String _name, int _tam){
      name = _name;
      tam = _tam;
   };

   //Devuelve el nombre del nodo
   public String nombre()  {
      return name;
   }
   
   //Devuelve el tamaño del nodo
   public int tamano(int iter) {
      return tam;
   }
}