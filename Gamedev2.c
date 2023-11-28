
#include <stdio.h>

void draw_board(char board[9]) {
    printf("%c|%c|%c\n", board[0], board[1], board[2]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", board[3], board[4], board[5]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", board[6], board[7], board[8]);
}

int check_win(char board[9]) {
    //write the code for checking win condition for both players.
    //for rows
    if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=' ')return 1;
    else if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=' ')return 1;
    else if(board[6]==board[7]&&board[7]==board[8]&&board[7]!=' ')return 1;
    //coloumns
    else if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=' ')return 1;
    else if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=' ')return 1;
    else if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=' ')return 1;
    //diagonals
    else if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=' ')return 1;
    else if(board[2]==board[4]&&board[4]==board[6]&&board[2]!=' ')return 1;

    else return 0;
}

int check_tie(char board[9]) {
        //check the condition for tie in the game.
        int new=9;
   for(int i=0;i<9;i++){
       if(board[i] == ' ')new--;
       else continue;
   }
   if(new==8 || new==9) {printf("%d",new); return 1;}
   else return 0;
}

int get_move(char player, char board[9]) {
    int valid_move = 0;
    int move;
    while (!valid_move) {
        printf("Player %c, enter a valid move (0-8): ", player);
        scanf("%d", &move);
        if (move >= 0 && move < 9 && board[move] == ' ') {
            valid_move = 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    return move;
}

void play_game() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char players[2] = {'X', 'O'};
    char current_player = players[0];
    int winner = 0;
    int tie = 0;

    while (!winner && !tie) {
        draw_board(board);
        int move = get_move(current_player, board);
        board[move] = current_player;
        if (check_win(board)) {
            winner = 1;
            printf("Player %c has won the game!\n", current_player);
        } else 
        if (check_tie(board)) {
            tie = 1;
            printf("The game is a tie!\n");
        } else {
            current_player = (current_player == players[0]) ? players[1] : players[0];
        }
    }
    draw_board(board);
}

int main() {
    play_game();
    printf("Congratulations");
    return 0;
}