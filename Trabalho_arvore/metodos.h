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
    return 2;
}

void printa_filhos(arv* pessoa)
{
    int i;
    arv* aux;
    aux = pessoa->filho;
    if (aux == NULL)
        printf("Sem filhos");
    else
        printf("filhos: ");
    while (aux != NULL)
    {
        printf(" %s", aux->nome);
        aux = aux->irmao;
    }
}

void printa_tio(arv* pessoa)
{
    arv* aux;
    if (pessoa->pai == NULL || pessoa->pai->pai == NULL)
    {
        printf("Nenhum tio");
        return NULL;
    }
    aux = pessoa->pai->pai->filho;
    if (aux->irmao != NULL)
    {
        printf("Tios parte de pai: ");
        while (aux != NULL)
        {
            if (aux != pessoa->pai)
                printf("%s ",aux->nome);
            aux = aux->irmao;
        }
    }
    else
        printf("Nenhum tio parte de pai");
    aux = pessoa->mae->pai->filho;
    if (aux->irmao != NULL)
    {
        printf("Tios parte de mae: ");
        while (aux != NULL)
        {
            if (aux != pessoa->mae)
                printf("%s ",aux->nome);
            aux = aux->irmao;
        }
    }
    else
        printf("\nNenhum tio parte de mae");
}

void printa_irmaos(arv* pessoa)
{
    Parv aux;
    if (pessoa->pai == NULL)
    {
        printf("Nenhum irmao");
        return NULL;
    }
    if (pessoa->pai->filho->irmao == NULL)
    {
        printf("Nenhum irmao");
        return NULL;
    }
    aux = pessoa->pai->filho;
    printf("Irmao(s): ");
    while(aux != NULL)
    {
        if (aux != pessoa)
            printf("%s ",aux->nome);
        aux = aux->irmao;
    }
}

void printa_aspectos(arv *nodo)
{
    printa_pais(nodo);
    printf("\n");
    printa_avos(nodo);
    printf("\n");
    printa_filhos(nodo);
    printf("\n");
    printa_primos(nodo);
    printf("\n");
    printa_tio(nodo);
    printf("\n");
    printa_irmaos(nodo);
    printf("\n");
    printa_conjuge(nodo);
}

void printa_conjuge(arv* pessoa)
{
    if (pessoa == NULL)
        return;
    if (pessoa->conjuge != NULL)
    {
        printf("Conjuge: %s", pessoa->conjuge->nome);
        return;
    }
    else
    {
        printf("Solteiro(a)");
        return;
    }
}

void printa_pais(arv* pessoa)
{
    if (pessoa->pai == NULL)
        printf("Sem pais");
    else
    {
        printf("Pai: %s \nMae: %s",pessoa->pai->nome,pessoa->mae->nome);
    }
}

void printa_avos(arv* pessoa)
{
        if (pessoa->pai == NULL)
        {
            printf("Sem avos");
            return NULL;
        }
        if (pessoa->pai->pai == NULL)
        {
            printf("Sem avos");
            return NULL;
        }
        printf("avo: %s  ",pessoa->pai->pai->nome);

        printf("\navoh: %s",pessoa->pai->pai->conjuge->nome);
}

void printa_primos(arv* pessoa)
{
    Parv aux;
    if (pessoa->pai == NULL || pessoa->pai->irmao == NULL|| pessoa->pai->irmao->filho == NULL)
        printf("Nenhum tio parte de pai");
    else
    {
        printf("\nPrimos parte de pai:");
        aux = pessoa->pai->irmao->filho;
        while(aux!=NULL);
        {
            printf(" %s", aux->nome);
            aux = aux->irmao;
        }
    }
    if (pessoa->mae == NULL || pessoa->mae->irmao == NULL || pessoa->mae->irmao->filho == NULL)
        printf("\nNenhum primo parte de mae");
    else
    {
        printf("\nPrimos parte de mae:");
        aux = pessoa->mae->irmao->filho;
        while(aux!=NULL);
        {
            printf(" %s", aux->nome);
            aux = aux->irmao;

        }
    }
}


