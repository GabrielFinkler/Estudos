# Laboratório 4: Estruturas de Dados (Pilha e Fila)

Este projeto apresenta a implementação prática de duas estruturas de dados fundamentais: Pilha (Stack) e Fila (Queue), utilizando diferentes métodos de gerenciamento de memória em C++.

Funcionalidades

O programa oferece um ambiente interativo via terminal para testar as seguintes estruturas:

1. Pilha (Stack) - Implementação com Vetor
A pilha segue o princípio LIFO(Last In, First Out), onde o último elemento inserido é o primeiro a ser removido.
* Armazenamento: Estático (Vetor de 100 inteiros).
* Operações Disponíveis:
    * `Push`: Insere um elemento no topo.
    * `Pop`: Remove o elemento do topo.
    * `Top`: Exibe o valor que está no topo sem remover.
    * `Imprimir`: Mostra todos os elementos da pilha.



2. Fila (Queue) - Implementação com Lista Encadeada
A fila segue o princípio FIFO (First In, First Out), onde o primeiro elemento inserido é o primeiro a ser removido.
* Armazenamento: Dinâmico (Uso de ponteiros e nós encadeados).
* Operações Disponíveis:
    * `Enqueue`: Insere um novo nó no fim da fila.
    * `Dequeue`: Remove o nó do início da fila e libera a memória.
    * `Front`: Exibe o primeiro valor da fila.
    * `Imprimir`: Percorre a lista e exibe todos os valores.



---


📂 Organização do Código
Pilha: Implementada através da struct Pilha contendo um array fixo e um inteiro topo.

Fila: Implementada através da struct No (nó da lista) e struct Fila (contendo ponteiros para inicio e fim).

