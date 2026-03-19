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

## Tentativa 1
```c
#include <stdio.h>
#include <math.h>

void mergeSort(int *V, int inicio,int fim) {
    int meio;
    if(inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V,inicio,meio);
        mergeSort(V,meio+1,fim);
        merge(V,inicio,meio,fim);
    }
}

void merge(int *V,int inicio, int meio, int fim) {
    int aux, i;
    for(i = 0; i <fim; i++) {
        V[i];
    }
}

int main()
{
    printf("Hello World");

    int v[9] = {0,2,5,8,1,6,9,7,3};
    mergeSort(v, 0, 8);
    return 0;
}
```
