#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int conteudo;
  no *esq;
  no *dir;
} no

typedef struct no* Arvore;

/** FUNÇÕES ************************************************************/
Arvore* criar_arvore(){
    Arvore *tree = (Arvore*) malloc(sizeof(Arvore));
    if(tree!=NULL) {
        *tree=NULL;
    }
    return tree;
}

int inserir(Arvore *tree, int x){
    if(tree == NULL) {return 0;}
    no *aux = (no*) malloc(sizeof(no));
    no *temp;
    if(aux == NULL) {return 0;}
    if(*tree == NULL) {
      aux->conteudo = x;
      aux->esq = NULL;
      aux->dir = NULL;
      tree = aux;
      return 1;
    }
  
    temp = *tree;
    aux -> conteudo = x;
    aux->esq = NULL;
    aux->dir = NULL;
  
  while(temp!=NULL) {
    if(temp->conteudo == aux->conteudo) {return 0;}
    if(temp->esq == NULL && temp->conteudo > aux->conteudo) {
    if (temp->conteudo > aux->conteudo) {
      temp = temp->esq;
    }
    else if (temp->conteudo < aux->conteudo) {
      temp = temp->dir;        
    }
  }

  if(temp->conteudo > aux->conteudo) {
      temp->esq = aux;
  }
  
  if(temp->conteudo < aux->conteudo) {
      temp->dir = aux;
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

int main() {
  
  return 0;
}
