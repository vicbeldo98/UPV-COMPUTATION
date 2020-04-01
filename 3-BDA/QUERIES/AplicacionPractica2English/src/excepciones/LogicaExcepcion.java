package excepciones;

@SuppressWarnings("serial")
public class LogicaExcepcion extends Exception{

	
		public LogicaExcepcion(String message) {
			super(message);
			// TODO Auto-generated constructor stub
		}
		

		public LogicaExcepcion(Exception e) {
			super(e.getMessage());
			// TODO Auto-generated constructor stub
		}

	

	
	
}
