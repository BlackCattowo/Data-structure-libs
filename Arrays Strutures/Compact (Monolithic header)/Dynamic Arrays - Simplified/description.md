## Arrays dinâmicos:
Arrays dinâmicos são estruturas de dados que permitem a alocação de memória de forma flexível durante a execução de um programa. Diferente dos arrays estáticos, que têm um tamanho fixo definido em tempo de compilação, os arrays dinâmicos podem crescer ou encolher conforme necessário, oferecendo maior adaptabilidade ao armazenamento de dados.

### Características principais:

- **Alocação dinâmica**: A memória para um array dinâmico é alocada em tempo de execução, utilizando funções específicas como `malloc` ou `calloc` em C.
- **Redimensionamento**: Quando um array dinâmico precisa ser ampliado, uma nova área de memória pode ser alocada, e os dados existentes podem ser copiados para essa nova área. Isso é frequentemente feito usando funções como `realloc`.
- **Acesso aleatório**: Assim como arrays estáticos, arrays dinâmicos permitem acesso direto aos elementos através de índices, proporcionando eficiência em operações de leitura e escrita.

### Vantagens:

- **Flexibilidade**: Permitem a manipulação de conjuntos de dados de tamanho variável, ideal para aplicações onde o número de elementos não é conhecido previamente.
- **Eficiência**: O acesso a elementos é rápido, uma vez que a estrutura mantém a característica de acesso direto.

### Desvantagens:

- **Custo de gerenciamento de memória**: A alocação e liberação dinâmica de memória podem introduzir sobrecarga e a necessidade de gerenciamento cuidadoso para evitar vazamentos de memória.
- **Fragmentação**: Frequentemente, a memória pode se fragmentar, especialmente em sistemas de longa execução, o que pode afetar o desempenho.

### Aplicações:
Arrays dinâmicos são amplamente utilizados em algoritmos e estruturas de dados que requerem flexibilidade, como listas, filas e pilhas, além de serem uma escolha comum em linguagens de programação que não oferecem suporte nativo para coleções dinâmicas.