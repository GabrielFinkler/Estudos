#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

struct Lista {
    No* inicio;
};

void inicializar(Lista &L) {
    L.inicio = nullptr;
}

bool vazia(const Lista &L) {
    return L.inicio == nullptr;
}

void imprimir(const Lista &L) {
    No* atual = L.inicio;

    cout << "[ ";
    while (atual != nullptr) {
        cout << atual->valor << " ";

        atual = atual->prox;
    }
    cout << "]" << endl;
}

/* IMPLEMENTAR AS FUNCOES ABAIXO */

void inserir_inicio(Lista &L, int valor) {    
    No* novo = new No();
    novo->valor = valor;
    if(L.inicio == nullptr){
        L.inicio = novo;
    }else{
        novo->prox = L.inicio;
        L.inicio = novo;
    }
}

void inserir_final(Lista &L, int valor) {
    No* novo = new No();
    novo->valor = valor;
    novo->prox = nullptr;
    if(L.inicio == nullptr){
        L.inicio = novo;
    }else{
        No* atual = L.inicio;
        while(atual->prox != nullptr){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

No* buscar(const Lista &L, int valor) {
    No* atual = L.inicio;
    while(atual != nullptr){
        if(atual->valor == valor){
            return atual;
        }
        atual = atual->prox;
    }
    return nullptr;
}

bool remover_valor(Lista &L, int valor) {
    if(L.inicio == nullptr){
        cout << "A lista ja está vazia.";
        return false;
    }else{
        No* atual = L.inicio;
        if(atual->prox == nullptr ){
            if(atual->valor == valor){
                delete atual;
                L.inicio = nullptr;
                cout << "A lista possuia somente esse valor, a lista foi apagada";
                return true;
            }else
                return false;
        }else{
            if(atual->valor == valor){
                L.inicio = atual->prox;
                delete atual;
                return true;
            }else{
                No* anterior = L.inicio;
                atual = atual->prox;
                while(atual != nullptr){
                    if(atual->valor == valor){
                        anterior->prox = atual->prox;
                        delete atual;
                        return true;
                    }
                    anterior = atual;
                    atual = atual->prox;
                    
                }
                return false;
            }

        }
    }
}

void liberar_lista(Lista &L) {
    if(L.inicio == nullptr){
        cout << "A lista ja se encontra vazia.";
    }else{
        No* atual = L.inicio;
        No* temp;
        while(atual != nullptr){
                temp = atual->prox;
                delete atual;
                atual = temp;
        }
        L.inicio = nullptr;
    }
}

void mostrar_menu() {
    cout << "\n===== MENU - LISTA ENCADEADA =====\n";
    cout << "1. Inicializar lista\n";
    cout << "2. Inserir no inicio\n";
    cout << "3. Inserir no final\n";
    cout << "4. Buscar valor\n";
    cout << "5. Remover valor\n";
    cout << "6. Imprimir lista\n";
    cout << "7. Verificar se a lista esta vazia\n";
    cout << "8. Liberar memoria da lista\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    Lista L;
    inicializar(L);

    int opcao;

    do {
        mostrar_menu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                liberar_lista(L);
                inicializar(L);
                cout << "Lista inicializada com sucesso.\n";
                break;
            }

            case 2: {
                int valor;
                cout << "Digite o valor a inserir no inicio: ";
                cin >> valor;
                inserir_inicio(L, valor);
                cout << "Valor inserido com sucesso.\n";
                break;
            }

            case 3: {
                int valor;
                cout << "Digite o valor a inserir no final: ";
                cin >> valor;
                inserir_final(L, valor);
                cout << "Valor inserido com sucesso.\n";
                break;
            }

            case 4: {
                int valor;
                cout << "Digite o valor a buscar: ";
                cin >> valor;

                No* p = buscar(L, valor);
                if (p != nullptr) {
                    cout << "Valor encontrado no no de endereco: " << p << endl;
                } else {
                    cout << "Valor nao encontrado.\n";
                }
                break;
            }

            case 5: {
                int valor;
                cout << "Digite o valor a remover: ";
                cin >> valor;

                if (remover_valor(L, valor)) {
                    cout << "Valor removido com sucesso.\n";
                } else {
                    cout << "Valor nao encontrado.\n";
                }
                break;
            }

            case 6: {
                cout << "Conteudo da lista: ";
                imprimir(L);
                break;
            }

            case 7: {
                if (vazia(L)) {
                    cout << "A lista esta vazia.\n";
                } else {
                    cout << "A lista nao esta vazia.\n";
                }
                break;
            }

            case 8: {
                liberar_lista(L);
                cout << "Memoria da lista liberada com sucesso.\n";
                break;
            }

            case 0: {
                liberar_lista(L);
                cout << "Encerrando o programa.\n";
                break;
            }

            default: {
                cout << "Opcao invalida. Tente novamente.\n";
                break;
            }
        }

    } while (opcao != 0);

    return 0;
}