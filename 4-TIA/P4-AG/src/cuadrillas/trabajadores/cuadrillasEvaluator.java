package cuadrillas.trabajadores;

import java.util.*;

import org.opt4j.core.Objectives;
import org.opt4j.core.Objective.Sign;
import org.opt4j.core.problem.Evaluator;

public class cuadrillasEvaluator 
	implements Evaluator<ArrayList<Integer>>{
			
	public Objectives evaluate (ArrayList<Integer> phenotype) {
		
		int resultados = 0;
		//PARA LA AMPLIACION OSLO HAY QUE AÑADIR PRODUCTIVIDAD Y MAXIMIZARLA
		int productividad=0;
		int [] contador = new int[Datos.NUM_TURNOS+1];	
		for(int i=1;i<=Datos.NUM_TURNOS;i++) {
			contador[i]=0;
		}
		for(int i=0;i<phenotype.size();i++) {
			int turno = phenotype.get(i) - 1;
			//HE AÑADIDO UN +1 AQUÍ
			contador[turno+1]++;
			resultados+=Datos.matrizCostes[turno][i];
			productividad+=Datos.matrizProductividad[turno][i];
		}
		boolean turnos_ok=true;
		for(int i=1;i<=Datos.NUM_TURNOS;i++) {
			if(contador[i]<3)turnos_ok=false;
		}
		
		if(!turnos_ok) {
			resultados=Integer.MAX_VALUE;
		}
		
		Objectives objectives = new Objectives();
		
		objectives.add("Coste: ", Sign.MIN, resultados);
		objectives.add("Productividad: ", Sign.MAX, productividad);
		return objectives;
	}
}
