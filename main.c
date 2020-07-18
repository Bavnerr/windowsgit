#include <stdio.h>
#include <stdlib.h>

int drawBoard(char array[]);
int markbaord(char array[],int turn);
int checkForWin(char array[], int turn);

int main()
{
    int move;
    int turn = 1;
    printf("\tThis is a TicTacToe game:\n\tPlayer 1(X) Vs. Player 2(O)\n");
    static char board[30] = {
    '1','|','2','|','3','\n',
    '-','-','-','-','-','\n',
    '4','|','5','|','6','\n',
    '-','-','-','-','-','\n',
    '7','|','8','|','9','\n',
    };
    drawBoard(board);
    markbaord(board, turn);
    turn++;
    drawBoard(board);
    if (checkForWin(board, turn) == 1)
        goto end;
    markbaord(board, turn);
    turn--;
    drawBoard(board);
    markbaord(board, turn);
    if (checkForWin(board, turn) == 1)
        goto end;
    turn++;
    drawBoard(board);
    markbaord(board, turn);
    if (checkForWin(board, turn) == 1)
        goto end;
    turn--;
    drawBoard(board);
    markbaord(board, turn);
    if (checkForWin(board, turn) == 1)
        goto end;
    turn++;
    drawBoard(board);
    markbaord(board, turn);
    if (checkForWin(board, turn) == 1)
        goto end;
    turn--;
    drawBoard(board);
    markbaord(board, turn);
    if (checkForWin(board, turn) == 1)
        goto end;
    turn++;
    drawBoard(board);
    markbaord(board, turn);
    if (checkForWin(board, turn) == 1)
        goto end;
    turn--;
    drawBoard(board);
    markbaord(board, turn);
    if (checkForWin(board, turn) == 1)
        goto end;
    turn++;
    drawBoard(board);
    markbaord(board, turn);
    if (checkForWin(board, turn) == 1)
        goto end;

    end:
        drawBoard(board);
        return 0;
}

int drawBoard(char array[])
{
    printf("%s",array);
}

int checkForWin(char array[], int turn){
    if (array[0] == array[2] && array[0] == array[4]){
        printf("\nPlayer %d Wins!!\n", turn);
        return 1;
    }
    if (array[12] == array[14] && array[12] == array[16]){
        printf("\nPlayer %d Wins!!\n", turn);
        return 1;
    }
    if (array[24] == array[26] && array[24] == array[28]){
        printf("\nPlayer %d Wins!!\n", turn);
        return 1;
    }
    if (array[0] == array[12] && array[0] == array[24]){
        printf("\nPlayer %d Wins!!\n", turn);
        return 1;
    }
    if (array[2] == array[14] && array[2] == array[26]){
        printf("\nPlayer %d Wins!!\n", turn);
        return 1;
    }
    if (array[4] == array[16] && array[4] == array[28]){
        printf("\nPlayer %d Wins!!\n", turn);
        return 1;
    }
    if (array[0] == array[14] && array[0] == array[28]){
        printf("\nPlayer %d Wins!!\n", turn);
        return 1;
    }
    if (array[4] == array[14] && array[4] == array[24]){
        printf("\nPlayer %d Wins!!\n", turn);
        return 1;
    }
}

int markbaord(char array[],int turn)
{
    int move;
    printf("Player %d type a location:\n", turn);
    scanf("%d",&move);
    if (move == 1)
        move = 0;
    if (move == 2)
        move = 2;
    if (move == 3)
        move = 29;
    if (move == 4)
        move = 12;
    if (move == 5)
        move = 14;
    if (move == 6)
        move = 16;
    if (move == 7)
        move = 24;
    if (move == 8)
        move = 26;
    if (move == 9)
        move = 28;
    if (move == 29)
        move = 4;
    if (turn == 1)
        array[move] = 'X';
    if (turn == 2)
        array[move] = 'O';
}
