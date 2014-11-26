#include <stdio.h>

//Info preliminar:
//Para as equivalências, 0 = FALSE, 1 = TRUE.
//X = player, O = pc

//Declaração de variaveis
int i, j;
char board[10];
int alguem_quitou = 0;
char opcao;

//Declaracao de funcoes
void popula_board();
printa_board();
void printa_instrucoes();
void loop_dos_turnos();
int alguem_ganhou();
//alguem_quitou();
//prompta_jogar_ou_sair();
void player_joga_ou_sai();
void pc_joga();
int jogada_impossivel();
//atualiza_board();

//It's runtime!!11

int main ()
{
    //criar a board
    popula_board();
    printa_instrucoes();
    loop_dos_turnos();
    printf("pimba");

    return 0;
}


//Definição de funcoes#######################################################################################################################################################

popula_board()
{
    for (i=1;i<=9; i++)
            board[i] = '*';
}

printa_instrucoes()
{
    printf("JOGO DA VELHA \n");
    printf("-------------------------------------------------------------------------------- \n");
    printf(" \n");
    printf("Instrucoes \n");
    //blablabla
}

loop_dos_turnos()
{
    while(1==1)
    {
        if (alguem_ganhou() == 0 /*|| alguem_quitou == 1*/)
            printf("teste \n");
            break;
        player_joga_ou_sai();
        printa_board();


        if (alguem_ganhou() == 1 || alguem_quitou == 1)
            break;

        pc_joga();
        printa_board();

    }


// se alguem ganhou, informar
//Se alguém quitou Prompt "Quer jogar nova partida?"

}

alguem_ganhou()
{
    printf("Inicio alguem_ganhou");

    //Alguem ganhou na horizontal?
    for(i=1; i<=7; i+=3) {

        if((board[i] != '*') && (board[i] == board[i+1]) && (board[i] == board[i+2]))
        {
            printf("Temos um vencedor! \n");
            return 1;
        }

    }

    //Alguem ganhou na vertical?
    for(i=1; i<=3; i++) {
        if((board[i] != '*') && (board[i] == board[i+3]) && (board[i] == board[i+6]))
        {
            return 1;
        }

    }

    //Alguem ganhou em uma das diagonais?
    if((board[1] != '*') && (board[1] == board[5]) && (board[1] == board[9]))
    {
        return 1;
    }

    if((board[3] != '*') && (board[3] == board[5]) && (board[3] == board[7]))
    {
        return 1;
    }


        return 0;

}

//alguem_quitou()



//prompta_jogar_ou_sair()



player_joga_ou_sai()
{
    printf("joga \n");
    int sem_erro = 0;

    do {
        printf("Escolha uma posicao pelo seu numero \n");
        printf("ou digite 's' para sair da partida:  \n");
        scanf("%c", &opcao);
        if(opcao>=1 && opcao<=9 && jogada_impossivel() == 0) {
            board[opcao] = 'X';
            sem_erro = 1;
        }
        else if (opcao == 's' || 'S') {
            alguem_quitou = 1;
            sem_erro = 1;
        }
        else
            printf("Opção inválida. Tente novamente. \n");
    } while (sem_erro == 0);

}

pc_joga()
{
    int i = rand() %2;
    if(board[i] = '*') {
        board[i] = 'O';
    }
    else
        pc_joga();
}
jogada_impossivel()
{
    if(board[opcao] != '*')
        return 1;
}
//atualiza_board()

printa_board()
{
    printf("|%c|%c|%c| \n", board[1], board[2], board[3]);
    printf("|%c|%c|%c| \n", board[4], board[5], board[6]);
    printf("|%c|%c|%c| \n", board[7], board[8], board[9]);
}

//Seção de testes
    /*
    for (i=0;i<3; i++)
        for(j=0; j<3; j++)
            printf("Posicao [%d] [%d] = %c \n", i, j, board[i][j]);
    */





