{-****************************************************************
 * File:   Lsystem.hs
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   22 abril 2023
 * Coms:   Practica 5 - Modulo con la funcion lsystem
******************************************************************-}

module Lsystem where

--Lista de funciones con las reglas de cada imagen

rules :: Char -> String
rules 'F' = "G-F-G"
rules 'G' = "F+G+F"
rules x = [x]

rulesKoch :: Char -> String
rulesKoch 'F' = "F+F--F+F"
rulesKoch x = [x]

rulesKochCuad :: Char -> String
rulesKochCuad 'F' = "F+F-F-F+F"
rulesKochCuad x = [x]

rulesSnowflake :: Char -> String
rulesSnowflake 'F' = "F-F++F-F"
rulesSnowflake x = [x]

rulesAntiSnowflake :: Char -> String
rulesAntiSnowflake 'F' = "F+F--F+F"
rulesAntiSnowflake x = [x]

rulesMinkowski :: Char -> String
rulesMinkowski 'F' = "F+F-F-FF+F+F-F"
rulesMinkowski x = [x]

rulesSierpinski :: Char -> String
rulesSierpinski 'F' = "F-G+F+G-F"
rulesSierpinski 'G' = "GG"
rulesSierpinski x = [x]

rulesArrowHead :: Char -> String
rulesArrowHead 'F' = "G-F-G"
rulesArrowHead 'G' = "F+G+F"
rulesArrowHead x = [x]

rulesHilbert :: Char -> String
rulesHilbert 'f' = "-g>+f>f+>g-"
rulesHilbert 'g' = "+f>-g>g->f+"
rulesHilbert x = [x]

rulesGosper :: Char -> String
rulesGosper 'F' = "F-G--G+F++FF+G-"
rulesGosper 'G' = "+F-GG--G-F++F+G"
rulesGosper x = [x]

--Extras
rulesDragon :: Char -> String
rulesDragon 'F' = "F+G"
rulesDragon 'G' = "F-G"
rulesDragon x = [x]

rulesPleasantError :: Char -> String
rulesPleasantError 'F' = "F-F++F+F-F-F"
rulesPleasantError x = [x]

rulesPerroSalchicha :: Char -> String
rulesPerroSalchicha 'F' = "FG+"
rulesPerroSalchicha 'G' = "GGF>F"
rulesPerroSalchicha x = [x]

rulesCirculosConcentricos :: Char -> String
rulesCirculosConcentricos 'F' = "FG+"
rulesCirculosConcentricos 'G' = "FFG"
rulesCirculosConcentricos x = [x]

--Función Lsystem para generar la cadena para cada imagen
lsystem :: (Char -> String) -> String -> Int -> String
lsystem rules f 0 = f
lsystem rules "F" n = lsystem rules "G-F-G" (n-1)
lsystem rules "G" n = lsystem rules "F+G+F" (n-1)  
lsystem rules f n = lsystem rules (concat (map rules f)) (n-1)