#include <stdio.h>
#include <stdlib.h>

int drawBoard(char array[]) {

    printf("=====\n");
    printf("%s",array);
    printf("=====\n\n");
}

int checkForWin(char array[], int playerNum) {

    if (array[0] == array[2] && array[0] == array[4]){
        printf("\nPlayer %d Wins!!\n", playerNum);
        return 1;
    }
    if (array[12] == array[14] && array[12] == array[16]){
        printf("\nPlayer %d Wins!!\n", playerNum);
        return 1;
    }
    if (array[24] == array[26] && array[24] == array[28]){
        printf("\nPlayer %d Wins!!\n", playerNum);
        return 1;
    }
    if (array[0] == array[12] && array[0] == array[24]){
        printf("\nPlayer %d Wins!!\n", playerNum);
        return 1;
    }
    if (array[2] == array[14] && array[2] == array[26]){
        printf("\nPlayer %d Wins!!\n", playerNum);
        return 1;
    }
    if (array[4] == array[16] && array[4] == array[28]){
        printf("\nPlayer %d Wins!!\n", playerNum);
        return 1;
    }
    if (array[0] == array[14] && array[0] == array[28]){
        printf("\nPlayer %d Wins!!\n", playerNum);
        return 1;
    }
    if (array[4] == array[14] && array[4] == array[24]){
        printf("\nPlayer %d Wins!!\n", playerNum);
        return 1;
    }
}

int play(char array[],int playerNum) {

    int move, toReplace;
    int strikes = 0;
    int spots[9] = {0, 2, 4, 12, 14, 16, 24, 26 ,28};

    smartAssReTrun:

    drawBoard(array);
    printf("Player %d type a location : ", playerNum);
    scanf("%d",&move);
    if (0 > move || move < 10) {
        toReplace = spots[move - 1];
        
        if (playerNum == 2 && array[toReplace] != 'X')
            array[toReplace] = 'O';

        else if (playerNum == 1 && array[toReplace] != 'O')
            array[toReplace] = 'X';

        else if (strikes == 0) {
            printf("\nYou MOTH*RFUCKER, you can't put it in here, choose other place\nAnd don't be a smart ass this time\n\n");
            strikes++;
            goto smartAssReTrun;
        }

        else if (strikes == 1) {
            printf("\nHoo, come on, try me one more time\n\n");
            strikes++;
            goto smartAssReTrun;
        }

        else if (strikes == 2) {

            char winnerChar = 'H';

            if (playerNum == 1) {
                winnerChar = 'X';
                playerNum = 2;
            }

            else {
                winnerChar = 'O';
                playerNum = 1;
            }

            for (int i = 0; i < 9; i++)
                array[spots[i]] = winnerChar;
        }
    }
    else {
        printf("\n Please choose number between 1-9 you MOTHERF*CKER\n\n");
        goto smartAssReTrun;
    }
}

int main() {

    printf("\tThis is a TicTacToe game:\n\tPlayer 1(X) Vs. Player 2(O)\n");
    static char board[30] = {
    '1','|','2','|','3','\n',
    '-','-','-','-','-','\n',
    '4','|','5','|','6','\n',
    '-','-','-','-','-','\n',
    '7','|','8','|','9','\n',
    };
    for (int turn = 1; turn <= 9; turn ++) {

        int playerNum;
        if (turn % 2 == 0)
            playerNum = 2;
        else
            playerNum = 1;

        play(board, playerNum);
        if (checkForWin(board, playerNum) == 1)
            goto end;
    }
    end:
        drawBoard(board);
        return 0;
}

