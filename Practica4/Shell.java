/*****************************************************************
 * File:   Shell.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   13 abril 2023
 * Coms:   Implementación de la clase Shell
*****************************************************************/
import java.util.*;

final class Shell {

   // Atributos:

   // Nombre
   String name;
   // Ruta activa
   Stack<Directorio> path;
   // Separador
   char separador = '/';
   //directorio root
   Directorio root;

   // Metodos:

   //Constructor
   public Shell() {
      path = new Stack<Directorio>();
      root = new Directorio("/");
      path.push(root);
   };

   //Pre: longitud >= 0
   public void encontrarPath(String[] ruta, int longitud, Stack<Directorio> pathcopy) throws ExcepcionArbolFicheros {
      
      Nodo nodoAux = path.peek();
   

      for(int i = 0; i < longitud; i++){
         
         //ruta Absoluta
         if(i==0 && ruta[i].equals("")){
            pathcopy.clear();
            pathcopy.push(root);   
            continue;
         }

         //mismo directorio
         else if (ruta[i].equals(".")) {
            continue; 
         } 

         //directorio padre
         else if (ruta[i].equals("..")) { 
            if (pathcopy.peek().equals(root)) { //Si es root no sigue para atrás, pero no tira excepción
               continue; 
            }
            pathcopy.pop();
         }

         //directorio con nombre
         else {
            //comprobar si existe
            try{
               if(!pathcopy.peek().existeNodo(ruta[i])){
                  throw new ExcepcionArbolFicheros();
               }
            }
            catch(ExcepcionArbolFicheros e){
               System.out.println("El nodo " + ruta[i] + " no existe");
               throw e;
            }

            nodoAux = pathcopy.peek().devuelveNodo(ruta[i]);
            try{
               if(nodoAux instanceof Directorio){
                  pathcopy.push((Directorio)nodoAux);
               }
               else if (nodoAux instanceof Enlace) {
                  Enlace enlaceAux = (Enlace)nodoAux;
                  if(enlaceAux.ref() instanceof Directorio){
                     pathcopy.push((Directorio)enlaceAux.ref());
                  }
               }
               else{
                  throw new ExcepcionArbolFicheros();
               }
            }
            catch (ExcepcionArbolFicheros e){
               System.out.println("El nodo " + ruta[i] + " no es un directorio");
               throw e;
            }
         }
      }
   }

   /*
    * Devuelve la ruta completa de forma textual, con todos los nombres de los directorios
    * desde la raiz hasta el directorio actual concatenados y separados por el separador `/`.
    */
   public String pwd() {
      String ruta = "";
      for (Directorio item : path) {
         if(item.equals(root)){
            ruta = ruta + item.nombre();
         }
         else{
            ruta = ruta + separador + item.nombre();
         }
      }
      return ruta;
   }

   /*
    * Devuelve un listado con el nombre de todos los nodos contenidos en la ruta actual, uno por linea.
    */
   public String ls() {
      
      String listado = "";
      Directorio actual = path.peek();
      int cont = 0;
      for (Map.Entry<String, Nodo> entry : actual.colecHijos.entrySet()) {
         Nodo item = entry.getValue();
         listado = listado + item.nombre();
         if (cont != actual.colecHijos.size()-1) {
            listado = listado + "\n";
         }
         cont++;
      }
      return listado;
   }
   
   /*
    * Devuelve un listado con el nombre y el tamano de todos los nodos contenidos en la ruta actual, uno por linea.
    */
   public String du() {
      String listado = "";
      Directorio actual = path.peek();
      int cont = 0;
      for (Map.Entry<String, Nodo> entry : actual.colecHijos.entrySet()) {
         Nodo item = entry.getValue();
         listado = listado + item.nombre() + " " + item.tamano(0);
         if(cont != actual.colecHijos.size() - 1){
            listado = listado + "\n";
         }
         cont++;
      }
      return listado;
   }

