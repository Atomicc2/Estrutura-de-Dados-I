
public class TInfo {
	public int prioridade;
	String nome;
	String sintomas;
	
	public TInfo(int prioridade, String nome, String sintomas){
		this.prioridade = prioridade;
		this.nome = nome;
		this.sintomas = sintomas;
	}
	
	public String toString(){
		//return prioridade+"-"+nome;
		return prioridade+"-"+nome+"-"+sintomas;
	}
	
	public int getPrioridade(){
		return prioridade;
	}
}