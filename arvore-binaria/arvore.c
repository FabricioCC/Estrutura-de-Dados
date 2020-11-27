#ifndef ARVORE_C
#define ARVORE_C

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvno {
    int info;
    ArvNo* esq;
    ArvNo* dir;
};


struct arv {
    ArvNo* raiz;
};

//criar nó
ArvNo* arv_criano (int c, ArvNo* esq , ArvNo* dir){
    ArvNo* p = (ArvNo*) malloc(sizeof (ArvNo ));
    p-> info = c;
    p-> esq = esq;
    p-> dir = dir;
    return p;
}

//cria arvore
Arv* arv_cria (){

    Arv* a = (Arv*) malloc(sizeof (Arv));
    a-> raiz = NULL;
    return a;

}


static void imprime (ArvNo* r){


    printf("<");

    if (r != NULL ){
        imprime(r-> esq); 
        printf("%d", r-> info); 
        imprime(r-> dir); 

    }

    printf(">");
}

void arv_imprime (Arv* a){
    imprime(a-> raiz); 
}

static void libera (ArvNo* r){

    if (r != NULL) {
        libera(r-> esq); 

        libera(r-> dir);

        free(r); 
    }

}

void arv_libera (Arv* a){

    libera(a-> raiz); 
    free(a); 

}

static int pertence (ArvNo* r, char c){

    if (r == NULL)
        return 0; 
    else
        return c==r-> info ||pertence(r->esq ,c) || pertence(r->dir,c);

}

int arv_pertence (Arv* a, int c){

    return pertence(a->raiz ,c);

}


static ArvNo* busca (ArvNo* r, int v){

    if (r == NULL){
        return NULL;
    }else if (r-> info > v){
        return busca (r->esq , v);
    }else if (r-> info < v){
        return busca (r->dir, v);
    }else{
        return r;
    } 

}

ArvNo* abb_busca (Arv* a, int v){
    return busca(a->raiz ,v);   
}



static ArvNo* insere (ArvNo* r, int v){

    if (r== NULL) {
    
        r = (ArvNo*) malloc(sizeof (ArvNo ));
        r-> info = v;
        r-> esq = r-> dir = NULL;
    
    }else if (v < r-> info){
        r-> esq = insere(r->esq ,v);
    }else{
        r-> dir = insere(r->dir,v);
    }
    
   
    
    return r;

}

void abb_insere (Arv* a, int v){
    a-> raiz = insere(a->raiz ,v);
}


static ArvNo* retira (ArvNo* r, int v){

    if (r == NULL){ 
        return NULL;
    }else if (r-> info > v){
        r-> esq = retira(r->esq , v);
    }else if (r-> info < v){
        r-> dir = retira(r->dir, v);
    }else{ //∗ achou o e le me nto ∗/

        //e le me nto sem f i l h o s
        
        if (r-> esq == NULL && r-> dir == NULL) {
        
            free (r);
            
            r = NULL;
            
        
        }else if (r-> esq == NULL) {//só tem f i l h o à d i r e i t a ∗/
        
            ArvNo* t = r;
            
            r = r-> dir;
            
            free (t);
        
        }else if (r-> dir == NULL) {//∗ só tem f i l h o à e s q u e rd a ∗/
        
            ArvNo* t = r;
            r = r-> esq;
            free (t);
            
        }else {//∗ tem os d o i s f i l h o s ∗/
        
            ArvNo* f = r-> esq;
            
            while (f-> dir != NULL) {
            
                f = f-> dir;
            
            }
            
            r-> info = f-> info; 
            
            f-> info = v;
            
            r-> esq = retira(r->esq ,v);
            
        }
        
    }

    return r;

}

void abb_retira (Arv* a, int v){
    a-> raiz = retira(a->raiz ,v);
}


//funcao recursiva para verificar a quantidade de pares;
int ehPar(ArvNo* a){
    if(a!=NULL){
        if(a->info%2==0){
            return 1 + ehPar(a->esq) + ehPar(a->dir); 
        }else{
            return 0 + ehPar(a->esq) + ehPar(a->dir);
        }
        
    }else{
        return 0;
    }
    
}

//questao 1
int pares (Arv* a){
    return ehPar(a->raiz);; 
}

//questao 2
int qtFolhas(ArvNo* no){
    if(no!=NULL){
        if(no->esq == NULL && no->dir == NULL){
            return 1;
        }else{
            return 0 + qtFolhas(no->esq) + qtFolhas(no->dir);
        }        
    }else{
        return 0;
    }
}
int folhas (Arv* a){
    return qtFolhas(a->raiz);    
}

//questao3 
int qtUmFilho(ArvNo* no){
    if(no){
        if((no->esq == NULL && no->dir != NULL) || (no->esq != NULL && no->dir == NULL)){
            return 1+ qtUmFilho(no->esq) + qtUmFilho(no->dir);
        }else{
            return 0 + qtUmFilho(no->esq) + qtUmFilho(no->dir);
        }   
    }else{
        return 0;
    }
}

int um_filho (Arv* a){
    return qtUmFilho(a->raiz);
}

//questao6
int eh_maior(ArvNo* no, int x){
    if(no){
        if(no->info>x){
            return 1 + eh_maior(no->esq, x) + eh_maior(no->dir,x);
        }else{
            return 0 + eh_maior(no->esq, x) + eh_maior(no->dir,x);
        }
    }
        
}

int nfolhas_maiores (Arv*a, int x){
    int nfolhas = 0;
    nfolhas = eh_maior(a->raiz, x);
    return nfolhas;
    
}

//questao 7
int soma(ArvNo* no, int x, int y){
    if(no){
        if(no->info>y && no->info<x){
            return no->info + soma(no->esq, x, y) + soma(no->dir, x, y);
        }else{
            return 0 +  soma(no->esq, x, y) + soma(no->dir, x, y);
        }
    }else{
        return 0;
    }
}

int soma_xy (Arv*a, int x, int y){
    int somaxy = 0;
    somaxy = soma(a->raiz, x, y);
    return somaxy;
}

//questao 8
int nivelNo(ArvNo* no, int x){
    if(no){
        if(no->info < x){
            return 1 + nivelNo(no->esq, x) + nivelNo(no->dir,x);
        }else if(no->info == x){
            return 1;
        }else{
            return 0 + nivelNo(no->esq, x) + nivelNo(no->dir,x);
        }
        
    }else{
        return 0;
    }
}

int nivel (Arv* a, int x){
    int nivel = 0;
    nivel = nivelNo(a->raiz, x) - 1;
    return nivel;
}

#endif
