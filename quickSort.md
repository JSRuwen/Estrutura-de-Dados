# Quick Sort
```c
#include <stdio.h>

void quickSort(int *v, int inicio, int fim) {
    int pivo;
    if(fim > inicio) {
        pivo = particiona(v, inicio, fim); //separa os dados em 2 partições
        
        quickSort(v, inicio, fim);//Chama a função para as 2 metades
        quickSort(v, pivo+1,fim);//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    }
}

private int particiona(int *v, int inicio, int fim) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while(esq<dir){
        //avança a posição da esquerda
        while(esq<=final && v[esq] <= pivo){
            esq++;
        }
        
        //recua posição da direita
        while(dir>=0 && v[dir] > pivo) {
            dir--;
        }
        
        //Trocar esq e dir
        if(esq <dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

int main()
{
    printf("Hello World");

    return 0;
}
```
