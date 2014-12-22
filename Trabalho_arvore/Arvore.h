#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#endif // ARVORE_H_INCLUDED

//estrutura da árvore

typedef struct arv
{
    struct arv* esq;
    struct arv* dir;
    struct arv* filho;
    struct arv* irmao;
    struct arv* conjuge;
    struct arv* pai;
    struct arv* mae;
    int familia;
    char nome[20];
    char sexo;
}arv, *Parv;

//funções principais

void deleta_arv();
arv* insere_arv();
void imp_emordem(Parv raiz);
void imp_preordem(Parv raiz);
void imp_posordem(Parv raiz);
arv* retorna_menor(arv* nod, int zerar_anterior);
arv* busca_arv(char nome[30] ,Parv* nodo, int aspectos);

//funções secundárias

int ordem_alfabetica(char palavra[], char palavra1[]);
void cria_filhos(arv* pai,arv* mae);
void cria_primeiros(int quantidade);
char* cria_nome(arv* pai, int sexo);
arv* busca_minhaordem(Parv raiz);
arv* busca_conjuge(arv* raiz, arv* nod);
void casa_emordem(Parv nod);
void printa_primos(arv* pessoa);
void printa_avos(arv* pessoa);
void printa_tio(arv* pessoa);
void printa_filhos(arv* pessoa);

//variaveis globais

arv* raiz = NULL;
arv* nodoaux = NULL;
arv* nodoaux1 = NULL;
arv* nodoaux2 = NULL;
char familias[60][21];
int tamanho_arv = 0;
int quantidade_familias = 0;
int global = 0;
//código de funções

//Insere a pessoa na árvore em ordem alfabética
arv* insere_arv(Parv* nod, char nome[], int sexo, arv* pai)
{
    if ((busca_arv(nome,&raiz,0) != NULL))
        return NULL;
    if ((*nod) == NULL)
    {
        (*nod) = (arv*)malloc(sizeof(arv));
        tamanho_arv +=1;
        if((*nod) == NULL)
        {
            printf("Sem espaco na memoria");
            return NULL;
        }
        (*nod)->esq = NULL;
        (*nod)->dir = NULL;
        (*nod)->filho = NULL;
        (*nod)->pai = pai;
        (*nod)->conjuge = NULL;
        (*nod)->mae = NULL;
        (*nod)->sexo = sexo;
        if (pai != NULL)
        {
            ( *nod)->mae = pai->conjuge;
            ( *nod)->familia = pai->familia;
        }
        strcpy((*nod)->nome, nome);
        return (*nod);
    }
    else if (ordem_alfabetica(nome, (*nod)->nome) == 0)
    {
        insere_arv(&((*nod)->esq), nome, sexo, pai);
    }
    else
    {
        insere_arv(&((*nod)->dir), nome, sexo, pai);
    }
}

//Deleta um nó da árvore(não usada no programa)
void deleta_arv(arv* nod)
{
    int z = 1;
    arv* aux = NULL;
    if (nod == NULL)
        return;
    if (nod->esq == NULL && nod->dir == NULL)
    {
        free(nod);
    }
    else if (nod->esq == NULL && nod->dir != NULL)
    {
        aux = nod;
        nod = retorna_menor(nod, z);
        nod->dir = aux->dir;
        free(aux);
    }
    else if (nod->dir == NULL && nod->esq != NULL)
    {
        aux = nod;
        nod = retorna_menor(nod, z);
        nod->esq = aux->esq;
        free(aux);
    }
    else if (nod->dir != NULL && nod->esq != NULL)
    {
        aux = nod;
        nod = retorna_menor(nod, z);
        nod->esq = aux->esq;
        nod->dir = aux->dir;
        free(aux);
    }

}


//Retorna o menor valor a direita ou o maior a esquerda para substituir quando for deletar
arv* retorna_menor(arv* nod, int zerar_anterior)
{
    arv* aux = NULL;
    arv* aux2 = NULL;
    if (nod->esq != NULL)
    {
        aux = nod->esq;
        while (aux->dir != NULL)
        {
            aux2 = aux;
            aux = aux->dir;
            if (aux->dir == NULL)
                if (zerar_anterior == 1)
                    aux2->dir = NULL;
                return aux;
        }
    }
        else if (nod->dir != NULL)
    {
        aux = nod->dir;
        while (aux->esq != NULL)
        {
            aux2 = aux;
            aux = aux->esq;
            if (aux->esq == NULL)
                if (zerar_anterior == 1)
                    aux2->esq = NULL;
                return aux;
        }
    }
    return NULL;
}

//Busca um nome na árvore e imprime seu endereço
arv* busca_arv(char nome[30] ,Parv* nodo, int aspectos)
{
    if ((*nodo) == NULL)
        return NULL;
    else if (strcmp(nome,(*nodo)->nome)==0)
    {
        if (aspectos == 1)
        {
            printa_aspectos(*nodo);
            return (*nodo);
        }
        else
            return (*nodo);
    }
    else if (ordem_alfabetica(nome,(*nodo)->nome) == 0)
    {
        busca_arv(nome,&((*nodo)->esq),aspectos);
    }
    else if (ordem_alfabetica(nome,(*nodo)->nome) == 1)
    {
        busca_arv(nome,&((*nodo)->dir),aspectos);
    }
}


//Imprime a árvore em ordem
void imp_emordem(Parv raiz)
{
    if (raiz != NULL)
    {
        imp_emordem(raiz->esq);
        printf("\n%s",raiz->nome);
        imp_emordem(raiz->dir);
    }
}


//Imprime a árvore em Pré-ordem
void imp_preordem(Parv raiz)
{
    if (raiz != NULL)
    {
        printf("\n%s",raiz->nome);
        imp_preordem(raiz->esq);
        imp_preordem(raiz->dir);
    }
}

//Imprime a árvore em Pós-ordem
void imp_posordem(Parv raiz)
{
    if (raiz != NULL)
    {
        imp_posordem(raiz->esq);
        imp_posordem(raiz->dir);
        printf("\n%s",raiz->nome);
    }
}
