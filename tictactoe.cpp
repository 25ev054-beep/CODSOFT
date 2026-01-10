#include <windows.h>

// tell compiler that main() exists
int main();

// Windows entry point
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return main();
}


#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player = 'X';

void displayBoard() {
    cout << endl;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool win() {
    for(int i=0;i<3;i++)
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;

    for(int i=0;i<3;i++)
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;

    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;

    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}

int main() {
    int move;

    while(true) {
        displayBoard();
        cout << "Player " << player << ", enter move: ";
        cin >> move;

        int r = (move-1)/3;
        int c = (move-1)%3;

        if(board[r][c]=='X' || board[r][c]=='O') {
            cout << "Invalid move!\n";
            continue;
        }

        board[r][c] = player;

        if(win()) {
            displayBoard();
            cout << "🎉 Player " << player << " wins!\n";
            break;
        }

        player = (player=='X') ? 'O' : 'X';
    }
    return 0;
}
