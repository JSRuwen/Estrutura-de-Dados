# Lista Encadeada
- tipo de "lista" onde cada elemento aponta para um sucessor da "lista"
- Usa um ponteiro especial para o primeiro elemento da lista e uma indicação de final de lista

---

## Vantagens
- Melhor utilização dos recursos de memórias
- Não precisa de movimentar os elementos nas operações de inserção e remoção

## Desvantagem
- Acesso indireto aos elementos
- Necessidade de percorrer a lista para acessar um elemento

---

```
1         32             73              55
      [ 1 | 73] ---> [ 3 | 55 ] ---> [ 4 | null ] ---#

2         32             73              55
      [ 1 | 73] ---> [ 3 | 55 ] ---> [ 4 | null ] ---#
            ^       /
            11     /  
        [ 2 | null ]
```



## Quando utilizar?
- Não há necessidade de garantir um espaço mínimo para execução do aplicativo
- Inserção/Remoção em lisas de forma ordenadas são as operações mais frequentes


--


# Lista Duplamente Encadeada
- tipo de "lista" onde cada elemento aponta para um sucessor da "lista" e para um antecessor
- Códigos de exemplo [aqui](https://github.com/JSRuwen/Estrutura-de-Dados/blob/main/struct-listaEncadeada/20260416_lista-duplamente-encadeada.c)
# Lista Encadeada com Cabeça
- 

# Lista Encadeada Circular
