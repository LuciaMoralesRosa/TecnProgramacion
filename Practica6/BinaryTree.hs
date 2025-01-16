{-------------------------------------------------------------------------------
 * File:    BinaryTree.hs
 * Author:  Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:    10 mayo 2023
 * Coms:    Practica 6 - BinaryTree
-------------------------------------------------------------------------------}

module BinaryTree where
import Data.List


-- Definicion de dato ----------------------------------------------------------
data ArbolBin ab = AbVacio | Nodo ab (ArbolBin ab) (ArbolBin ab)


-- empty: Devuelve arbol vacio -------------------------------------------------
empty :: ArbolBin ab
empty = AbVacio

-- leaf: Devuelve un arbol de una sola hoja ------------------------------------
leaf :: ab -> ArbolBin ab
leaf ab = Nodo ab (empty) (empty)

-- tree: Devuelve un arbol que contiene en la raíz el elemento ab con: ---------
--    - Hijo izquierdo lc
--    - Hijo derecho rc
tree :: ab -> ArbolBin ab -> ArbolBin ab -> ArbolBin ab
tree ab lc rc = Nodo ab lc rc

-- size: Devuelve el numero de elementos que contiene el arbol ab --------------
size :: ArbolBin ab -> Integer
size AbVacio = 0
size (Nodo _ lc rc) = 1 + size lc + size rc

-- add: Añade el elemento elem al árbol t y devolviendo el ABB resultante ------
--    - El ABB puede contener valores repetidos, pero el valor en cada nodo
--      siempre será mayor que todos los valores de los elementos del subárbol
--      de la izquierda, y menor o igual que todos los elementos del subárbol
--      de la derecha.
add :: (Ord ab) => ArbolBin ab -> ab -> ArbolBin ab
add AbVacio elem = leaf elem --Si el arbol original es vacio queda una hoja
add (Nodo ab lc rc) elem
   | ab > elem = Nodo ab (add lc elem) (rc)
   | otherwise = Nodo ab (lc) (add rc elem)

-- build: Construye un ABB, insertando los elementos de la lista dada ----------
build :: (Ord ab) => [ab] -> ArbolBin ab
build [] = AbVacio
build lista = buildAux lista (empty)
   where
      buildAux [] ab = ab
      buildAux (l:lista) ab = buildAux lista (add ab l)

-- buildBalanced: Construye un árbol equilibrado a partir de la lista dada -----
buildBalanced :: (Ord ab) => [ab] -> ArbolBin ab
buildBalanced [] = AbVacio
buildBalanced [h] = leaf h
buildBalanced lista = Nodo (head (mitad2)) (buildBalanced mitad1)
                                           (buildBalanced (drop 1 mitad2)) 
   where
      mitad1 = takemitad(sort lista) where
         takemitad lista = take (div (length lista) 2) lista
      mitad2 = dropmitad(sort lista) where
         dropmitad lista = drop (div (length lista) 2) lista

-- preorder: Dado un arbol, devuelve una lista con los nodos en preorden -------
preorder :: (Ord ab) => ArbolBin ab -> [ab]
preorder AbVacio = []
preorder (Nodo ab lc rc) = [ab] ++ preorder lc ++ preorder rc

-- postorder: Dado un arbol, devuelve una lista con los nodos en postorden -----
postorder :: (Ord ab) => ArbolBin ab -> [ab]
postorder AbVacio = []
postorder (Nodo ab lc rc) = postorder lc ++ postorder rc ++ [ab]

-- inorder: Dado un arbol, devuelve una lista con los nodos en inorden ---------
inorder :: (Ord ab) => ArbolBin ab -> [ab]
inorder AbVacio = []
inorder (Nodo ab lc rc) = inorder lc ++ [ab] ++ inorder rc

-- balance: Construye un árbol equilibrado a partir de otro arbol dado ---------
balance :: (Ord ab) => ArbolBin ab -> ArbolBin ab
balance ab = buildBalanced (preorder ab)

-- between: Busca en el ABB dado y devuelve una lista con todos los ------------
--      elementos del árbol que están entre los valores [xmin, xmax]
between :: (Ord ab) => ArbolBin ab -> ab -> ab -> [ab]
between AbVacio _ _ = []
between (Nodo ab lc rc) min max  
   | min > max = []
   | ab < min = between rc min max 
   | ab > max = between lc min max 
   | ab == min = between rc min max ++ [ab]
   | otherwise = between lc min max ++ between rc min max ++ [ab]

-- show: Funcion para mostrar por pantalla ----------------------------------
instance (Show ab) => Show (ArbolBin ab) where
   show ab = showAux ab 0 where
      showAux AbVacio _ = "<>"
      showAux (Nodo ab AbVacio AbVacio) _ = show ab
      showAux (Nodo ab lc rc) num = show ab ++ "\n" ++ sangria num ++ "|- " ++ 
                                    showAux lc (num + 1) ++ "\n" ++ sangria num 
                                    ++ "|- " ++ showAux rc (num + 1)
         where
            sangria 0 = ""
            sangria num = ("   ") ++ sangria(num - 1)      
