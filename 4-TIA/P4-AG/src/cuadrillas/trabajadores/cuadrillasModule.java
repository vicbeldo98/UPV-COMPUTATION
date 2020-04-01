package cuadrillas.trabajadores;

import org.opt4j.core.problem.ProblemModule;

public class cuadrillasModule 
	extends ProblemModule{
	protected void config() {
		bindProblem(cuadrillasCreator.class,cuadrillasDecoder.class,cuadrillasEvaluator.class);
	}
}
