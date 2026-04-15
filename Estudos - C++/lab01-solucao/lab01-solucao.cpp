#include <iostream>
using namespace std;

const int MAX = 100;

struct Lista {
    int dados[MAX];
    int tamanho;
};

void inicializar(Lista &L) {
    L.tamanho = 0;
}

bool cheia(Lista &L) {
    return L.tamanho == MAX;
}

bool vazia(Lista &L) {
    return L.tamanho == 0;
}

void imprimir(Lista &L) {
    cout << "[ ";
    for (int i = 0; i < L.tamanho; i++) {
        cout << L.dados[i] << " ";
    }
    cout << "]" << endl;
}

/* IMPLEMENTAR ABAIXO */

bool inserir_final(Lista &L, int valor) { 
    if(L.tamanho < MAX){
        L.dados[L.tamanho] = valor;
        ++L.tamanho;
    }else
        return false;
    return true;
}

bool inserir_posicao(Lista &L, int valor, int pos) {
    if(pos < 0 || pos > MAX){
        return false;
    }
    for(int i = L.tamanho - 1;i >= pos ;i--){
        L.dados[i+1] = L.dados[i];
    }
    L.dados[pos] = valor;
    ++L.tamanho;
    return true;
}

bool remover_posicao(Lista &L, int pos) {
    if(pos < 0 || pos >= L.tamanho){
        return false;
    }
    for(int i = pos; i < L.tamanho - 1; i++){
        L.dados[i] = L.dados[i + 1];
    }
    --L.tamanho;

    return true;
}

int buscar(Lista &L, int valor) {
    for(int i = 0; i < L.tamanho; i++){
        if(L.dados[i] == valor){
            return i;
        }
    }
    return -1;
}

bool remover_valor ( Lista &L , int valor ){
    int posicao = buscar(L,valor);
    if(posicao == -1){
        return false;
    }else
        remover_posicao(L, posicao);
    return true;
}

int main() {

    Lista L;
    inicializar(L);
    
    inserir_final(L, 10);
    inserir_final(L, 20);
    inserir_final(L, 30);

    imprimir(L);

    inserir_posicao(L, 15, 1);
    imprimir(L);
    remover_valor(L,15);
    imprimir(L);
    remover_posicao(L, 2);
    imprimir(L);

    
    
    cout << "Posicao do 20: " << buscar(L,20) << endl;

}