{-
*****************************************************************
 * Fichero: goldbach.sh
 * Autor:   Lucia Morales (816906)
 * Fecha:   23 abril 2023
 * Coms:    Conjetura de Goldbach
*****************************************************************/
-}

--Funciones para el calculo de primos

--prime: Devuelve true si un numero n es primo
prime :: Int -> Bool
prime n   = all ((/= 0).mod n) [2..n-1] 
--primes: devuelve una lista infinita de primos
primes :: [Int]
primes    = 1 : 2 : [ x | x <- [3,5..], prime x ]
--primesMen: devuelve una lista con los primos menores a n
primesMen :: Int -> [Int]
primesMen n = takeWhile (< n) primes
--primeraMitad: devuelve una lista con los primos menores a n/2
primeraMitad :: Int -> [Int]
primeraMitad n = takeWhile (\x -> 2*x < n) (primesMen n)
--segundaMitad: devuelve una lista con los primos mayores o iguales a n/2 y menores a n
segundaMitad :: Int -> [Int]
segundaMitad n = reverse (drop (length (primeraMitad n)) (primesMen n))

--Fin funciones para el calculo de primos


-- Funciones de evaluacion de resultado 

--esIgual: devuelve true si x+y es igual a n y false en el caso contrario
esIgual :: Int -> Int -> Int -> Bool
esIgual n x y = x + y == n
--esMenor: devuelve true si x+y es menor a n y false en el caso contrario
esMenor :: Int -> Int -> Int -> Bool
esMenor n x y = x + y < n
--esPar: devuelve true si n es par y false en caso contrario
esPar :: Int -> Bool
esPar x = x `mod` 2 == 0

--Fin funciones de evaluacion de resultado


--Funcion recursiva

--verifican: devuelve una lista con los pares de primos que suman n
  {-
  --si y es vacia, devuelve la lista primos sin modificar
  --si x es vacia, evalua el ultimo valor de la lista y
    --si el ultimo valor *2 es igual a n, lo añade a la lista primos y la devuelve
    --si el ultimo valor de y *2 no es igual a n, devuelve la lista primos sin modificar
  --si x e y son no vacias, evalua el valor obtenido al sumar el primer elemento de x e y
  --y actua en consecuencia
  -}
verifican :: Int -> [Int] -> [Int] -> [(Int, Int)] -> [(Int, Int)]
verifican n x [] primos = primos --y es vacia
verifican n [] y primos --x es vacia
  | head (reverse y) * 2 == n = (head (reverse y), head (reverse y)):primos
  | otherwise = primos
verifican n x y primos
  | esMenor n (head x) (head y) = verifican n (tail x) y primos --ni x ni y son vacios
  | esIgual n (head x) (head y) = let nuevosPrimos = ((head x),(head y)):primos
                                  in verifican n (tail x) (tail y) nuevosPrimos
  | otherwise = verifican n x (tail y) primos

--goldbach: devuelve una lista de pares primos cuya suma es igual a n
goldbach :: Int -> [(Int, Int)]
goldbach n
  | esPar n = let primos = []
                  primos' = verifican n (primeraMitad n) (segundaMitad n) primos
              in reverse primos'
  | otherwise = [(-1, -1)]


--Inicializacion de la variable
n = 74
--Funcion principal
main = do
  print $ n
  print $ goldbach n