   /*
    * Edita el fichero de nombre 'name' (en el directorio actual). Para simular la edicion,
    * simplemente se cambia el tamano del fichero al valor especificado como parametro. Si el fichero no existe,
    * se debe crear con el nombre y tamano especificados.
    */
   public void vi(String name, int size) throws ExcepcionArbolFicheros{
      Directorio actual = path.peek();
      if (actual.existeNodo(name)) {
         try{
            Nodo dado = actual.devuelveNodo(name);
            if(dado instanceof Fichero){
               Fichero fich = (Fichero) dado;
               fich.editar(size);
            }
            else{
               throw new ExcepcionArbolFicheros();
            }
         }
         catch(ExcepcionArbolFicheros e){
            System.out.println("El nodo no es un fichero.");
         }
      }
      else {
         actual.anadirNodo(new Fichero(name,size));
      }
   }

   /*
    * Crea un directorio de nombre 'name' en el directorio activo.
    */
   public void mkdir(String name) throws ExcepcionArbolFicheros{
      
      //Comprobar que nombre de directorio no es '.' o '..'
      try{
         if(name.equals(".") || name.equals("..")){
            throw new ExcepcionArbolFicheros();
         };
      }
      catch (ExcepcionArbolFicheros e) {
         System.out.println("Nombre de directorio no valido");
         throw e;
      }
      
      Directorio actual = path.peek();
      
      //Comprobar si ya hay un nodo con ese nombre en el directorio actual
      try {
         if (actual.existeNodo(name))
            throw new ExcepcionArbolFicheros();
         
         actual.anadirNodo(new Directorio(name)); 
      }
      catch (ExcepcionArbolFicheros e) {
         System.out.println("Ya existe un nodo con ese nombre en el directorio");
      }  
   }

   /*
    * Hace que la ruta activa pase a referenciar a otro directorio. La nueva ruta activa definida en 'path'
    * debe referenciar un directorio o un enlace a un directorio.
    */
   public void cd(String nombrePath) throws ExcepcionArbolFicheros {
      if (nombrePath.equals("/")) {
         path.clear();
         path.push(root); 
      }
      else{
         @SuppressWarnings("unchecked")
         Stack<Directorio> pathcopy = (Stack<Directorio>)path.clone();

         String[] ruta = nombrePath.split("/");
         int longitud = ruta.length;

         try {
            encontrarPath(ruta, longitud, pathcopy);
         }
         catch (ExcepcionArbolFicheros e) {
            throw e;
         }
         path = pathcopy;
      }
   }

   /*
    * Crea en el directorio actual un enlace simbolico de nombre 'name' que apunta al elemento identificado
    * mediante la ruta especificada en 'nombrePath', que puede ser de cualquier tipo. El nombre 'name' es un nombre
    * simple de nodo (se creara en el directorio activo), por lo que no puede contener una ruta completa.
    * La ruta definida en 'path' si, de tal modo que se puede crear un enlace a un elemento en otro directorio
    * del arbol, que debe existir previamente.
    */
   public void ln(String nombrePath, String name) throws ExcepcionArbolFicheros {
      Directorio actual = path.peek();

      @SuppressWarnings("unchecked")
      Stack<Directorio> pathcopy = (Stack<Directorio>)path.clone();

      if (nombrePath.equals("/")) { //enlace a root
         try{
            if(!actual.existeNodo(name)){
               actual.anadirNodo(new Enlace(name, root));
            }
            else{
               throw new ExcepcionArbolFicheros();
            }
         }
         catch(ExcepcionArbolFicheros e){
            System.out.println("Ya existe un nodo con ese nombre en el directorio");
         }
      }

      else {
         String[] ruta = nombrePath.split("/");
         int longitud = ruta.length;

         try {
            encontrarPath(ruta, longitud-1, pathcopy);
         }
         catch (ExcepcionArbolFicheros e) {
            throw e;
         }
      
         String finRuta = ruta[longitud-1];

         Nodo nodoEnlace = null;

         try {
            //Comprobar que existe nodo al que hace enlace
            
            //el mismo
            if (finRuta.equals(".")) {
               nodoEnlace = pathcopy.peek();
            }

            //ir para atrás
            else if (finRuta.equals("..")) { 
               if (!pathcopy.peek().equals(root)) { //Si es root no sigue para atrás, pero no tira excepción
                  pathcopy.pop();
               }
               nodoEnlace=pathcopy.peek();
            }

            else if(pathcopy.peek().existeNodo(finRuta)){
               nodoEnlace = pathcopy.peek().devuelveNodo(finRuta);
            }

            else {
               throw new ExcepcionArbolFicheros();
            }
         }
         catch(ExcepcionArbolFicheros e){
            System.out.println("No existe el nodo al que hacer enlace");
         }
         //Comprobar si existe algun nodo que se llame igual en el actual
         try {
            if(!actual.existeNodo(name)){
               actual.anadirNodo(new Enlace(name, nodoEnlace));
            }
            else{
               throw new ExcepcionArbolFicheros();
            }
         }
         catch(ExcepcionArbolFicheros e){
            System.out.println("Ya existe un nodo con ese nombre en el directorio");
         }
      }
   } 


