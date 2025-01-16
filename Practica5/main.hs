{-****************************************************************
 * File:   main.hs
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   20 abril 2023
 * Coms:   Practica 5 - Programa principal
******************************************************************-}

import Tplot
import SVG(savesvg)
import Lsystem

--Programa principal
main :: IO()
main = do
   let  
      --BASICOS
      cuadrado = tplot (1,90,(0,0),90) ">+>+>+>+"
      trianguloInvertido = tplot (1,120,(0,0),0) ">->->-"
      triangulo = tplot (1,120,(0,0),0) ">+>+>+"
      circulo = tplot (1, 1, (0,0),0) ">+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+"
      --L-SYSTEM
      koch = (tplot (1,60,(0,0),-60) (lsystem rulesKoch "F" 4))
      kochCuadrada = (tplot (1,90,(0,0),-90) (lsystem rulesKochCuad "F" 4))
      snowflake = (tplot (1,60,(0,0),0) (lsystem rulesSnowflake "F++F++F" 3))
      antiSnowflake = (tplot (1,60,(0,0),180) (lsystem rulesAntiSnowflake "F++F++F" 4))
      minkowski = (tplot (1,90,(0,0),0) (lsystem rulesMinkowski "F+F+F+F" 2))
      sierpinski = (tplot (1,120,(0,0),180) (lsystem rulesSierpinski "F-G-G" 4))
      arrowHead = (tplot (1,60,(0,0),0) (lsystem rulesArrowHead "F" 6))
      hilbert = (tplot (1,90,(0,0),180) (lsystem rulesHilbert "f" 4))
      gosper = (tplot (1,60,(0,0),0) (lsystem rulesGosper "F" 3)) --no sale la figura del pdf
      gosper2 = (tplot (1,60,(0,0),0) (lsystem rulesGosper "FG" 3)) --mas similar
      --EXTRAS
      dragon = (tplot (1,90,(0,0),0) (lsystem rulesDragon "F" 14))
      pleasantError = (tplot (1,72,(0,0),-20) (lsystem rulesPleasantError "F-F-F-F-F" 4))
      circulosConcentricos = (tplot (1,35,(0,0),0) (lsystem rulesCirculosConcentricos "FG" 8))
      perritoSalchica = (tplot (1,50,(0,0),40) (lsystem rulesPerroSalchicha "FG" 8))

   --Basicos
   savesvg "cuadrado" cuadrado
   savesvg "trianguloInventido" trianguloInvertido
   savesvg "triangulo" triangulo
   savesvg "circulo" circulo
   --L-Systems
   savesvg "Koch" koch 
   savesvg "Koch-cuadrada" kochCuadrada
   savesvg "Snowflake" snowflake
   savesvg "Anti-Snowflake" antiSnowflake
   savesvg "Minkowski" minkowski
   savesvg "Sierpinski" sierpinski
   savesvg "ArrowHead" arrowHead
   savesvg "Hilbert" hilbert
   savesvg "Gosper" gosper
   --Otros L-Systems
   savesvg "Dragon" dragon
   savesvg "PleasantError" pleasantError
   savesvg "CirculosConcentricos" circulosConcentricos
   savesvg "PerritoSalchica" perritoSalchica
