Lista Duplamente Encadeada em C++

Descrição:
Este programa implementa uma lista duplamente encadeada em C++.
Cada nó da lista possui:

um valor inteiro
um ponteiro para o próximo nó
um ponteiro para o nó anterior

A lista também pode ser convertida para circular, onde:

o último nó aponta para o primeiro
o primeiro nó aponta para o último

Estruturas
- No
	Representa um elemento da lista.
	Contém:

	valor → valor armazenado
	prox → ponteiro para o próximo nó
	ant → ponteiro para o nó anterior
- Lista

	Representa a lista.
	Contém:

	inicio → primeiro nó
	fim → último nó

Funcionalidades:
O programa possui um menu interativo com as seguintes operações:

-Inserir no início
Adiciona um novo elemento no começo da lista.
-Inserir no final
Adiciona um novo elemento no final da lista.
-Remover valor
Remove o primeiro nó que contém o valor informado.
-Tornar circular
Conecta o último nó ao primeiro, formando uma lista circular.
-Desfazer circular
Remove a circularidade da lista.
-Verificar se é circular
Informa se a lista está circular ou não.
-Imprimir frente
Mostra os elementos da lista do início para o fim.
-Imprimir reverso
Mostra os elementos da lista do fim para o início.
-Imprimir circular
Imprime n elementos percorrendo a lista circular.
-Liberar lista
Libera toda a memória alocada.
-Sair
Encerra o programa.