{-****************************************************************
 * File:   Tplot.hs
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   20 abril 2023
 * Coms:   Practica 5 - Modulo con la funcion tplot
******************************************************************-}

module Tplot where
import Turtle

getpos :: Turtle -> Position
getpos (_,_,pos,_) = pos
--

step :: Turtle -> Char -> Turtle
step tortuga s = case s of
   '>' -> moveTurtle tortuga Forward
   'F' -> moveTurtle tortuga Forward
   'G' -> moveTurtle tortuga Forward
   '+' -> moveTurtle tortuga TurnRight 
   '-' -> moveTurtle tortuga TurnLeft
   _ -> tortuga

tplot :: Turtle -> String -> [Position]
tplot tortuga [] = []
tplot tortuga str = getpos tortuga : tplot (step tortuga (head str)) (tail str)
