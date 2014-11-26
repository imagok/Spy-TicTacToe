#include <stdio.h>
#include <stdlib.h>

//printf("\n");
//Info preliminar:
//Opcoes de menu: 1 - nova partida, 99 - sair da partida ou do game
//X = player, O = pc

//Declaração de variaveis
int i, j;
int board[10];
int opcao;
int var_rematch_ou_quit;
int quit;

//Declaracao de funcoes
void clear_board();
void printa_board();
void printa_instrucoes();
void partida();
int alguem_ganhou();
void player_joga_ou_sai();
void pc_joga();
int jogada_impossivel();
int empate();
void novo_jogo_ou_quit();


//It's runtime!!11

int main ()
{
        do {
        clear_board();
        printa_instrucoes();
        partida();
        novo_jogo_ou_quit();
        } while (var_rematch_ou_quit == 1);
    return 0;
}


//Definição de funcoes#######################################################################################################################################################

clear_board()
{
    for (i=1;i<=9; i++)
            board[i] = 0;
}

printa_instrucoes()
{
    printf("JOGO DA VELHA \n");
    printf("-------------------------------------------------------------------------------- \n");
    printf("1) Forme tres em linha para vencer.\n");
    printf("2) O jogador marca X e a maquina marca O.\n");
    printf("3) Para marcar, na sua vez, digite o numero da posicao desejada\n");
    printf("   do tabuleiro e tecle enter.\n");
    printf("4) A esquerda do tabuleiro do jogo ha um tabuleiro de referencia\n");
    printf("   com as posicoes:\n");
    printa_board();
    printf("5) Para sair a qualquer momento, digite 99 e tecle enter.\n");
    printf("\nVamos la!\n");
}

partida()
{
    while(1==1)
    {
        player_joga_ou_sai();

        if (opcao == 99)
            break;

            printa_board();


            if (alguem_ganhou() || empate())
                break;

            printf("\nVez da maquina:\n");
            pc_joga();

            printa_board();

            if (alguem_ganhou() || empate())
                break;

    }

// se alguem ganhou, informar
//Se alguém quitou Prompt "Quer jogar nova partida?"

}

alguem_ganhou()
{
    //Alguem ganhou na horizontal?
    for(i=1; i<=7; i+=3) {
        if((board[i] != 0) && (board[i] == board[i+1]) && (board[i] == board[i+2]))
        {
            printf("Temos um vencedor!\n");
            return 1;
        }

    }

    //Alguem ganhou na vertical?
    for(i=1; i<=3; i++) {
        if((board[i] != 0) && (board[i] == board[i+3]) && (board[i] == board[i+6]))
        {
            printf("Temos um vencedor! \n");
            return 1;
        }

    }

    //Alguem ganhou em uma das diagonais?
    if((board[1] != 0) && (board[1] == board[5]) && (board[1] == board[9]))
    {
        printf("Temos um vencedor! \n");
        return 1;
    }

    if((board[3] != 0) && (board[3] == board[5]) && (board[3] == board[7]))
    {
        printf("Temos um vencedor! \n");
        return 1;
    }


        return 0;

}

//alguem_quitou()



//prompta_jogar_ou_sair()



player_joga_ou_sai()
{
    int sem_erro = 0;

    do {
        printf("\nVez do jogador:\n");
        printf("\nEscolha uma posicao pelo seu numero\n");
        printf("ou digite 99 para sair da partida. ");
        scanf("%d", &opcao);
        printf("\n");
        if((opcao>=1) && (opcao<=9) && (jogada_impossivel() == 0)) {
            board[opcao] = 'X';
            sem_erro = 1;
        }
        else if ((opcao == 99) /*|| (opcao == 'S')*/) {
            sem_erro = 1;
        }
        else {
            printf("Opcao invalida. Tente novamente.\n");
            printa_board();
        }

    } while (sem_erro == 0);



}

pc_joga()
{
    int i = rand() %9;
    if((i != 0) && (board[i] == 0)) {
        board[i] = 'O';
    }
    else {
        pc_joga();
    }
}

empate()
{
    int sum_empate = 0;

    //checa se board cheio
    for (i=1; i<=9; i++) {
        if (board[i] != 0)
            sum_empate += 1;
    }
    //Se todos slots ocupados, empate.
    if (sum_empate == 9) {
        printf("\nEmpate!\n");
        return 1;
    }
    else
        return 0;
}

jogada_impossivel()
{
    if(board[opcao] != 0) {
        return 1;
    }
    else
        return 0;

}
//atualiza_board()

printa_board()
{
    printf("\n");
    printf("             Posicoes                     Jogo\n");
    printf("\n");

    printf("              ³   ³                      ³   ³   \n");
    printf("            1 ³ 2 ³ 3                  %c ³ %c ³ %c\n", board[1], board[2], board[3]);
    printf("          ÄÄÄÄÅÄÄÄÅÄÄÄÄ              ÄÄÄÄÅÄÄÄÅÄÄÄÄ\n");
    printf("            4 ³ 5 ³ 6                  %c ³ %c ³ %c \n", board[4], board[5], board[6]);
    printf("          ÄÄÄÄÅÄÄÄÅÄÄÄÄ              ÄÄÄÄÅÄÄÄÅÄÄÄÄ\n");
    printf("            7 ³ 8 ³ 9                  %c ³ %c ³ %c\n", board[7], board[8], board[9]);
    printf("              ³   ³                      ³   ³   \n");
    printf("\n");
}

novo_jogo_ou_quit()
{
    printf("\nPara jogar uma nova partida, digite 1,\n");
    printf("para fechar o jogo, digite 99: ");
    scanf("%d", &var_rematch_ou_quit);
    printf("\n");

    if (var_rematch_ou_quit == 1) {
        printf("\nNovo jogo.\n\n");
        system("cls"); //se windows
        //system("clear"); //se linux

    }
    else if (var_rematch_ou_quit == 99) {
        printf("\nAte a proxima!\n\n");
    }
    else {
        printf("\nOpcao invalida.\n");
        novo_jogo_ou_quit();
    }
}

//Seção de testes
    /*
    for (i=0;i<3; i++)
        for(j=0; j<3; j++)
            printf("Posicao [%d] [%d] = %c \n", i, j, board[i][j]);
    */




