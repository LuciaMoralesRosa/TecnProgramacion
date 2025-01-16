/*****************************************************************
 * File:   Directorio.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   13 abril 2023
 * Coms:   Implementación de la clase Directorio, subclase de Nodo
*****************************************************************/
import java.util.*;

public class Directorio extends Nodo {
   
   public Map<String, Nodo> colecHijos;

   //Constructor
   public Directorio(String _name){
      super(_name, 0);
      colecHijos = Collections.synchronizedMap(new HashMap<String, Nodo>());
   };

   //Devuelve el tamaño del directorio
   @Override
   public int tamano(int iter){
      int tamano = 0;
      for (Nodo nodo : colecHijos.values()) {
         tamano = tamano + nodo.tamano(iter);
      }
      this.tam = tamano;
      return tamano;
   }

   //Muestra los nodos
   public void mostrarNodos(){
      for (Map.Entry<String, Nodo> nodo : colecHijos.entrySet()) {
         System.out.println(nodo.getKey());
      }
   }
   
   //Muestra los nodos y su tamaño
   public void mostrarInfo(){
      for (Map.Entry<String, Nodo> nodo : colecHijos.entrySet()) {
         System.out.println(nodo.getKey() + "\t\t" + nodo.getValue().tamano(0));
      }
   }
   
   //Añade el nodo al directorio
   public boolean anadirNodo(Nodo nodo) {
      String nom = nodo.nombre();
      boolean res = false;
      if(!existeNodo(nom)){
         colecHijos.put(nom, nodo);
         res = true;
      }
      return res;
   } 
   
   // True si exsiste nodo con nombre "name"
   public boolean existeNodo(String name){
      return colecHijos.containsKey(name);
   }  
   
   // Devuelve el Nodo con la clave "name". Un Nodo con esa clave debe existir.
   public Nodo devuelveNodo(String name){
      return colecHijos.get(name);
   }

   // Elimina el Nodo con la clave "name". Un Nodo con esa clave debe existir.
   public void eliminarNodo(String name){
      colecHijos.remove(name);
   }
}
