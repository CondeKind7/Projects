#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main() {
    int i;
    char C='A';
    Arvore (*P_Arv)[10];
    Lista L;
    CriaLista(&L);
    for(i=0;i<10;i++){
        P_Arv=CriaArvore(P_Arv[i],i*3,C+i);
        InsereNaLista(&L,P_Arv);
        }
    ImprimeLista(L);
    return 0;
}
