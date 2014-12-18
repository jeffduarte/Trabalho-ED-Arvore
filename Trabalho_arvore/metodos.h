#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED
#endif // METODOS_H_INCLUDED

//Retorna 0 se a primeira palavra vier primeiro que a segunda, e 1 se o contrário 2 se iguais
int ordem_alfabetica(char palavra[], char palavra1[])
{
    int i;
    if (strlen(palavra) < strlen(palavra1) || strlen(palavra) == strlen(palavra1))
    {
        for (i=0;i<strlen(palavra);i++)
            {
                if ((int)toupper(palavra[i]) < (int)toupper(palavra1[i]))
                    return 0;
                else if ((int)toupper(palavra[i]) > (int)toupper(palavra1[i]))
                    return 1;

            }
            if (strlen(palavra1)>i)
                return 0;
    }
    else
    {
        for (i=0;i < strlen(palavra);i++)
            {
                if ((int)toupper(palavra[i]) < (int)toupper(palavra1[i]))
                    return 0;
                else if ((int)toupper(palavra[i]) > (int)toupper(palavra1[i]))
                    return 1;
            }
            if (strlen(palavra)>i)
                return 0;
    }
    printf("Mesma palavra");
    getch();
    return 2;
}

void printa_filhos(arv* pessoa)
{
    int i;
    arv* aux;
    aux = pessoa->filho;
    while (aux != NULL)
    {
        printf("filhos: ");
        printf("%s ", aux->nome);
        aux = aux->irmao;
    }
}

void printa_tio(arv* pessoa)
{
    int i;
    arv* aux;
    if (pessoa->pai == NULL)
        return NULL;
    aux = pessoa->pai->irmao;
    while (aux != NULL)
    {
        printf("Tios: ");
        printf("%s ",aux->nome);
        aux = aux->irmao;
    }
    aux = pessoa->mae->irmao;
    while (aux != NULL)
    {
        printf("Tios: ");
        printf("%s ",aux->nome);
        aux = aux->irmao;
    }
}

void printa_avos(arv* pessoa)
{
        if (pessoa->pai->pai == NULL)
            return NULL;
        printf("avo: %s  ",pessoa->pai->pai);
        printf("avoh: %s",pessoa->pai->pai->conjuge);
}

void printa_primos(arv* pessoa)
{
    if (pessoa->pai == NULL || pessoa->pai->irmao == NULL|| pessoa->pai->irmao->filho == NULL)
        printf("");
    else
    {
        printf("\nPrimos parte de pai: ");
        Parv aux;
        aux = pessoa->pai->irmao->filho;
        while(pessoa->pai->irmao->filho!=NULL);
        {

            printf("%s", aux->nome);
            aux = aux->irmao;

        }
    }
    if (pessoa->mae == NULL || pessoa->mae->irmao == NULL || pessoa->mae->irmao->filho == NULL)
        printf("");
    else
    {
        printf("\nPrimos parte de mae: ");
        Parv aux;
        aux = pessoa->mae->irmao->filho;
        while(pessoa->mae->irmao->filho!=NULL);
        {

            printf("%s", aux->nome);
            aux = aux->irmao;

        }
    }
}


//Enche a árvore automaticamente tendo limite de até 200 pessoas
void casa_emordem(Parv nod)
{
    while (tamanho_arv < 200)
    {
        if (nod != NULL)
        {
            casa_emordem(nod->esq);
            if (nod->esq->filho == NULL)
            {
                nodoaux1 = busca_conjuge(nod, raiz);
                nodoaux1->conjuge = nod;
                nod->conjuge = nodoaux1;
                if (nod->sexo == 0)
                    cria_filhos(nod, nodoaux1);
                else
                    cria_filhos(nodoaux1, nod);
            }
            casa_emordem(raiz->dir);
        }

    }
}

//Retorna uma pessoa em condições de ter filhos para outra pessoa
arv* busca_conjuge(arv* nod, arv* raiz)
{
    if (nod != NULL)
    {
        if (raiz->filho == NULL && raiz->familia != (nod)->familia && (nod)->sexo != raiz->sexo)
            return raiz;
        busca_conjuge((nod), raiz->dir);
        busca_conjuge((nod), raiz->esq);
    }
}


//Imprime na ordem direita, raiz, esquerda
void imp_minhaordem(Parv raiz)
{
    if (raiz != NULL)
    {
        imp_minhaordem(raiz->dir);
        printf("\n%s",raiz->nome);
        imp_minhaordem(raiz->esq);
    }
}

//Cria um nome para a pessoa de acordo com o nome do pai(O sobrenome do pai passa para os filhos)
char cria_nome(arv* pai, int sexo)
{
    char nome[20];
    if (sexo == 1)
    {
        strcpy(nome,nomes_masculinos[rand()%30]);
        strcat(nome,familias[pai->familia]);
        return nome;
    }
    else
    {
        strcpy(nome,nomes_femininos[rand()%30]);
        strcat(nome,familias[pai->familia]);
        return nome;
    }
}

//Cria os casais primogênitos de cada familia
void cria_primeiros(int quantidade)
{
    arv* pai;
    arv* mae;
    int sexo =1, i = 0;
    char nome[20];
    for (i=0;i<quantidade;i++)
    {
        srand(time(NULL));
        strcpy(familias[i],(sobre_nomes[rand()%20]));
        strcat(nome,familias[i]);
        pai = insere_arv(&raiz,nome,sexo, NULL);
        sexo = 0;
        mae = insere_arv(&raiz,nome, sexo, NULL);
        sexo = 1;
        cria_filhos(pai,mae);
    }
}

//Verifica se o pai e a mae tem parentesco, se não, cria um valor aleatório de filhos entre 0 e 4
void cria_filhos(arv* pai,arv* mae)
{
    int i, filhos;
    arv* pessoa;
    arv* irmao;
    filhos = (1+rand()%4);
    int sexo;
    if (pai->familia == mae->familia)
        return NULL;
    srand(time(NULL));
    for (i=0;i<filhos;i++)
    {
        srand(time(NULL));
        if (pessoa != NULL)
            irmao = pessoa;
        sexo = rand()%1;
        pessoa = insere_arv(&raiz,cria_nome(pai,sexo),sexo, NULL);
        irmao->irmao = pessoa;
    }
}

