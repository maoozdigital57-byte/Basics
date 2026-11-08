#include <iostream>
using namespace std;

void display(char A[3][3]) {
    cout << "\n\tT i c k C r o s s\n";
    cout << "----------------------------------------\n\n";
    cout << "Player1 [X]\n";
    cout << "Player2 [O]\n";

    cout << "\t\t    |    |   \n";
    cout << "\t\t  " << A[0][0] << " | " << A[0][1] << "  | " << A[0][2] << " \n";
    cout << "\t\t____|__ _|___\n";
    cout << "\t\t    |    |   \n";
    cout << "\t\t  " << A[1][0] << " | " << A[1][1] << "  | " << A[1][2] << " \n";
    cout << "\t\t____|__ _|___\n";
    cout << "\t\t    |    |   \n";
    cout << "\t\t  " << A[2][0] << " | " << A[2][1] << "  | " << A[2][2] << " \n";
    cout << "\t\t    |    |   \n";
}

void player_turn(char A[3][3], char turn) {
    int choice;
    while (true) {
        if (turn == 'X')
            cout << "\n\tPlayer1 [X] turn : ";
        else
            cout << "\n\tPlayer2 [O] turn : ";

        cin >> choice;

        // agar number ki jagah harf likh diya
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\tSirf number likhein (1-9)\n";
            continue;
        }

        if (choice < 1 || choice > 9) {
            cout << "\tInvalid Move! 1 se 9 tak likhein\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (A[row][col] == 'X' || A[row][col] == 'O') {
            cout << "\tYe jagah pehle se bhari hui hai!\n";
            continue;
        }

        A[row][col] = turn;
        break;
    }
}

bool checkWin(char A[3][3], char turn) {
    for (int i = 0; i < 3; i++) {
        // rows
        if (A[i][0] == turn && A[i][1] == turn && A[i][2] == turn) return true;
        // columns
        if (A[0][i] == turn && A[1][i] == turn && A[2][i] == turn) return true;
    }
    // diagonals
    if (A[0][0] == turn && A[1][1] == turn && A[2][2] == turn) return true;
    if (A[0][2] == turn && A[1][1] == turn && A[2][0] == turn) return true;
    return false;
}

bool checkDraw(char A[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (A[i][j] != 'X' && A[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char A[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    char turn = 'X';

    while (true) {
        display(A);
        player_turn(A, turn);

        if (checkWin(A, turn)) {
            display(A);
            if (turn == 'X')
                cout << "\n\tPlayer1 [X] jeet gaya!\n";
            else
                cout << "\n\tPlayer2 [O] jeet gaya!\n";
            break;
        }

        if (checkDraw(A)) {
            display(A);
            cout << "\n\tGame draw ho gayi!\n";
            break;
        }

        // turn badlo
        turn = (turn == 'X') ? 'O' : 'X';
    }

    return 0;
}