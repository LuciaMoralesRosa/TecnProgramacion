/*****************************************************************
 * File:   CuentaAtras.java
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Implementación de la clase CuentaAtras, subclase de Programa
*****************************************************************/

public class CuentaAtras extends Programa {
    public CuentaAtras()
	{
		nInstrucciones = 7;
        instrucciones = new Instruccion[nInstrucciones];
        instrucciones[0] = new Read();
        instrucciones[1] = new Dup();
        instrucciones[2] = new Write();
        instrucciones[3] = new Push(-1);
        instrucciones[4] = new Add();
        instrucciones[5] = new Dup();
        instrucciones[6] = new JumpIf(1);
	}
}