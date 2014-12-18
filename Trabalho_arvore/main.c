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
    int menu = 0;
    int quantidade, aux, valor;
    while (1)
    {
        system("cls");
        printf("                                TRABALHO ARVORE\n");
        printf("\n\n1 - Enche a Arvore\n2 - Imprime\n\nOpcao: ");
        scanf("%d",&menu);
        switch(menu)
        {
            case(1):
                printf("Quantidade de familias(20): ");
                scanf("%d",&quantidade);
                cria_primeiros(quantidade);
                printf("Chegou aqui");
                getch();
                //casa_emordem(raiz);
                printf("OPA!!!");
                imp_emordem(raiz);
                getch();
        }
    }
    return 0;
}
