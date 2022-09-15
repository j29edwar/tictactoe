//Tic Tac Toe Game in C++

#include <iostream>
#include <stdlib.h>
using namespace std;

// Board 2D array
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int turn = 1;
int row, column, choice;
bool in_game = true;
bool draw = false;

// Displays board
void player_board() {
    cout << "= = = = =" << endl;
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "- - - - -" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "- - - - -" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void play_turn(){
    if(turn == 1){
        cout << "Player 1's turn [O] : " << endl;
    }   
    else if(turn == 2){
        cout << "Player 2's turn [X] : " << endl;
    }


    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: 
            row = 0;
            column = 0; 
            break;
        case 2: 
            row = 0; 
            column = 1; 
            break;
        case 3: 
            row = 0; 
            column = 2; 
            break;
        case 4: 
            row = 1; 
            column = 0; 
            break;
        case 5: 
            row = 1; 
            column = 1; 
            break;
        case 6: 
            row = 1; 
            column = 2; 
            break;
        case 7: 
            row = 2; 
            column = 0; 
            break;
        case 8: 
            row = 2; 
            column = 1; 
            break;
        case 9: 
            row = 2; 
            column = 2; 
            break;
        default:
            cout << "invalid move" << endl;
            player_board();
            play_turn();
            return;
    }

    if (turn == 1 && board[row][column] != 'O' && board[row][column] != 'X') {
        board[row][column] = 'O';
        turn = 2;
    } else if (turn == 2 && board[row][column] != 'O' && board[row][column] != 'X') {
        board[row][column] = 'X';
        turn = 1;
    } else {
        cout << "Box is filled, enter another number" << endl;
        play_turn();
    }
    player_board();
}

bool end_game(){
    for(int i=0; i<3; i++) {
        if( (board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i]) )
            return false;
    }

    if( (board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]) )
        return false;
    

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] != 'O' && board[i][j] != 'X')
                return true;
        }
    }
    
    draw = true;
    return true;
}


int main()
{
    while (in_game) {
        player_board();
        play_turn();
        in_game = end_game();
    }
    if (turn == 2 && draw == false) {
        cout<<"Player 1 wins";
    } else if (turn == 1 && draw == false) {
        cout<<"Player 2 wins";
    } else {
        cout<<"Draw";
    }
} 
