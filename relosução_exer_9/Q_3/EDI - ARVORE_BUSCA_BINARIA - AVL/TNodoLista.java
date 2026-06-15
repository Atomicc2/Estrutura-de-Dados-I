
public class TNodoLista {

	TInfo item;
	TNodoLista proximo; 
	TNodo nodo;

	public TNodoLista (TNodo nodo) { 
		if (nodo != null) {  
			this.item = new TInfo(nodo.item.prioridade,nodo.item.nome, nodo.item.sintomas);
			this.nodo = nodo;
			this.proximo = null;
		}
	}

}
