## Árvores:
Estruturas de árvores são uma forma de organizar dados em hierarquias, permitindo uma representação eficiente de relações parentais e acesso rápido a elementos. Cada árvore é composta por **nós**, onde cada nó contém um valor (ou dados) e referências (ou ponteiros) a seus **filhos**. O primeiro nó da árvore é chamado de **raiz**, e os nós que não têm filhos são chamados de **folhas**.

### Características principais:

- **Hierarquia**: As árvores têm uma estrutura hierárquica, onde cada nó pode ter zero ou mais nós filhos.
- **Níveis**: Os nós são organizados em níveis, começando pela raiz no nível 0 e aumentando à medida que se desce na árvore.
- **Subárvores**: Cada nó pode ser considerado a raiz de uma subárvore, que é a parte da árvore composta pelos nós descendentes desse nó.
- **Caminhos**: A sequência de nós que conecta um nó à raiz é chamada de caminho.

### Tipos Comuns de Árvores:

- **Árvore Binária**: Cada nó tem no máximo dois filhos, frequentemente referidos como filho esquerdo e filho direito.
- **Árvore de Busca Binária**: Uma árvore binária onde todos os nós à esquerda de um nó têm valores menores, e todos os nós à direita têm valores maiores.
- **Árvore AVL**: Uma árvore de busca binária que se mantém balanceada, garantindo que as operações de inserção, exclusão e busca sejam realizadas em tempo logarítmico.
- **Árvore B**: Uma árvore balanceada que mantém dados ordenados e permite buscas, inserções e exclusões eficientes, ideal para sistemas de gerenciamento de banco de dados.
- **Árvores N-árias**: Cada nó pode ter até N filhos.

### Aplicações:

Estruturas de árvores são amplamente utilizadas em algoritmos de busca, organização de dados, sistemas de arquivos, bancos de dados e na implementação de diversas estruturas de dados, como heaps e tries, devido à sua capacidade de organizar informações de maneira eficiente.
