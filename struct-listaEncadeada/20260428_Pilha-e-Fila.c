#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int conteudo;
    struct elemento *seg;
}

typedef struct elemento Elem;

typedef struct elemento* Pilha;

struct fila{
    struct elemento *inicio;
    struct elemento *fim;
    int qtd;
}

typedef struct fila Fila;

void print_lista(Lista* lista) {
    if(lista == NULL) {
        printf("Lista não existe\n");
        return;
    }
    if(*lista == NULL) {
        printf("\nLista vazia\n");
        return;
    }
    
    cel *temp;
    temp = *lista;
    printf("\nLista: ");
    do {
        printf(" %d |",temp->conteudo);
        temp = temp->seg; //temp recebe o proximo endereço para avançar no loop
    } while(temp != NULL);
    
    printf("\n");
}

Pilha* criar_pilha(){
    Lista *pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi!=NULL) {
        *pi=NULL;
    }
    return pi;
}

Fila* criar_fila() {
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    if(fi!=NULL) {
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void free_pilha(Pilha* pilha) {
    if(pilha!=NULL) {
        Elem* aux;
        while(*pilha!=NULL) {
            aux = *pilha;
            *pilha = (*pilha) -> seg;
            free(aux);
        }
    free(pilha);
    }
}

void free_fila(Fila* fila) {
    if(fila->inicio!=NULL) {
        Elem* no;
        while(*fila!=NULL) {
            no = fila->seg;
            fila->inicio = fila->inicio->seg;
            free(no);
        }
    free(fila);
    }
}

int insere_lista_inicio(Lista *lista, int x){
    if(lista == NULL) {return 0;}
    cel *aux = (cel*) malloc(sizeof(cel));
    if(aux == NULL) {return 0;}

    aux -> ant = NULL;
    aux -> conteudo = x;
    aux -> seg = *lista;
    *lista = aux;
    return 1;
}

int* mostrar_topo_pilha(Pilha *pilha) {
    if (pilha == NULL) {return -1;}
    if ((*pilha) == NULL) {return -1;}

    return (*pilha)->conteudo;
}

int push_pilha(Pilha *pilha, int x) {
    if (pilha == NULL) {return -1;}
    Elem *aux = (Elem*) malloc(sizeof(Elem));
    if (aux == NULL) {return 0;}
    
    aux -> conteudo = x;
    aux -> seg = (*pilha);
    
    *pilha = aux;
    
    return 1;
}

int pop_pilha(Pilha *pilha) {
    if (pilha == NULL) {return -1;}
    if ((*pilha) == NULL) {return -1;}
    Elem *aux;
    
    aux = *pilha;
    *pilha = (*pilha)->seg;
    
    free(aux);
    
    return 1;
}

int enqueue_fila(Fila *fila, int x) {
    if (fila == NULL) {return -1;}
    Elem no = (Elem*) malloc (sizeof(Elem));
    if(no == NULL) {return 0;}
    //if ((*fila) == NULL) { fila -> fim = no; fila->inicio = no;}
    
    no->conteudo = x;
    no->seg = NULL;
    
    if(fila->inicio == NULL) {
        fila ->inicio = no;
    }
    
    fila -> fim -> seg = no;
    fila -> fim = no;
    fila->qtd++;
    
    return 1;
}

int dequeue_fila(Fila *fila) {
    if (fila == NULL) {return -1;}
    if (fila->inicio == NULL) {return -1;}
    
    Elem *no = fila->inicio;
    
    (*fila)->inicio = (*fila)->inicio->seg;
    
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(no);
    
    fila->qtd--;
    return 1;
}



int main()
{
    //receber os parametros
    //verif se a Lista existe;
    //verif se a Lista esta vazia;
    //criar nó/célula;
    
    //se a lista está vazia, o novo conteudo dela será o endereço do nó;
    
    Pilha *pil;
    pil = criar_pilha();
    
    insere_lista_inicio(lst, 1);
    insere_lista_inicio(lst, 2);
    insere_lista_inicio(lst, 3);
    insere_lista_inicio(lst, 4);
    insere_lista_inicio(lst, 5);
    insere_lista_inicio(lst, 6);

    print_lista(lst);
    
    buscar(lst, 4);
    //printf(countCadeia(lst));
    //printf("\nContador: %d", countCadeia(lst));
    //printf("\nRemoção: %d", remover(lst, 6));
    print_lista(lst);
    
    //printf("\n%d", removerLista(lst));
    
    return 0;
}
