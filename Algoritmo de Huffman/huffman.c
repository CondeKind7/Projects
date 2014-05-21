#include <stdio.h>
#include "huffman.h"


void CriaLista(Lista *L){
    L->Primeiro=(ApontaCelula)malloc(sizeof(Celula));
    L->Primeiro->Prox=NULL;
    L->Ultimo=L->Primeiro;
}

void InsereNaLista(Lista *L, ApontaArvore P_Arv){
    L->Ultimo->Prox=(ApontaCelula)malloc(sizeof(Celula));
    L->Ultimo=L->Ultimo->Prox;
    L->Ultimo->Arv_Cell=P_Arv;
    L->Ultimo->Prox=NULL;
}

ApontaArvore CriaArvore(ApontaArvore P_Arv, int W, char C) {
    P_Arv=(ApontaArvore)malloc(sizeof(Arvore));
    P_Arv->Letra=C;
    P_Arv->Peso=W;
    P_Arv->Esq=NULL;
    P_Arv->Dir=NULL;
    return P_Arv;
}

void CriaPai(ApontaArvore FilhoEsq, ApontaArvore FilhoDir){
    ApontaArvore Pai,Aux;
    Pai->Esq=FilhoEsq;
    Pai->Dir=FilhoDir;
    Pai->Peso=FilhoEsq->Peso+FilhoDir->Peso;
    if(FilhoEsq->Letra>FilhoDir->Letra) Pai->Letra=FilhoEsq->Letra;
    else Pai->Letra=FilhoDir->Letra;
    free(FilhoEsq);
    free(FilhoDir);
    FilhoEsq=Pai;
}

void ImprimeLista(Lista L){
    ApontaCelula Aux;
    Aux=L.Primeiro->Prox;
    while(Aux!=NULL){
        printf("Letra: %c\nPeso: %d\n\n", Aux->Arv_Cell->Letra,Aux->Arv_Cell->Peso);
        Aux=Aux->Prox;
        }
}

void Central(ApontaArvore P_Arv) {
    if (P_Arv == NULL) return;
    Central(P_Arv->Esq);
    printf("Letra: %c\nPeso: %d\n\n", P_Arv->Letra,P_Arv->Peso);
    Central(P_Arv->Dir);
}

/*
void InsereNaDireita(ApontaArvore Pai, ApontaArvore Filho) {
    if(Pai->Dir==NULL) Pai->Dir=Filho;
    else printf("Ja existe filho da direita!\n");
    return;
}

void InsereNaEsquerda(ApontaArvore Pai, ApontaArvore Filho) {
    if(Pai->Esq==NULL) Pai->Esq=Filho;
    else printf("Ja existe filho da esquerda!\n");
    return;
}
*/
