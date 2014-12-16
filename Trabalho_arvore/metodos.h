#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED
#endif // METODOS_H_INCLUDED

bool ordem_alfabetica(char palavra[], char palavra1[])
{
    int i;
    if (strlen(palavra) < strlen(palavra1) || strlen(palavra) == strlen(palavra1))
    {
        for (i=0;i<strlen(palavra);i++)
            {
                if ((int)toupper(palavra[i]) < (int)toupper(palavra1[i]))
                    return true;
                else if ((int)toupper(palavra[i]) > (int)toupper(palavra1[i]))
                    return false;

            }
            if (strlen(palavra1)>i)
                return true;
    }
    else
    {
        for (i=0;i < strlen(palavra);i++)
            {
                if ((int)toupper(palavra[i]) < (int)toupper(palavra1[i]))
                    return true;
                else if ((int)toupper(palavra[i]) > (int)toupper(palavra1[i]))
                    return false;
            }
            if (strlen(palavra)>i)
                return true;
    }
    printf("Mesma palavra");
    getch();
}


void cria_filhos(**arv pai, **arv mae, int quantidade)
{

}

void determina_tio(Parv* pessoa)
{
    (*pessoa)->
}
