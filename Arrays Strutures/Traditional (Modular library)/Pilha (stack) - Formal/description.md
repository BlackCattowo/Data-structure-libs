## Pilhas:
Pilhas são estruturas de dados que seguem o princípio **Last In, First Out (LIFO)**, ou seja, o último elemento a ser inserido é o primeiro a ser removido. Essa estrutura é frequentemente comparada a uma pilha de pratos: você adiciona e remove pratos apenas do topo.

### Características principais:

- **Operações principais**:
  - **push**: Adiciona um elemento ao topo da pilha.
  - **pop**: Remove e retorna o elemento do topo da pilha.
  - **top** ou **peek**: Retorna o elemento do topo da pilha sem removê-lo.
  - **isEmpty**: Verifica se a pilha está vazia.

- **Estrutura**: Pilhas podem ser facilmente implementadas usando arrays, permitindo a manipulação de dados de maneira eficiente. Porém também vale resaltar que é possivel criar estrutura de pilhas usando listas encadeadas.

### Vantagens:

- **Simplicidade**: A estrutura é fácil de entender e implementar, com um número limitado de operações.
- **Eficiência**: As operações de adição e remoção são realizadas em tempo constante \(O(1)\), tornando as pilhas rápidas para o gerenciamento de dados.

### Desvantagens:

- **Sem acesso aleatório**: Ao contrário de outras estruturas de dados, como arrays tradicionais, as pilhas não permitem acesso direto a elementos que não estão no topo.

### Aplicações:

Pilhas são amplamente utilizadas em diversas aplicações, incluindo:

- **Algoritmos de retrocesso**: Como na navegação em histórico de páginas ou em editores de texto (funções "desfazer" e "refazer").
- **Avaliação de expressões**: Usadas em algoritmos de conversão de notação infixa para pós-fixa e na avaliação de expressões matemáticas.
- **Gerenciamento de chamadas de funções**: O sistema operacional utiliza pilhas para gerenciar chamadas de função e retornos, armazenando informações sobre o estado da execução.

Devido à sua simplicidade e eficiência, as pilhas são uma estrutura de dados fundamental em computação.