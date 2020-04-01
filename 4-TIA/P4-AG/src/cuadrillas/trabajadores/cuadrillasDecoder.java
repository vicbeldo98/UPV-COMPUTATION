package cuadrillas.trabajadores;

import java.util.*;

import org.opt4j.core.genotype.*;
import org.opt4j.core.problem.Decoder;

public class cuadrillasDecoder 
	implements Decoder<SelectGenotype<Integer>, ArrayList<Integer>>{
	
	public ArrayList<Integer> decode(SelectGenotype<Integer> genotype){
		
		ArrayList<Integer> phenotype=new ArrayList<Integer>();
			
		for (int i=0;i<genotype.size();i++) {
			phenotype.add(genotype.getValue(i));
		}
		return phenotype;
	}
}
