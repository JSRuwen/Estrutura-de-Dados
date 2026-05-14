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

int inserir(Arvore *tree, int x){ //Versão Funcional desenvolvida por mim
  if(tree == NULL) {return 0;}
  no *aux = (no*) malloc(sizeof(no));
  no *temp;
  if(aux == NULL) {return 0;}
  
  
  aux -> conteudo = x;
  aux->esq = NULL;
  aux->dir = NULL;  
  if(*tree == NULL) {
      tree = aux;
      return 1;
    }
  
  temp = *tree;
  
  while(temp!=NULL) {
    if(temp->conteudo == x) {
      free(aux);
      return 0;
    }
    
    if(temp->esq == NULL && x < temp->conteudo) {
      temp->esq = aux;
      return 1;
    }
    if(temp->dir == NULL && x > temp->conteudo) {
      temp->dir = aux;
      return 1;
    }
    
    if (x < temp->conteudo) {
      temp = temp->esq;
    }
    else {
      temp = temp->dir;        
    }
  }
 
return 1;
}

int inserir_vProfessor(Arvore *tree, int x) {
  if(tree == NULL) {return 0;}
  no *aux = (no*) malloc(sizeof(no));
  if(aux == NULL) {return 0;}
  
  
  aux -> conteudo = x;
  aux->esq = NULL;
  aux->dir = NULL;  
  if(*tree == NULL) {
      tree = aux;
  } else {
    NO *atual = *tree;
    NO *ant = NULL;
    while(atual!=NULL) {
      ant = atual;
      if(atual->conteudo == x) {
      free(aux);
      return 0;
      }
      if(x > atual->conteudo) {
        atual = atual->dir;
      } else {
        atual = atual->esq;
      }
    }

    if(x > ant->conteudo) {
      ant->dir = aux;
    } else {
      ant->esq = aux;
    }
    
  return 1;
}

int buscar(Arvore *tree, int valor) {
    if(tree == NULL) {return 0;}
    no *aux = *tree;
    if(aux == NULL) {return 0;}

    do {
      if(aux->conteudo == valor) {return 1;}
      if (valor > aux->conteudo) {aux = aux->dir;
      } else {aux = aux->esq;}
    } while(aux != NULL);
    return 0;
}

int totalNos(Arvore *tree) {
  if(tree == NULL) {return 0;}
  if(*tree == NULL) {return 0;} else {
    Arvore *aux = tree;

    int no_esq;
    int no_dir;
  
    no_esq = totalNos(&((*aux)->esq));
    no_dir = totalNos(&((*aux)->dir));
  }
  return no_esq+no_dir+1;
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
