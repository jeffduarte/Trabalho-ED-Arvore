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
    struct arv* pai;
    char nome[20];
    char sexo;
}arv, *Parv;

//funções principais

void cria_arv();
void deleta_arv();
void insere_arv();
arv busca_arv();
void retorna_menordir();
//variaveis globais
arv* raiz = NULL;
arv* nodoaux = NULL;
arv* nodoaux1 = NULL;
arv* filhos_solteiros[10];
arv* pai_familias[10]


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
    else if (ordem_alfabetica(nome, nod->nome) == true)
    {
        insere_arv(nod->esq, nome);
    }
    else
    {
        insere_arv(nod->dir, nome);
    }
}

deleta_arv(arv* nod)
{
    if (nod == NULL)
        return;
    arv *aux;
    if (nod->esq && nod->dir) == NULL)
    {
        free(nod);
    }
    else if (nod->esq == NULL && nod->dir != NULL)
    {
        aux = nod;
        nod = nod->esq;
        free(aux);
    }
    else if (nod->dir == NULL && nod->esq != NULL)arv retorna_menordir(arv* nod)
{
    nodoaux1 = nod->dir;
    if (nod->esq != NULL)
        nodoaux = nod;
        retorna_menordir(nod->esq);
    else
        return nod;
}
    {
        aux = nod;
        nod = nod->dir;
        free(aux);
    }
    else
    {
        aux = nod;
        nod = retorna_menordir(nod);
        nodoaux->esq = NULL;
    }

}

arv retorna_menordir(arv* nod)
{
    if aux_int == 0
    {
        nod = nod->dir;
        aux_int = 1;
    }
    if (nod->esq != NULL)
        nodoaux = nod;
        retorna_menordir(nod->esq);
    else
        aux_int = 0;
        return nod;
}

arv busca_arv(char nome[30] ,arv* nodo)
{
    if raiz == NULL
        return;
    if (strcmp(nome,raiz->nome)==0)
        return raiz;
    else if (ordem_alfabetica(nome,raiz->nome) == true)
    {
        if (nodo->esq == NULL)
            return NULL;
        busca_arv(nome,raiz->esq)
    }
    else
    {
        if (nodo->dir == NULL)
            return NULL
        busca_arv(nome, raiz->dir)
    }
}
