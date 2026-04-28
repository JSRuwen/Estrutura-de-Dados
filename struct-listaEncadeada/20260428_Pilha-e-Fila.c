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

Lista* criar_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li!=NULL) {
        *li=NULL;
    }
    return li;
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

Elem* mostrar_topo_pilha(Pilha *pilha) {
    if (pilha == NULL) {return NULL;}
    if (*pilha == NULL) {return NULL;}

    return *pilha;
}

Elem* push_pilha(Pilha *pilha, int x) {
    if (pilha == NULL) {return NULL;}
    if (*pilha == NULL) {return NULL;}
    Elem *aux;
    
    aux -> conteudo = x;
    aux -> seg = *lista;
    
    *pilha = aux;
    
    return pilha;
}

Elem* pop_pilha(Pilha *pilha) {
    if (pilha == NULL) {return NULL;}
    if (*pilha == NULL) {return NULL;}
    Elem *aux;
    
    aux = *pilha;
    *pilha = pilha->seg;
    
    return aux;
}





int main()
{
    //receber os parametros
    //verif se a Lista existe;
    //verif se a Lista esta vazia;
    //criar nó/célula;
    
    //se a lista está vazia, o novo conteudo dela será o endereço do nó;
    
    Lista *lst;
    lst = criar_lista();
    
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
