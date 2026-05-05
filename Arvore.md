# Árvore
- Pai
  - Antecessor imediato de um vértice
- Filhos
  - Sucessor imediato de um vértice
- **Raiz**
  - É o vértice que não possui pai
- Nós terminais ou folhas
  - É o que não possui filhos
- Nós Não-terminais ou Internos
  - Qualquer vértice que possui pelo menos 1 filho

## Árvore Binária
- uma arvore em que cada nó tem 0, 1 ou 2 filhos
- uma arvore binária é:
  - uma arvore vazia, ou;
  - um no raiz 

---

- Uma árvore **completa** é considerado quando todo elemento nó não-terminal possui nenhum ou 2 filhos.

- Uma árvore é **cheia**, se é *completa* e todas as folhas estão no mesmo nível 
  - e uma árvore é **quase cheia** se está até o penúltimo nivel e todas as folhas do seguinte nível

### Propriedades
- Altura(h): A maior distância percorrida por um nó, até a raíz
  - a altura de um nó depende da distância percorrida de sua herança nó folha
- Nível: distância percorrida a partir da raíz
- Peso: quantidade de elementos na árvore.
- Grau: quantos elementos um nó suporta

### Tipos
Iguais
  - Quando ambas árvores estão vazias ou com mesma estrutura e elementos

Isomórficas:
  - Quando as árvores possuem a mesma estrutura representada, porém com elementos diferentes em seus nós

Semelhantes:
  - Quando as árvores possuem os mesmos elementos, com estrutura diferente

### Percurso na árvore
- **Pré-ordem**:
  Ordem de visitação: Raíz -> Filho esquerdo -> Filho direito

  - exemplo: (A(B(D,E(F,G)),C))
  
    0. inicia nó no A
    1. print A, go to B
    2. print B, go to D
    3. print D, go to E
    4. print E, go to F
    5. print F, go to G

- **Em-ordem**:
  Ordem de visitação: Filho esquerdo -> Raíz -> Filho direito

  - exemplo: (A(B(D,E(F,G)),C))
  
    0. inicia nó no A
    1. go to B
    2. go to D
    3. print D, go to B
    4. print B, go to E
