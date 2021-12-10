#include <stdio.h>
#include <stdlib.h>

char casilla[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int opcion, jugador;

int checkForWin();
void displayBoard();
void markBoard(char mark);

int main()
{
    int gameStatus;
    char bando;
    jugador = 1;
    do{
        displayBoard();
        jugador = (jugador % 2)?1:2;

        printf("Jugador %d, ingrese un numero: ",jugador);
        scanf("%d",&opcion);
        bando = (jugador==1)?'X':'O';
        markBoard(bando);
        gameStatus = checkForWin();
        jugador ++;

    }while(gameStatus == -1);

    if(gameStatus == 1) //player = 2
        printf("==>Jugador %d ha ganado \n\n",--jugador);
    else{
        printf("==>Empate\n\n");
    }
    return 0;
}

int checkForWin()
{
    int returnValue = 0;

    if (casilla[1] == casilla[2] && casilla[2] == casilla[3])
    {
        returnValue = 1;
    }
    else if (casilla[4] == casilla[5] && casilla[5] == casilla[6])
        returnValue = 1;

    else if (casilla[7] == casilla[8] && casilla[8] == casilla[9])
        returnValue = 1;

    else if (casilla[1] == casilla[4] && casilla[4] == casilla[7])
        returnValue = 1;

    else if (casilla[2] == casilla[5] && casilla[5] == casilla[8])
        returnValue = 1;

    else if (casilla[3] == casilla[6] && casilla[6] == casilla[9])
        returnValue = 1;

    else if (casilla[1] == casilla[5] && casilla[5] == casilla[9])
        returnValue = 1;

    else if (casilla[3] == casilla[5] && casilla[5] == casilla[7])
        returnValue = 1;

    else if (casilla[1] != '1' && casilla[2] != '2' && casilla[3] != '3' &&
        casilla[4] != '4' && casilla[5] != '5' && casilla[6] != '6' && casilla[7]
        != '7' && casilla[8] != '8' && casilla[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}


void displayBoard()
{
    system("cls");

    printf("\n\n\tTic Tac Toe\n\n");

    printf("Jugador 1 (X)  -  Jugador 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", casilla[1], casilla[2], casilla[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", casilla[4], casilla[5], casilla[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", casilla[7], casilla[8], casilla[9]);

    printf("     |     |     \n\n");
}

void markBoard(char bando)
{
    if (opcion == 1 && casilla[1] == '1')
        casilla[1] = bando;

    else if (opcion == 2 && casilla[2] == '2')
        casilla[2] = bando;

    else if (opcion == 3 && casilla[3] == '3')
        casilla[3] = bando;

    else if (opcion == 4 && casilla[4] == '4')
        casilla[4] = bando;

    else if (opcion == 5 && casilla[5] == '5')
        casilla[5] = bando;

    else if (opcion == 6 && casilla[6] == '6')
        casilla[6] = bando;

    else if (opcion == 7 && casilla[7] == '7')
        casilla[7] = bando;

    else if (opcion == 8 && casilla[8] == '8')
        casilla[8] = bando;

    else if (opcion == 9 && casilla[9] == '9')
        casilla[9] = bando;
    else
    {
        printf("Casilla ya usada ");

        jugador--;
    }
}
