#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main () {

    Arv *a = arv_cria ();

    abb_insere (a, 2);
    abb_insere (a, 7);
    abb_insere (a, 1);
    abb_insere (a, 3);
    abb_insere (a, 4);

    arv_imprime (a);

    printf ("\n quantidade de pares: %d", pares (a));

    printf ("\n quantidade de folhas: %d", folhas (a));

    printf ("\n quantidade de nos que possuem apenas um filho: %d",
	  um_filho (a));
    
    printf("\n quantidade de folhas maiores que x: %d", nfolhas_maiores(a, 2));
    
    printf("\n A soma dos numeros entre 7 e 1 é: %d", soma_xy(a, 7,1));
    
    printf("\n O nivel do num 4 eh: %d", nivel(a, 4));



    return 0;
}
