#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int conteudo;
  no *esq;
  no *dir;
} no

typedef struct no* Arvore;

/* FUNÇÕES ************************************************************/

/** IMPRESSÃO *********************************************************/
// Função auxiliar recursiva 
void imprime_NO(struct NO *no, const char *prefixo, int ehUltimo, char lado){
  if(no == NULL){ return;}
  printf("%s", prefixo);
  if(ehUltimo){printf("└── ");
  } else {printf("├── ");}
  if(lado == 'E'){printf("E: ");
  } else if(lado == 'D'){printf("D: ");}
  printf("%d\n", no->info);
  char novoPrefixo[1000];
  snprintf(novoPrefixo,sizeof(novoPrefixo),"%s%s",prefixo,ehUltimo ? "    " : "│   ");
  if(no->esq != NULL){
    imprime_NO(no->esq, novoPrefixo, no->dir == NULL, 'E');
  }
  if(no->dir != NULL){
    imprime_NO(no->dir, novoPrefixo, 1, 'D');
  }
}
// Função principal de impressão
void imprime_ArvBin(ArvBin *raiz){
  if(raiz == NULL || *raiz == NULL){
    printf("Árvore vazia.\n");
    return;
  }
  printf("%d\n", (*raiz)->info);
  if((*raiz)->esq != NULL){
    imprime_NO((*raiz)->esq, "", (*raiz)->dir == NULL, 'E');
  }
  if((*raiz)->dir != NULL){
    imprime_NO((*raiz)->dir, "", 1, 'D');
  }
}

/** CRIAR ÁRVORE *********************************************************/
Arvore* criar_arvore(){
    Arvore *tree = (Arvore*) malloc(sizeof(Arvore));
    if(tree!=NULL) {
        *tree=NULL;
    }
    return tree;
}

/** INSERIR NÓ *********************************************************/
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

// Código feito pelo professor
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

/** BUSCAR NÓ *********************************************************/
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

/** TOTAL DE NÓS *********************************************************/
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

/** ALTURA DA ÁRVORE *********************************************************/
int altura_arvore(Arvore *tree) {
  if(tree == NULL) {return -1;}
  if(*tree == NULL) {return -1;}
  
  int h_esq = altura_arvore(&((*tree)->esq));
  int h_dir = altura_arvore(&((*tree)->dir));

  if(h_esq>h_dir) {
    return(h_esq+1);
  } else {
    return(h_dir+1);
  }

  return 1;
}

/** ORDEM EM ARVORE *********************************************************/
void preOrdem_arvore(Arvore *tree) {
  if(tree == NULL) {return;}
  if(*tree !=NULL) {
    printf("%d\t", (*tree)->conteudo);
    preOrdem_arvore(&((*tree)->esq));
    preOrdem_arvore(&((*tree)->dir));
}

void emOrdem_arvore(Arvore *tree) {
  if(tree == NULL) {return;}
  if(*tree !=NULL) {
    emOrdem_arvore(&((*tree)->esq));
    printf("%d\t", (*tree)->conteudo);
    emOrdem_arvore(&((*tree)->dir));
}

void posOrdem_arvore(Arvore *tree) {
  if(tree == NULL) {return;}
  if(*tree !=NULL) {
    posOrdem_arvore(&((*tree)->esq));
    posOrdem_arvore(&((*tree)->dir));
    printf("%d\t", (*tree)->conteudo);
}


/** REMOÇÃO *************************************************************/
no* remove_atual(no *atual) {
  no *no1, *no2;

  if(atual->esq == NULL) {
    no2 = atual->dir;
    free(atual);
    return no2;
  }

  no1 = atual;
  no2 = atual->esq;

  while (no2->dir != NULL) {
    no1 = no2;
    no2 = no2->dir;
  }

  if(no1 != atual) {
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  } 
  
  no2->dir = atual->dir;
  free(atual);
  
  return no2;
}

int remover_ArvBin(Arvore *tree, int x) {
    if(tree == NULL) {return 0;}
    if(*tree == NULL) {return 0;}
    no *atual = NULL;
    no *ant = *tree;

    while(atual!=NULL) {
      if(valor == atual->conteudo) {
          if(atual == *tree) {
            *raiz = remove_atual(atual);
          } else {
            if(ant->dir == atual) {
              ant->dir = remove_atual(atual);
            } else {
              ant->esq = remove_atual(atual);
            }
      }
    }
      // andar na arvore
      ant = atual;
      if(x > atual->conteudo) {
        atual = atual->dir;
      } else {
        atual = atual->esq;
      }
  }
  return 0;
}

// no_esq, ant = remover_ArvBin($((*tree)->esq), x);
// no_dir, ant =

int main() {
  
  return 0;
}
