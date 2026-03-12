/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
//char alfabeto = {'a','b','c','d','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//char nomes = {"Gustavus","Dalston","Niko","Emile","Marieann","Wald","Lynsey","Ferdinand","Yolane","Monah","Cyrillus","Cherilyn","Robert","Robbyn","Stillmann","Rozanne","Bordie","Elissa","Kele","Rozanne"};

int ordenacao(char *p) {
    
}




void selectionSort(int *p, int n) {
    int menor;
    
    for( int i = 0; i < n; i++) {
        menor = i;
    
        for(int x = i + 1; x < n; x++) {
            
            
            if( p[x] < p[menor]) {
                int temp = p[menor];
                p[menor] = p[x];
                p[x] = temp;
            }
        }
    }
    
    for (int i =0; i < n; i++) {
        printf("%d ",p[i]);
    }
}

void bubbleSort(int *v, int n) {
    int swap;
    
    for(int i = 0; i < n; i++) {
        swap = 0;
        
        for(int j = 1; j < n - i; j++) {
            if(v[j] < v[i + 1]) {
                int temp = v[j];
                v[j] = v[i + 1];
                v[i + 1] = temp;
                swap = 1;
            }
            
        }
        
        if (swap == 0) {
            break;
        }
    }
    for (int i =0; i < n; i++) {
        printf("%d ",v[i]);
    }
}

void bubSort_Professor( int *v, int n) {
    //Versão do professor
    int i, aux, swap;
    
    do {
        swap = 0;
        
        for(i = 0; i <n-1-i;i++) {
            if(v[i] < v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                swap = 1;
            }
        }
        
    } while(swap);
}

void insertionSort(int *v, int n) {
    for (int i = 1; i < n; i++) {
        
        
        if(v[i] < v[i - 1]) {
            for(int x = i; x > 0; x--) {
                if(v[i] > v[x]) {
                        int temp = v[i];
                        v[i] = v[x];
                        v[x] = temp;
                }
            }
        }
    }
    for (int i =0; i < n; i++) {
        printf("%d ",v[i]);
    }
}

void insSort_Professor(int *v, int n) {
    //Versão do professor
    int i, j, aux;
    
    for(i =0; i <n; i++) {
        aux = v[i];
        for(int j = 0; (j>0) && (aux < v[j - 1]);j--) {
            v[j] = v[j - 1];
        }
        v[j] = aux;
    }
}


int main()
{
    int numeros[7] = {7,4,6,9,8,2,1};
    printf("v Array Original > ");
    for(int i = 0; i < 7; i++) {
        printf("%d ",numeros[i]);
    }
    
    printf("\n| selection Sort > ");
    selectionSort(numeros, 7);
    
    printf("\n| bubble sort    > ");
    bubbleSort(numeros,7);
    
    printf("\n| insertion sort > ");
    insertionSort(numeros,7);
    return 0;
}
