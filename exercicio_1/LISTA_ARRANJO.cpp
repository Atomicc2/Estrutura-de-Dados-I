#include <iostream>
#include <fstream>
#include <sstream>
#include "LISTA_ARRANJO.h"
using namespace std;

void Cria(TLista& Lista) {
    Lista.tamanho = 0;
}

void Imprime(TLista Lista) {
    for(int i = 0; i < Lista.tamanho; i++) {
        cout << Lista.itens[i].ID << " ";
    }
    cout << endl;
}

void InsereInicio(TLista& Lista, TInfo Item) {
    if(Lista.tamanho < Tmax) {
        for(int i = Lista.tamanho; i > 0; i--) {
            Lista.itens[i] = Lista.itens[i-1];
        }
        Lista.itens[0] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }
}

void InserePosicao(TLista& Lista, int pos, TInfo Item) {
    if(Lista.tamanho < Tmax) {
        for(int i = Lista.tamanho; i > pos; i--) {
            Lista.itens[i] = Lista.itens[i-1];
        }
        Lista.itens[pos] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }   
}

void InsereFinal(TLista& Lista, TInfo Item){
    if(Lista.tamanho < Tmax) {
        Lista.itens[Lista.tamanho] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }
}

void InsereOrdenado(TLista& Lista, TInfo Item) {
    if(Lista.tamanho < Tmax) {
        int pos = 0;
        while(pos < Lista.tamanho && Lista.itens[pos].ID < Item.ID) {
            pos++;
        }
        for(int i = Lista.tamanho; i > pos; i--) {
            Lista.itens[i] = Lista.itens[i-1];
        }
        Lista.itens[pos] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }
}

void RemoveInicio(TLista& Lista) {
    if(Lista.tamanho > 0) {
        for(int i = 0; i < Lista.tamanho -1; i++) {
            Lista.itens[i] = Lista.itens[i+1];
        }
        Lista.tamanho--;
    } else {
        cout << "Lista vazia. Não é possível remover." << endl;
    }
}

void RemoveFinal(TLista& Lista) {
    if(Lista.tamanho > 0) {
        Lista.tamanho--;
    } else {
        cout << "Lista vazia. Não é possível remover." << endl;
    }

}

void PesquisaRemove(TLista& Lista, int Chave) {
    if(Lista.tamanho > 0) {
        for(int i = 0; i < Lista.tamanho; i++) {
            if(Lista.itens[i].ID == Chave) {
                for(int j = i; j < Lista.tamanho -1; j++) {
                    Lista.itens[j] = Lista.itens[j+1];
                }
                Lista.tamanho--;
            } else {
                cout << "Chave não encontrada." << endl;
            }
        }
    } else {
        cout << "Lista vazia. Não é possível remover." << endl;
    }
}

void CarregaArquivo(TLista& Lista, const string nomeArquivo) {
    
    ifstream arquivo(nomeArquivo);
    if(!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }
    
    string linha;
    while(getline(arquivo, linha) && Lista.tamanho < Tmax) {
        stringstream ss(linha);
        string campo;
        TInfo item;
        getline(ss, campo, ';');
        item.ID = stoi(campo);
        getline(ss, item.Rodovia, ';');
        getline(ss, item.Cidade, ';');
        getline(ss, item.Data, ';');
        getline(ss, item.DiaSemana, ';');
        getline(ss, item.Hora, ';');
        getline(ss, item.TipoAcidente, ';');
        getline(ss, campo, ';');
        item.Feridos = stoi(campo);
        getline(ss, campo, ';');
        item.Mortos = stoi(campo);
        getline(ss, item.Descricao, ';');
        InsereFinal(Lista, item);
    }
    arquivo.close();
}

int PesquisaPorID(TLista& Lista, int ID) {
    for(int i = 0; i < Lista.tamanho; i++) {
        if(Lista.itens[i].ID == ID) {
            return Lista.itens[i].ID;
        }
    }
    return -1;
}


void ImprimeAcidentes(TLista& Lista, int ID) {
    for(int i = 0; i < Lista.tamanho; i++) {
        if(Lista.itens[i].ID == ID) {
            cout << "ID: " << Lista.itens[i].ID << endl;
            cout << "Rodovia: " << Lista.itens[i].Rodovia << endl;
            cout << "Cidade: " << Lista.itens[i].Cidade << endl;
            cout << "Data: " << Lista.itens[i].Data << endl;
            cout << "Dia da Semana: " << Lista.itens[i].DiaSemana << endl;
            cout << "Hora: " << Lista.itens[i].Hora << endl;
            cout << "Tipo de Acidente: " << Lista.itens[i].TipoAcidente << endl;
            cout << "Feridos: " << Lista.itens[i].Feridos << endl;
            cout << "Mortos: " << Lista.itens[i].Mortos << endl;
            cout << "Descrição: " << Lista.itens[i].Descricao << endl;
        }
    }
}

void ImprimeAcidentesPorCidade(TLista& Lista, string Cidade) {
    bool encontrado = false;
    for(int i = 0; i < Lista.tamanho; i++) {
        if(Lista.itens[i].Cidade == Cidade) {
            encontrado = true;
            cout << "ID: " << Lista.itens[i].ID << endl;
            cout << "Rodovia: " << Lista.itens[i].Rodovia << endl;
            cout << "Cidade: " << Lista.itens[i].Cidade << endl;
            cout << "Data: " << Lista.itens[i].Data << endl;
            cout << "Dia da Semana: " << Lista.itens[i].DiaSemana << endl;
            cout << "Hora: " << Lista.itens[i].Hora << endl;
            cout << "Tipo de Acidente: " << Lista.itens[i].TipoAcidente << endl;
            cout << "Feridos: " << Lista.itens[i].Feridos << endl;
            cout << "Mortos: " << Lista.itens[i].Mortos << endl;
            cout << "Descrição: " << Lista.itens[i].Descricao << endl;
            cout << "---" << endl;
        }
    }
    if(!encontrado) {
        cout << "Nenhum acidente encontrado para a cidade: " << Cidade << endl;
    }
}