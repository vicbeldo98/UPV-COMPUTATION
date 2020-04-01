package comunicacion;



public class ActuaDTO {
	private String cod_act;
	private String cod_peli;
	private String papel;
	
	public ActuaDTO(String cod_act, String cod_peli, String papel) {
		this.cod_act = cod_act;
		this.cod_peli = cod_peli;
		this.papel = papel;
	}
	public String getCod_act() {
		return cod_act;
	}
	public void setCod_act(String cod_act) {
		this.cod_act = cod_act;
	}
	public String getCod_peli() {
		return cod_peli;
	}
	public void setCod_peli(String cod_peli) {
		this.cod_peli = cod_peli;
	}
	public String getPapel() {
		return papel;
	}
	public void setPapel(String papel) {
		this.papel = papel;
	}
	public String toStringCod_peli() {
		return "'"+cod_peli+"'";
	}
	public String toStringCod_act() {
		return "'"+cod_act+"'";
	}
	public String toStringPapel() {
		return "'"+papel+"'";
	}
}
