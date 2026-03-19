# Malloc
- Serve para alocar um tamanho de ponteiro
- **OBS:** após alocar, o ponteiro `GANHA um endereço`, `MAS continua nulo`.
```c
int *p;
p=(int *) malloc(50*sizeof(int));

printf(p); //printa o endereço
```

# MergeSort
- Divdir para conquistar para ordenar os dados
- Divide, recursivamente, o array em duas partes
- Continua ate cada parte ter apenas um elemento