//Enche a árvore automaticamente procurando e fazendo filhos entre os casais
void casa_emordem(Parv nod)
{
    Parv conjuge = NULL;
    if (global<tamanho_arv)
        global = tamanho_arv;
    if (tamanho_arv < global*1.4 && tamanho_arv < 130)
    {
        if (nod != NULL)
        {
            if (nod->filho == NULL)
            {
                conjuge = busca_conjuge(nod, raiz);
                if (conjuge != NULL)
                 {
                    conjuge->conjuge = nod;
                    nod->conjuge = conjuge;
                    if (nod->sexo == 1)
                        cria_filhos(nod, conjuge);
                    else
                        cria_filhos(conjuge, nod);
                 }

            }
            casa_emordem(nod->esq);
            casa_emordem(nod->dir);
        }
    }
}

//Retorna uma pessoa em condições de ter filhos para outra pessoa
arv* busca_conjuge(arv* nod, arv* raiz)
{
    arv* verifica = NULL;
    if (nod != NULL && raiz != NULL && raiz != nod)
    {
        if ((raiz->filho == NULL) && (raiz->familia != (nod)->familia) && ((nod)->sexo != raiz->sexo))
        {
            return raiz;
        }
        if (verifica == NULL)
            verifica = busca_conjuge((nod), raiz->dir);
        if (verifica == NULL)
            verifica = busca_conjuge((nod), raiz->esq);
        if (verifica != NULL)
            return verifica;
        else
            return NULL;
    }
    else
        return NULL;
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
char* cria_nome(arv* pai, int sexo)
{
    char* nome = malloc(sizeof(char)*30);
    if (sexo == 1 && pai != NULL)
    {
        strcpy(nome,nomes_masculinos[rand()%25]);
        strcat(nome,familias[pai->familia]);
        return nome;
    }
    else if (pai != NULL)
    {
        strcpy(nome,nomes_femininos[rand()%25]);
        strcat(nome,familias[pai->familia]);
        return nome;
    }
}

//Cria os casais primogênitos de cada familia
void cria_primeiros(int quantidade)
{
    arv* pai;
    arv* mae;
    int sexo =1;
    int i = 0, j = 0;
    char nome[30];
    quantidade_familias = quantidade;
    for (i=0;i<quantidade;i++)
    {
        strcpy(familias[i],(sobre_nomes[rand()%20]));
        while (j<i)
        {
            if((strcmp(familias[i],familias[j]))==0)
            {
                j = -1;
                strcpy(familias[i],(sobre_nomes[rand()%20]));
            }
            j++;
        }
        strcpy(nome,nomes_masculinos[rand()%27]);
        strcat(nome,familias[i]);
        pai = insere_arv(&raiz,nome,sexo, NULL);
        pai->familia = i;
        sexo = 0;
        strcpy(nome,nomes_femininos[rand()%27]);
        strcat(nome,familias[i]);
        mae = insere_arv(&raiz,nome, sexo, NULL);
        mae->familia = i;
        pai->conjuge = mae;
        mae->conjuge = pai;
        sexo = 1;
        j = 0;
        cria_filhos(pai,mae);
    }
}

//Verifica se o pai e a mae tem parentesco, se não, cria um valor aleatório de filhos entre 0 e 4
void cria_filhos(arv* pai,arv* mae)
{
    int i, filhos, sexo;
    char nome[30];
    char* Pnome;
    arv* pessoa = NULL;
    arv* irmao = NULL;
    filhos = (1+rand()%4);
    for (i=0;i<filhos;i++)
    {
        sexo = rand()%2;
        Pnome = cria_nome(pai,sexo);
        strcpy(nome,Pnome);
        while (busca_arv(nome, &raiz,0) != NULL)
        {
            Pnome = cria_nome(pai,sexo);
            strcpy(nome,Pnome);
        }
        free(Pnome);
        if (pessoa != NULL)
            irmao = pessoa;
        pessoa = insere_arv(&raiz,nome,sexo, pai);
        if (irmao != NULL)
            irmao->irmao = pessoa;
        if (i==0)
        {
            pai->filho = pessoa;
            pai->conjuge->filho = pessoa;
        }
    }
}
