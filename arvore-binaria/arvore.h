#ifndef ARVORE_H
#define ARVORE_H


typedef struct arv Arv;
typedef struct arvno ArvNo;


Arv *arv_cria ();
ArvNo *arv_criano (int c, ArvNo * e, ArvNo * d);
void arv_libera (Arv * a);
void arv_imprime (Arv * a);
int arv_pertence (Arv * a, int c);
ArvNo *arv_busca (Arv * a, int c);
static ArvNo* insere (ArvNo* r, int v);
void abb_insere (Arv* a, int v);
static ArvNo* retira (ArvNo* r, int v);
void abb_retira (Arv* a, int v);
static ArvNo* busca (ArvNo* r, int v);

#endif
