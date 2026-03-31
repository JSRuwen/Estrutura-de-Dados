#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int conteudo;
    struct celula *seg;
} cel;

typedef struct *cel Lista;

Lista* criar_Lista() {
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL) {
        *li == NULL;
    }
    return li;
}

int main()
{
    printf("Hello World");
    
    Lista *lst;
    lst = criar_Lista();
    
    cel c1, c2, c3;
    // Jeito não ortodoxo
    c1.conteudo = 10;
    c2.conteudo = 20;
    c3.conteudo = 30;
    
    
    // Jeito não ortodoxo pt.2
    c1.seg = &c2;
    c2.seg = &c3;
    c3.seg = NULL;
    
    *lst = &c1;

    cel* aux = *lst;
    
    printf("Minha lista:\n");
    
    
    while(aux != NULL){
        printf("\t%d", aux->conteudo);
        aux = aux->seg;
    }
    
    return 0;
}
