package persistencia;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import comunicacion.PeliculaDTO;
import excepciones.DAOExcepcion;



public class PeliculaDAO {
	
	private ConnectionManager connManager;


	public PeliculaDAO(ConnectionManager connManager) throws ClassNotFoundException {
			this.connManager= connManager;
	}
	
	
	public PeliculaDTO buscarPeliculaPorCod(String cod)	throws DAOExcepcion{
		try{
			String query = "SELECT * FROM MOVIE M WHERE M.MOVIE_CODE='"+cod+"'";
			
			if (query.compareTo("")==0 || query.isEmpty()) return null;
			
			ResultSet rs=connManager.queryDB(query);
			
				
			if (rs.next())
				return new PeliculaDTO(rs.getString("MOVIE_CODE"),rs.getString("TITLE"),rs.getString("YEAR"),rs.getInt("LENGTH"),rs.getString("BOOK_CODE"),rs.getString("DIRECTOR"));
	
			return null;
		}
		catch (Exception e){		throw new DAOExcepcion(e);}
	}
	
		
	public void crearPelicula(PeliculaDTO peli) throws DAOExcepcion {
		try{
			String query = "";
			
			if (query.compareTo("")==0 || query.isEmpty()) return;
			
			connManager.updateDB(query);
			
		}
		catch (Exception e){		throw new DAOExcepcion(e);}
	}

 

	public List<PeliculaDTO> buscarPeliculas() throws DAOExcepcion{
		try{
			List<PeliculaDTO> listaPeliculas=new ArrayList<PeliculaDTO>();
			String query = "SELECT * FROM MOVIE";
			
			if (query.compareTo("")==0 || query.isEmpty()) return listaPeliculas;
			
			ResultSet rs=connManager.queryDB(query);						
				
			try{				
				while (rs.next()){
					PeliculaDTO peli = new PeliculaDTO(rs.getString("MOVIE_CODE"),rs.getString("TITLE"),rs.getString("YEAR"),rs.getInt("LENGTH"),rs.getString("BOOK_CODE"),rs.getString("DIRECTOR")); 
					listaPeliculas.add(peli);
				}
				return listaPeliculas;
			}
			catch (Exception e){	throw new DAOExcepcion(e);}
		}
		catch (DAOExcepcion e){		throw e;}	
	}
		
}
