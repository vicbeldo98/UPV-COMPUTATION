package comunicacion;

import java.util.Date;

public class ActorDTO {

	private String cod_act;
	private String nombre;
	private Date fecha_nac;
	private String nom_pais; 

	public ActorDTO(String cod_act, String nombre, Date fecha_nac,
			String nom_pais) {
		this.cod_act = cod_act;
		this.nombre = nombre;
		this.fecha_nac = fecha_nac;
		this.nom_pais = nom_pais;
	}

	public String getCod_act() {
		return cod_act;
	}

	public void setCod_act(String cod_act) {
		this.cod_act = cod_act;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Date getFecha_nac() {
		return fecha_nac;
	}

	public void setFecha_nac(Date fecha_nac) {
		this.fecha_nac = fecha_nac;
	}

	public String getNom_pais() {
		return nom_pais;
	}

	public void setNom_pais(String nom_pais) {
		this.nom_pais = nom_pais;
	}

	@Override
	public String toString() {
		return nombre;
	}
}
