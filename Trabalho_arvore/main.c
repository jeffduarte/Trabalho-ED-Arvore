#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "nomes.h"
#include "arvore.h"
#include "metodos.h"

int main()
{
    srand(time(NULL));
    Parv Paux;
    int menu = 0;
    int quantidade, aux, valor, i = 0;
    char nome[40];
    while (menu != 7)
    {
        system("cls");
        printf("                                TRABALHO ARVORE\n");
        printf("\n\n1 - Inserir\n2 - Busca\n3 - Enche a Arvore\n4 - Imprime Familias\n5 - Imprime em Ordem\n6 - Printa tamanho da arvore\n7 - Sai do Programa\n\nOpcao: ");
        scanf("%d",&menu);
        switch(menu)
        {
            case(1):
                printf("Digite o nome: ");
                setbuf(stdin,(NULL));
                gets(nome);
                printf("Digite o sexo 0: Feminino 1: Masculino: ");
                scanf("%d",&aux);
                insere_arv(&raiz,nome,aux,NULL);
                break;
            case(2):
                printf("Quem deseja buscar?: ");
                setbuf(stdin,(NULL));
                gets(nome);
                Paux = busca_arv(nome,&raiz,1);
                if(Paux == NULL)
                    printf("Nome nao encontrado");
                getch();
                break;
            case(3):
                if (raiz == NULL)
                {
                    printf("Quantidade de familias(20): ");
                    scanf("%d",&quantidade);
                    cria_primeiros(quantidade);
                    casa_emordem(raiz);
                    imp_emordem(raiz);
                    getch();
                }
                else
                {
                    printf("\nArvore cheia!");
                    getch();
                }
                break;
            case(4):
                for (i = 0;i<=quantidade_familias-1;i++)
                {
                    printf("%s  ",familias[i]);
                }
                getch();
                break;
            case(5):
                imp_emordem(&raiz);
                getch();
                break;
            case(6):
                printf("%d",tamanho_arv);
                getch();
                break;
        }
    }
    return 0;
}
