## Filas:
Filas são estruturas de dados que seguem o princípio **First In, First Out (FIFO)**, ou seja, o primeiro elemento a ser inserido é o primeiro a ser removido. Essa estrutura é similar a uma fila de pessoas em um banco ou loja: a pessoa que chega primeiro é a primeira a ser atendida.

### Características principais:

- **Operações principais**:
  - **enqueue**: Adiciona um elemento ao final da fila.
  - **dequeue**: Remove e retorna o elemento do início da fila.
  - **front** ou **peek**: Retorna o elemento na frente da fila sem removê-lo.
  - **isEmpty**: Verifica se a fila está vazia.

- **Estrutura**: Filas podem ser facilmente implementadas usando arrays, permitindo a manipulação de dados de maneira eficiente. Porém também vale resaltar que é possivel criar estrutura de filas usando listas encadeadas e dessa forma podemos inclusive criar uma fila circular.

### Vantagens:

- **Simplicidade**: As operações de adição e remoção são diretas e intuitivas, facilitando a implementação.
- **Eficiência**: As operações de adição e remoção são realizadas em tempo constante \(O(1)\), tornando as filas rápidas para gerenciar dados em ordem.

### Desvantagens:

- **Sem acesso aleatório**: As filas não permitem acesso direto a elementos que não estão na frente ou no final.

### Aplicações:
Devido à sua simplicidade e eficiência em gerenciar dados em ordem, as filas são uma estrutura de dados fundamental em computação, sendo amplamente utilizadas em diversas aplicações, incluindo:

- **Gerenciamento de tarefas**: Em sistemas operacionais, onde processos são organizados em filas de pronto, esperando para serem executados.
- **Impressão de documentos**: Os trabalhos de impressão são organizados em uma fila, sendo impressos na ordem em que foram enviados.
- **Simulações**: Usadas em simulações de eventos, como filas em caixas de supermercado ou filas em atendimentos de serviços.
