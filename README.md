# Bibliotecas para estrutura de dados
**Bibliotecas de gerenciamento de estrutura de dados em C, desenvolvidas por mim e de livre uso conforme o seu licenciamento.** </br>
**Libraries for data structure management in C, fully developed by me and free to use according to it's license.**
</br>

## Incluso:
  - Gerenciamento de arrays dinamicos.
  - Gerenciamento de filas e pilhas.
  - Gerenciamento por listas encadeadas.
  - Gerenciamento por árvores.
  - Bibliotecas extras e experimentais de diversas utilidades.
</br>

## Navegação do projeto:
O Projeto é dividido por categorias de estruturas de dados, tipo de formato dos arquivos da biblioteca e finalmente as bibliotecas em si.
Isso foi feito para facilitar tanto a organização do desenvolvimento quanto a pesquisa pelo arquivo desejado por parte do usuário: </br>
  - Tipo de estrutura de dados da biblioteca
    - Formato da biblioteca
    <sup></br>(Header only ou traditional)</sup>
      - Bibliotecas
        - Arquivos
        <sup></br>Códigos em si</sup>
        
</br>

**Exemplo de navegação:**
- "Arrays Strutures"
    - "Compact (Monolithic header)"
      - "Fila (queue) - Simplified"
        - "main.c"
        - "queuelib.h"

</br>

Como essas bibliotecas foram desenvolvidas visando tanto a praticidade funcional quanto o aprendizado academico, cada pasta contém uma descrição sobre seus arquivos,
suas funcionalidades e seu uso. Dessa forma o usuário pode não só usar as bibliotecas para facilitar seu código como também pode usá-la para o aprendizado de estrutura de dados.
Todo o projeto de repositório da estrutura de dados é feito para ser prático e user-friendly e estou a disposição para sugestões.</br>

Além dos repositórios principais de estruturas de dados, também há um repositório especial chamado **"cat libs :3"**
que contém bibliotecas experimentais, extras ou especiais que são desenvolvidas e mantidas totalmente por mim.

</br>

> [!TIP]
> Formatos "Traditional", "Modular" e "Formal" se referem a bibliotecas cujos arquivos são separados em um ***header file (.h)*** e um ***source file (.c)*** </br>
> esses arquivos precisam ser compilados manualmente, porém são a forma comum de arquivos de biblioteca e podem ser compilados universalmente. </br> </br>
> Formatos "Compact", "Monolithic header" e "Simplified" se referem a bibliotecas inteiramente salvas em apenas um ***header file (.h)*** </br>
> esse arquivo .h único pode ser importado e compilado automáticamente com o código main.c principal, porém pode gerar erros ao ser compilado manualmente a depender do compilador usado.


## Development roadmap:
- **Vetores**
  - [x] Dynamic Arrays
  - [x] Filas
  - [x] Pilhas

- **Listas encadeadas** (W.I.P.)
  - [x] Simple Linked Lists
  - [ ] Doubly Linked Lists
  - [ ] Circular Linked Lists
  - [ ] Doubly Circular Linked Lists (ouroboros)

- **Arvores** (W.I.P.)
  - [ ] Binary Tree
  - [ ] Recursive Tree

- **Bibliotecas**
  - [x] LinkedList lib **<sup>[1]</sup>**
  - [x] Dynamic Addon
  - [ ] LinkedList addon **<sup>[2]</sup>**
  - [ ] Fractree **<sup>[2]</sup>**

> [!NOTE]
> ### <sup>[1] = In the making, [2] = Work In Progress (W.I.P.), [3] = On rework, [4] = Future work.</sup>
> - Bibliotecas marcadas com "In the making" ainda não tiveram seus arquivos publicados, mas estão sendo feitas por mim. </br>
> - Bibliotecas marcadas com (W.I.P.) estão atualmente sendo trabalhadas por mim e estão incompletas. </br>
> - Bibliotecas marcadas com "On rework" são bibliotecas que foram concluidos, porém apresentam erros e portanto precisam ser retrabalhadas. </br>
> - Bibliotecas marcadas com "Future work" são bibliotecas cujo desenvolvimento ainda não foi iniciado. </br>
