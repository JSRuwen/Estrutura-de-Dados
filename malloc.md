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

# Resolução
```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void imprimirV(int *v, int n) {
    printf("Vetor %p:",v);
    for(int i; i<n; i++) {
        printf(" %d |",v[i]);
    }
    printf("\n");
}

void mergeSort(int *v, int inicio,int fim) {
    int meio;
    if(inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v,inicio,meio);
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }
}

void merge(int *v,int inicio, int meio, int fim) {
    int *temp, i, j, k, n, p1, p2, fim1=0, fim2=0;
    n = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int) malloc(n * sizeof(int));
    if(temp != NULL) {
        for(i = 0; i<n; i++){
            if(!fim1 && !fim2) {//se nenhum chegou ao fim
                if(v[p1]<v[p2]) {
                    temp[i] = v[p1++];
                    
                }
                else {
                    temp[i] = v[p2++];
                }
            } else{//se um dos vetores chegou ao fim 
                if(!fim1){temp[i] = v[p1++];}
                else{temp[i] = v[p2++];}
            }
        }
        for(j=0, k=inicio; j<n; j++, k++) {
        v[k] = temp[j];
        }
    }
   free(temp); 
}


int main()
{
    int v[9] = {0,2,5,8,1,6,9,7,3};
    imprimirV(v, 9);
    mergeSort(v, 0, 8);
    return 0;
}
```
