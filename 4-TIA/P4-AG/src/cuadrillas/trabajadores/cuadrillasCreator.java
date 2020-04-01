package cuadrillas.trabajadores;

import java.util.*;

import org.opt4j.core.genotype.*;
import org.opt4j.core.problem.Creator;

public class cuadrillasCreator implements Creator<SelectGenotype<Integer>>{
	
	public SelectGenotype<Integer> create(){
		List<Integer> numeros = new ArrayList<Integer>();
		for(int i=1; i<=Datos.NUM_TURNOS;i++) {
			numeros.add(i);
		}
		SelectGenotype<Integer> genotype = new SelectGenotype<Integer>(numeros);
		
		genotype.init(new Random(), Datos.NUM_CUADRILLAS);
		return genotype;
	}
}
