package comunicacion;

public class LibroDTO {

	private String cod_lib;
	private String titulo;
	private int anyo;
	private String autor;
	
	public LibroDTO(String cod_lib, String titulo, int anyo, String autor) {
		this.cod_lib = cod_lib;
		this.titulo = titulo;
		this.anyo = anyo;
		this.autor = autor;
	}
	
	public String getCod_lib() {
		return cod_lib;
	}

	public void setCod_lib(String cod_lib) {
		this.cod_lib = cod_lib;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public int getAnyo() {
		return anyo;
	}

	public void setAnyo(int anyo) {
		this.anyo = anyo;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}
	@Override
	public String toString() {
		return titulo;
	}


}
