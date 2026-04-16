#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *seg;
    struct cel *ant;
}cel;

typedef struct cel* ListaDup;

/** FUNÇÕES ************************************************************/
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

int insere_lista_fim(Lista *lista, int x){
    if(lista == NULL) {return 0;}
    cel *aux = (cel*) malloc(sizeof(cel));
    if(aux == NULL) {return 0;}
    aux -> conteudo = x;
    aux -> seg = NULL;
    aux -> ant = NULL;
    if((*lista) == NULL) {
        *lista = aux; 
    } else {
            cel *temp;
            temp = *lista;
            
            while(temp->seg !=NULL) {//anda até o ultimo elemento;
                temp = temp->seg;
            }
            temp->seg = aux;
            aux->ant = temp;
        }
        return 1;
}

int buscar(Lista *lista, int valor) {
    if(lista == NULL) {return 0;}
    cel *aux = *lista;
    if(aux == NULL) {return 0;}

    do {
        if (aux->conteudo == valor) {
            printf("OK %d",valor);
            return 1;
        }
        if (aux->conteudo != valor) {
            aux = aux->seg;
        }
    } while(aux->seg != NULL);
    free(aux);
    return 0;
}

int buscaProfessorV1(Lista *lista, int valor) {
    if(lista == NULL) {return 0;}
    if(*lista == NULL) {return 0;}
    cel *aux = *lista;
    
    do {
        if (aux->conteudo == valor) {
            return 1;
        }
        if (aux->conteudo != valor) {
            aux = aux->seg;
        }
    } while(aux->seg != NULL);
    free(aux);
    return 0;
}

int busca_for(Lista *lista, int valor) {
    if(lista == NULL) {return 0;}
    if(*lista == NULL) {return 0;}
    cel *aux;
    
    for(aux = *lista; aux!=NULL; aux = aux->seg) {
        if (aux->conteudo == valor) {
            return 1;
        }
    }
    free(aux);
    return 0;
}

int countCadeia(Lista *lista) {
    if(lista == NULL) {return 0;}
    if(*lista == NULL) {return 0;}
    cel *aux;
    int count = 0;
    for(aux = *lista; aux!=NULL; aux = aux->seg) {
        count++; 
    }
    //printf(count);
    return count;
}

int remover(Lista *lista, int x) {
    if(lista == NULL) {return 0;}
    if(*lista == NULL) {return 0;}
    cel *aux;
    
    for(aux = *lista; aux!=NULL; aux = aux->seg) {
        if(aux->conteudo == x) {
            if (aux == *lista) {
                *lista = (*lista)->seg;
                free(aux);
                return 1;
            }
            aux->ant = aux->seg;
            free(aux);
            return 1;
        }
    }
    free(aux);
    return 0;
}

int removerLista(Lista *lista) {
    if (lista == NULL) {return 0;}
    if (*lista == NULL) {return 0;}
    cel *aux;
    while(*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->seg;
        free(aux);
        print_lista(lista);
    }
    free(lista);
    return 1;
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
    printf("\nContador: %d", countCadeia(lst));
    printf("\nRemoção: %d", remover(lst, 6));
    print_lista(lst);
    
    printf("\n%d", removerLista(lst));
    
    return 0;
}
