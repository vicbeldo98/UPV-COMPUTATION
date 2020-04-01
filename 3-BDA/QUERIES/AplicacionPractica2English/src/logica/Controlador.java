package logica;
import excepciones.*;

import java.util.*;

import comunicacion.ActorDTO;
import comunicacion.ActuaDTO;
import comunicacion.LibroDTO;
import comunicacion.PeliculaDTO;
import persistencia.*;


public class Controlador {
	private DAL dal;
	
	//****************************************************************
	//****		CREACIÓN DEL CONTROLADOR
	//****************************************************************

	public Controlador() throws DAOExcepcion{
		
	}
		
	
	//****************************************************************
	//****     Conectar con la capa de presistencia
	//****************************************************************
	public void connectarDAL(String usuario, String password) throws DAOExcepcion{
			try{
				//Comunicación con la capa de acceso a datos
				dal = new DAL(usuario, password);//.dameDAL();
				dal.probarConexion();
			} 
			catch (DAOExcepcion e){		throw new DAOExcepcion (e);}
	}
	
	public void desconectar() throws DAOExcepcion{
		dal = null;
	}
	
	
	
	
	
	//****************************************************************
	//****     ACCESO A LOS MÉTODOS PELICULA DAL
	//****************************************************************
	public PeliculaDTO buscarPeliculaPorCod(String cod) throws DAOExcepcion{
		return dal.buscarPeliculaPorCod(cod);
	}
	
	public void crearPelicula (PeliculaDTO peli) throws LogicaExcepcion{
		try{	
			if (dal.buscarPeliculaPorCod(peli.getCod_peli())==null){
				dal.crearPelicula(peli);
			}
			else throw new LogicaExcepcion("This movie exists in the database.");
		}
		catch (DAOExcepcion e){		throw new LogicaExcepcion(e);}
	}
	
	public List<PeliculaDTO> buscarPeliculas() throws LogicaExcepcion{
		try{
			return dal.buscarPeliculas();
		}
		catch (DAOExcepcion e){		throw new LogicaExcepcion(e);}
	}
	
	//****************************************************************
	//****     ACCESO A LOS MÉTODOS LIBRO DAL
	//****************************************************************
	public LibroDTO buscarLibroPorCod(String cod) throws DAOExcepcion{
			return dal.buscarLibroPorCod(cod);
	}
		
			
	public List<LibroDTO> buscarLibros() throws LogicaExcepcion{
		try{
			return dal.buscarLibros();
		}
		catch (DAOExcepcion e){		throw new LogicaExcepcion(e);}
	}
	
	//****************************************************************
	//****     ACCESO A LOS MÉTODOS ACTOR DAL
	//****************************************************************
	public ActorDTO buscarActorPorCod(String cod) throws DAOExcepcion{
			return dal.buscarActorPorCod(cod);
	}
			
				
	public List<ActorDTO> buscarActores() throws LogicaExcepcion{
		try{
			return dal.buscarActores();
		}
		catch (DAOExcepcion e){		throw new LogicaExcepcion(e);}
	}
	public List<ActorDTO> buscarActoresPorCodPeli(String cod) throws LogicaExcepcion{
		try{
			return dal.buscarActoresPorCodPeli(cod);
		}
		catch (DAOExcepcion e){		throw new LogicaExcepcion(e);}
	}


	public void crearActuacion(ActuaDTO actua) throws LogicaExcepcion {
		try{	
			if (dal.buscarActuacionPorPeliActor(actua.getCod_peli(), actua.getCod_act())==null){
				dal.crearActuacion(actua);
			}
			else throw new LogicaExcepcion("This \"Acts\" exists in the database.");
		}
		catch (DAOExcepcion e){		throw new LogicaExcepcion(e);}
		
	}


	
		
}
