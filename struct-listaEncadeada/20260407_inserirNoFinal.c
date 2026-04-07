#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *seg;
}cel;

typedef struct cel* Lista;

//func
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
    } while(temp->seg != NULL);
    
    printf("\n");
}

Lista* criar_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li!=NULL) {
        *li=NULL;
    }
    return li;
}

int insere_lista_fim(Lista *lista, int x){
    if(lista == NULL) {
        return 0;
    } else {
        cel *aux = (cel*) malloc(sizeof(cel));
        if(aux != NULL) {return 0;}
        aux -> conteudo = x;
        aux -> seg = NULL;
        if(*lista == NULL) {*lista = aux;} 
        else {
            cel *tmp;
            tmp = *lista;
            
            while(tmp->seg !=NULL) {//anda até o ultimo elemento;
                tmp = tmp->seg;
            }
            tmp->seg = aux;
        }
        return 1;
    }
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
    
    insere_lista_fim(lst, 1);
    insere_lista_fim(lst, 2);
    insere_lista_fim(lst, 3);
    insere_lista_fim(lst, 4);
    insere_lista_fim(lst, 5);
    insere_lista_fim(lst, 6);

    print_lista(lst);

    return 0;
}