   /*
    * Devuelve el tamano del nodo que referencia el nombrePath.
    */
   public int stat(String nombrePath) throws ExcepcionArbolFicheros {
      
      int tam = 0;

      @SuppressWarnings("unchecked")
      Stack<Directorio> pathcopy = (Stack<Directorio>)path.clone();

      if (nombrePath.equals("/")) { //enlace a root
         tam = root.tamano(0);
      }

      else {
         String[] ruta = nombrePath.split("/");
         int longitud = ruta.length;

         try {
            encontrarPath(ruta, longitud-1, pathcopy);
         }
         catch (ExcepcionArbolFicheros e) {
            throw e;
         }

         String finRuta = ruta[longitud-1];

         
         try {

            //el mismo
            if (finRuta.equals(".")) {
               tam = pathcopy.peek().tamano(0);
            }

            //ir para atrás
            else if (finRuta.equals("..")) { 
               if (!pathcopy.peek().equals(root)) { //Si es root no sigue para atrás, pero no tira excepción
                  pathcopy.pop();
               }
               tam = pathcopy.peek().tamano(0);
            }

            else if(pathcopy.peek().existeNodo(finRuta)){
               tam = pathcopy.peek().devuelveNodo(finRuta).tamano(0);
            }

            else{
               throw new ExcepcionArbolFicheros();
            }
         }
         catch(ExcepcionArbolFicheros e){
            System.out.println("No existe el nodo");
            throw e;
         }
      }
      return tam;
   }

   /*
    * Elimina un nodo. Si es un fichero, es simplemente eliminado. Si es un enlace, elimina el enlace pero no el nodo referenciado.
    * Si es un directorio, elimina el directorio y todo su contenido. Si existen enlaces al elemento borrado, ese elemento sigue
    * siendo accesible a traves del enlace (todavia existe), pero no a traves de su ubicacion original (que ha sido eliminada).
    */
   public void rm(String nombrePath) throws ExcepcionArbolFicheros {

      @SuppressWarnings("unchecked")
      Stack<Directorio> pathcopy = (Stack<Directorio>)path.clone();

      if (nombrePath.equals("/")) { //enlace a root
         System.out.println("No se puede eliminar root.");
         throw new ExcepcionArbolFicheros();
      }

      String[] ruta = nombrePath.split("/");
      int longitud = ruta.length;

      try {
         encontrarPath(ruta, longitud-1, pathcopy);
      }
      catch (ExcepcionArbolFicheros e) {
         throw e;
      }
      
      String finRuta = ruta[longitud -1];
      

      //comprobamos que el nodo que queremos borrar exista en el directorio padre
      Nodo nodoEnlace = null;

      try{
         //el mismo
         if (finRuta.equals(".")) {
            nodoEnlace = pathcopy.peek();
            pathcopy.peek().eliminarNodo(nodoEnlace.nombre());
         }

         //ir para atrás
         else if (finRuta.equals("..")) { 
            if (!pathcopy.peek().equals(root)) { //Si es root no sigue para atrás, pero no tira excepción
               pathcopy.pop();
            }
            nodoEnlace = pathcopy.peek();
            pathcopy.peek().eliminarNodo(nodoEnlace.nombre());
         }

         //Comprobar que existe nodo
         else if(pathcopy.peek().existeNodo(finRuta)){
            nodoEnlace = pathcopy.peek().devuelveNodo(finRuta);
            pathcopy.peek().eliminarNodo(nodoEnlace.nombre());
         }

         else {
            throw new ExcepcionArbolFicheros();
         }
      }
      catch(ExcepcionArbolFicheros e){
         System.out.println("No existe el nodo que se quiere borrar");
      }
   }
}