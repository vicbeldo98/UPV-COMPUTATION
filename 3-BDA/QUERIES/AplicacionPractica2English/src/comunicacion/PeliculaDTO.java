package comunicacion;

import excepciones.LogicaExcepcion;

public class PeliculaDTO {
	private String cod_peli;
	private String titulo;
	private String anyo;
	private int duracion;
	private String cod_lib;
	private String director;
	
	public PeliculaDTO(String cod_peli, String titulo, String anyo, int duracion,
			String cod_lib, String director) throws LogicaExcepcion {
		this.cod_peli = cod_peli;
		this.titulo = titulo;
		this.anyo = anyo;
		setDuracion(duracion);
		this.cod_lib = cod_lib;
		this.director = director;
	}

	public String getCod_peli() {
		return cod_peli;
	}

	public void setCod_peli(String cod_peli) {
		this.cod_peli = cod_peli;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public String getAnyo() {
		return anyo;
	}

	public void setAnyo(String anyo) {
		this.anyo = anyo;
	}

	public int getDuracion() {
		return duracion;
	}

	public void setDuracion(int duracion) throws LogicaExcepcion {
		if (duracion<=0) throw new LogicaExcepcion("Lenght must be greater than zero.");
		this.duracion = duracion;
	}

	public String getCod_lib() {
		return cod_lib;
	}

	public void setCod_lib(String cod_lib) {
		this.cod_lib = cod_lib;
	}

	public String getDirector() {
		return director;
	}

	public void setDirector(String director) {
		this.director = director;
	}
	public String toStringCod_peli() {
		return "'"+cod_peli+"'";
	}
	public String toStringTitulo() {
		return "'"+titulo+"'";
	}
	public String toStringAnyo() {
		if (anyo==null || anyo.isEmpty()) return "NULL";
		else return anyo;
	}
	public String toStringDuracion() {
		return Integer.toString(duracion);
	}
	public String toStringCod_lib(){
		if (cod_lib==null) return "NULL";
		else return "'"+cod_lib+"'";
	}
	public String toStringDirector() {
		return "'"+director+"'";
	}
	@Override
	public String toString() {
		return titulo;
	}
}
