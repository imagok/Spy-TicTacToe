//Comentando rola piça
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>


// LARGURA MAX DA TELA EM WINDOWS: 80 CHARS!!

//printf("\n");
//Info preliminar:
//Opcoes de menu: 1 - nova partida, 99 - sair da partida ou do game
//X = player, O = pc

//Declaração de variaveis
static int num_partida = 1;
int i, j;
int board[10];
int opcao;
int var_rematch_ou_quit = 0;
int quit;
char teste_texto[]="Teste de texto";
char opcao_menu;

//Assinatura de funcoes
void spy_intro();
void main_menu();
void clear_board();
void printa_board();
void printa_instrucoes();
void partida();
int alguem_ganhou();
void player_joga_ou_sai();
void pc_joga();
void pc_escolhe_aleatorio();
int jogada_impossivel();
int empate();
void novo_jogo_ou_quit();



//It's runtime!!11

int main ()
{
        do {
            if (var_rematch_ou_quit == 0)
                spy_intro();
            else
                printa_topo();
            if (var_rematch_ou_quit == 0)
                main_menu();
            printf("\nIniciando partida");
            animate("...", 500);
            printf("\n");
            printf ("\n                                   Partida %d\n", num_partida);
            num_partida += 1;
            clear_board();
            //printa_instrucoes();
            printa_board();
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
    system("cls"); //se windows
    printa_topo();
    animate("                                 JOGO DA VELHA \n", 5);
    animate("-------------------------------------------------------------------------------- \n", 5);
    animate("1) Forme tres em linha para vencer.\n", 5);
    animate("2) O jogador marca X e a maquina marca O.\n", 5);
    animate("3) Para marcar, na sua vez, digite o numero da posicao desejada do tabuleiro e\n", 5);
    animate("   tecle enter.\n", 5);
    animate("4) A esquerda do tabuleiro do jogo ha um tabuleiro de referencia com as\n", 5);
    animate("   posicoes:\n", 5);
    //printa_board();
    //printf("5) Para sair a qualquer momento, digite 99 e tecle enter.\n");
    //printf("\nVamos la!\n");
    animate("\nPress <ENTER> to return to the main menu", 10);
    getchar();
    main_menu();
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
        else if (opcao == 99) {
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
	//checa se pode ganhar. se sim, ganha.
	for (i=1; i<=9; i++) {
		if (board[i] == 0) {
			switch (i) {
			case 1:
				if (board[2] == 'O' && board[3] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[4] == 'O' && board[7] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[5] == 'O' && board[9] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 2:
				if (board[1] == 'O' && board[3] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[5] == 'O' && board[8] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 3:
				if (board[1] == 'O' && board[2] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[5] == 'O' && board[7] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[6] == 'O' && board[9] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 4:
				if (board[1] == 'O' && board[7] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[5] == 'O' && board[6] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 5:
				if (board[1] == 'O' && board[9] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[2] == 'O' && board[8] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[3] == 'O' && board[7] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[4] == 'O' && board[6] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 6:
				if (board[3] == 'O' && board[9] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[4] == 'O' && board[5] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 7:
				if (board[1] == 'O' && board[4] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[3] == 'O' && board[5] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[8] == 'O' && board[9] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 8:
				if (board[2] == 'O' && board[5] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[7] == 'O' && board[9] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 9:
				if (board[1] == 'O' && board[5] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[3] == 'O' && board[6] == 'O') {
					board[i] = 'O';
					return;
				}
				else if (board[7] == 'O' && board[8] == 'O') {
					board[i] = 'O';
					return;
				}
				else
					break;
			}
		}
	}

	//checa se pode perder. se sim, impede na primeira oportunidade
	for (i=1; i<=9; i++) {
		if (board[i] == 0) {
			switch (i) {
			case 1:
				if (board[2] == 'X' && board[3] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[4] == 'X' && board[7] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[5] == 'X' && board[9] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 2:
				if (board[1] == 'X' && board[3] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[5] == 'X' && board[8] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 3:
				if (board[1] == 'X' && board[2] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[5] == 'X' && board[7] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[6] == 'X' && board[9] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 4:
				if (board[1] == 'X' && board[7] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[5] == 'X' && board[6] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 5:
				if (board[1] == 'X' && board[9] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[2] == 'X' && board[8] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[3] == 'X' && board[7] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[4] == 'X' && board[6] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 6:
				if (board[3] == 'X' && board[9] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[4] == 'X' && board[5] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 7:
				if (board[1] == 'X' && board[4] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[3] == 'X' && board[5] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[8] == 'X' && board[9] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 8:
				if (board[2] == 'X' && board[5] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[7] == 'X' && board[9] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			case 9:
				if (board[1] == 'X' && board[5] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[3] == 'X' && board[6] == 'X') {
					board[i] = 'O';
					return;
				}
				else if (board[7] == 'X' && board[8] == 'X') {
					board[i] = 'O';
					return;
				}
				else
					break;
			}
		}
	}
	pc_escolhe_aleatorio();
}

pc_escolhe_aleatorio()
{
    i = rand () %9;

    if((i != 0) && (board[i] == 0)) {
        board[i] = 'O';
		return;
    }
    else {
        pc_escolhe_aleatorio();
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
    printf("                   Posicoes                           Jogo\n");
    printf("\n");
    printf("                    ³   ³                            ³   ³   \n");
    printf("                  1 ³ 2 ³ 3                        %c ³ %c ³ %c\n", board[1], board[2], board[3]);
    printf("                ÄÄÄÄÅÄÄÄÅÄÄÄÄ                    ÄÄÄÄÅÄÄÄÅÄÄÄÄ\n");
    printf("                  4 ³ 5 ³ 6                        %c ³ %c ³ %c \n", board[4], board[5], board[6]);
    printf("                ÄÄÄÄÅÄÄÄÅÄÄÄÄ                    ÄÄÄÄÅÄÄÄÅÄÄÄÄ\n");
    printf("                  7 ³ 8 ³ 9                        %c ³ %c ³ %c\n", board[7], board[8], board[9]);
    printf("                    ³   ³                            ³   ³   \n");
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

    */



//Spy Intro

spy_intro(){
animate("  _____                 _______  _        _______            _______ \n", 4);
animate(" / ____|               |__   __|(_)      |__   __|          |__   __|\n", 4);
animate("| (___   _ __   _   _     | |    _   ___    | |  __ _   ___    | |  ___    ___ \n", 4);
animate(" \\___ \\ | '_ \\ | | | |    | |   | | / __|   | | / _` | / __|   | | / _ \\  / _ \\\n", 4);
animate(" ____) || |_) || |_| |    | |   | || (__    | || (_| || (__    | || (_) ||  __/\n", 4);
animate("|_____/ | .__/  \\__, |    |_|   |_| \\___|   |_| \\__,_| \\___|   |_| \\___/  \\___|\n", 4);
animate("        | |      __/ |                                                         \n", 4);
animate("        |_|     |___/ \n", 3);
animate("--------------------------------------------------------------------------------", 4);
Sleep(1000);
}

void animate(char* texto, int velocidade){
    int i;
    for(i=0; i < strlen(texto); i++){
    printf("%c", texto[i]);
    Sleep(velocidade);
    }
}

main_menu(){
    system("cls"); //se windows
    printa_topo();
    animate("\n\n\t1 - Jogar\n", 5);
    animate("\t2 - Instrucoes\n", 5);
    animate("\t3 - Creditos\n", 5);
    animate("\tQ - Sair\n", 5);
    printf("\n\tOpcao: ");
    scanf("%c)", &opcao_menu);
    getchar();
    switch(opcao_menu){
case '1':
    break;

case '2':
    printa_instrucoes();
    break;

case '3':
    chama_creditos();
    break;

case 'Q':
case 'q':
    exit(0);
    break;

default:
    printf("\nOpcao invalida! \nPressione <ENTER> para continuar\n");
    getchar();
    main_menu();
    }
}

void printa_topo(){
    printf("  _____                 _______  _        _______            _______ \n");
    printf(" / ____|               |__   __|(_)      |__   __|          |__   __|\n");
    printf("| (___   _ __   _   _     | |    _   ___    | |  __ _   ___    | |  ___    ___ \n");
    printf(" \\___ \\ | '_ \\ | | | |    | |   | | / __|   | | / _` | / __|   | | / _ \\  / _ \\\n");
    printf(" ____) || |_) || |_| |    | |   | || (__    | || (_| || (__    | || (_) ||  __/\n");
    printf("|_____/ | .__/  \\__, |    |_|   |_| \\___|   |_| \\__,_| \\___|   |_| \\___/  \\___|\n");
    printf("        | |      __/ |                                                         \n");
    printf("        |_|     |___/ \n");
    printf("--------------------------------------------------------------------------------");
}

void chama_creditos(){
    system("cls"); //se windows
    printa_topo();
    animate("\nimagok: #Coding, #Compiling, #Complaining, #low_class_jokes.lib\n", 10);
    animate("Spy: #Coding + #Insulting = #Consulting\n", 10);
    animate("\nPress <ENTER> to return to the main menu", 10);
    getchar();
    main_menu();
}
