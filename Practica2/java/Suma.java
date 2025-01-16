/*****************************************************************
 * File:   Suma.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase Suma, subclase de Programa
*****************************************************************/

public class Suma extends Programa {
    public Suma()
	{
		nInstrucciones = 4;
        instrucciones = new Instruccion[nInstrucciones];
        instrucciones[0] = new Read();
        instrucciones[1] = new Read();
        instrucciones[2] = new Add();
        instrucciones[3] = new Write();
	}
}
