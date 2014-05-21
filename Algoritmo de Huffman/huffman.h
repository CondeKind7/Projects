
typedef struct Arvore *ApontaArvore;

typedef struct Arvore{
    char Letra;
    int Peso;
    ApontaArvore Esq;
    ApontaArvore Dir;
}Arvore;

typedef struct Celula *ApontaCelula;

typedef struct Lista{
    ApontaCelula Primeiro;
    ApontaCelula Ultimo;
}Lista;

typedef struct Celula{
    ApontaCelula Prox;
    ApontaArvore Arv_Cell;
}Celula;
