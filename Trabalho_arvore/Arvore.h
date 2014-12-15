#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#endif // ARVORE_H_INCLUDED


//estrutura da árvore

typedef struct arv
{
    struct arv* esq;
    struct arv* dir;
    struct arv* filho;
    struct arv* conjuge;
    char nome[20];
    char sexo;
}arv, Parv;

//funções principais

void cria_arv();
void deleta_arv();
void insere_arv();
void busca_arv();

//variaveis globais
arv* raiz = NULL;


//código de funções
insere_arv(arv* nod, char nome[])
{
    if (nod == NULL)
    {
        nod = (arv*)malloc(sizeof(arv));
        if(nod == NULL)
        {
            printf("Sem espaco na memoria");
        }
    }
    else if (compara_alfabet(nod, nod) == nod)
    {
        insere_arv(nod->esq);
    }
    else
    {
        insere_arv(nod->dir);
    }
}

deleta_arv(arv* nod)
{
    if (nod->esq && nod->dir) == NULL)
    {
        free(nod);
    }
    else if (nod->esq == NULL && nod->dir != NULL)
    {

    }
    else if (nod->dir == NULL && nod->esq != NULL)

}

