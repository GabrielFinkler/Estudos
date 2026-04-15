Lista Sequencial em C++


A lista guarda números inteiros e controla quantos elementos existem usando a variável tamanho.

Estrutura da lista
struct Lista {
    int dados[MAX];
    int tamanho;
};

dados → vetor onde os valores são armazenados

tamanho → quantidade de elementos atualmente na lista

MAX → tamanho máximo da lista (100)

Funções principais

inicializar
Define o tamanho da lista como 0, deixando a lista vazia.

inserir_final
Adiciona um elemento no final da lista.

inserir_posicao
Insere um valor em uma posição específica da lista.
Os elementos depois dessa posição são deslocados para a direita.

remover_posicao
Remove um elemento de uma posição da lista.
Os elementos seguintes são deslocados para a esquerda.

buscar
Procura um valor na lista e retorna sua posição.
Se não encontrar, retorna -1.

remover_valor
Procura um valor na lista e remove ele se existir.

imprimir
Mostra os elementos da lista no formato:

[ 10 20 30 ]