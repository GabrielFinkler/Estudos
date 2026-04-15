#include <iostream>
using namespace std;

/* =========================
   PILHA - VETORES
   ========================= */

struct Pilha {
    int dados[100];
    int topo;
};

void inicializar_pilha(Pilha &P) {
    P.topo = -1;
}

bool pilha_vazia(const Pilha &P) {
    return (P.topo == -1);
}

bool push(Pilha &P, int valor) {
    if(P.topo == 99) return false;
    P.topo++;
    P.dados[P.topo] = valor;
    return true;
}

bool pop(Pilha &P) {
    if(P.topo == -1) return false;
    P.topo--;
    return true;
}

int top(const Pilha &P) {
    if(P.topo == -1) return -1;
    return P.dados[P.topo];
}

void imprimir_pilha(const Pilha &P) {
    cout << "[";
    for(int i = P.topo; i >= 0; i--){
        cout << P.dados[i] << " " ;
    }
    cout << "]";
}

void liberar_pilha(Pilha &P) {
    P.topo = -1;
}

/* =========================
   FILA - LISTAS ENCADEADAS
   ========================= */

struct No{
    int valor;
    No* prox;
};

struct Fila {
    No* inicio;
    No* fim;
};

void inicializar_fila(Fila &F) {
    F.inicio = nullptr;
    F.fim = nullptr;
}

bool fila_vazia(const Fila &F) {
    if(F.inicio == nullptr)
        return true;
    return false;
}

bool fila_cheia(const Fila &F) {
    // Visto que a fila foi implementada utilizando uma lista encadeada ela não tem limite de itens.(A não ser quando acabar a memória)
    return false;
}

bool enqueue(Fila &F, int valor) {
    No* atual = new No();
    atual->valor = valor;
    atual->prox = nullptr;
    if(fila_vazia(F)){
        F.inicio = atual;
        F.fim = atual;
        return true;
    }
         F.fim->prox = atual;
         F.fim = atual;
    return true;
}

bool dequeue(Fila &F) {
    No* temp = F.inicio;
    if(fila_vazia(F)){
        return false;
    }if(F.inicio == F.fim){
        F.inicio = nullptr;
        F.fim = nullptr;
        delete temp;
        return true;
    }
        F.inicio = F.inicio->prox;
        delete temp; 
    return true;
}

int front(const Fila &F) {
        return F.inicio->valor;
}

void imprimir_fila(const Fila &F) {
    No* atual = F.inicio;
    cout << "[ ";
    while(atual != nullptr){
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << "]";
}


/* =========================
   MENUS
   ========================= */
void menu_principal() {
    cout << "\n===== LABORATORIO 4 =====\n";
    cout << "1. Testar Pilha\n";
    cout << "2. Testar Fila\n";
    cout << "0. Sair\n";
    cout << "Opcao: ";
}

void menu_pilha() {
    cout << "\n--- PILHA ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Top\n";
    cout << "4. Imprimir\n";
    cout << "0. Voltar\n";
    cout << "Opcao: ";
}

void menu_fila() {
    cout << "\n--- FILA ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Front\n";
    cout << "4. Imprimir\n";
    cout << "0. Voltar\n";
    cout << "Opcao: ";
}

int main() {
    Pilha P;
    Fila F;

    inicializar_pilha(P);
    inicializar_fila(F);

    int op;

    do {
        menu_principal();
        cin >> op;

        if (op == 1) {
            int op2;
            do {
                menu_pilha();
                cin >> op2;

                switch (op2) {
                    case 1: {
                        int v;
                        cout << "Valor: ";
                        cin >> v;
                        if (push(P, v)) cout << "Inserido.\n";
                        break;
                    }
                    case 2:
                        if (pop(P)) cout << "Removido.\n";
                        else cout << "Pilha vazia.\n";
                        break;
                    case 3:
                        if (!pilha_vazia(P)) cout << "Topo = " << top(P) << endl;
                        else cout << "Pilha vazia.\n";
                        break;
                    case 4:
                        imprimir_pilha(P);
                        break;
                }
            } while (op2 != 0);
        }

        if (op == 2) {
            int op2;
            do {
                menu_fila();
                cin >> op2;

                switch (op2) {
                    case 1: {
                        int v;
                        cout << "Valor: ";
                        cin >> v;
                        if (enqueue(F, v)) cout << "Inserido.\n";
                        break;
                    }
                    case 2:
                        if (dequeue(F)) cout << "Removido.\n";
                        else cout << "Fila vazia.\n";
                        break;
                    case 3:
                        if (!fila_vazia(F)) cout << "Front = " << front(F) << endl;
                        else cout << "Fila vazia.\n";
                        break;
                    case 4:
                        imprimir_fila(F);
                        break;
                }
            } while (op2 != 0);
        }
    } while (op != 0);

    liberar_pilha(P);

    return 0;
}
