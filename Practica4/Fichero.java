/*****************************************************************
 * File:   Fichero.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   13 abril 2023
 * Coms:   Implementación de la clase Fichero, subclase de Nodo
*****************************************************************/

class Fichero extends Nodo {

   //Constructor
   public Fichero(String _name, int _tam){
      super(_name, _tam);
   };

   // Cambia el tamaño del fichero a "size"
   public void editar(int size){
      this.tam = size;
   }

}