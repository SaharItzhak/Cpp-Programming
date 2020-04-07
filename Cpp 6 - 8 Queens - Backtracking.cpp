
#include <iostream>
#include <conio.h>

//------------------------------------------------
using std::cout;
using std::endl;
//------------------------------------------------
const int SIZE = 4;
//------------------------------------------------
void queens(bool board[][SIZE], int num_of_queens);
bool consistent(const bool board[][SIZE], int row, int col);
void print(const bool board[][SIZE]);
//------------------------------------------------

int main() {
    bool board[SIZE][SIZE] = { { false } };

    queens(board, 0);

    std::cin.get();   // (*)
    return EXIT_SUCCESS;
}
//------------------------------------------------
void queens(bool board[][SIZE], int num_of_queens) {
    for (int i = 0; i < SIZE; i++) {
        board[num_of_queens][i] = true;
        if (consistent(board, num_of_queens, i))
            if (num_of_queens == SIZE - 1)
                print(board);
            else
                queens(board, num_of_queens + 1);
        board[num_of_queens][i] = false; //(-)
    }
}
//------------------------------------------------
bool consistent(const bool board[][SIZE], int row, int col) {
    for (int temp = row - 1; temp >= 0; temp--)
        if (board[temp][col])
            return false;
    for (int tempr = row - 1, tempc = col - 1;
        tempr >= 0 && tempc >= 0; tempr - , tempc - )
        if (board[tempr][tempc])
            return false;
    for (int tempr = row - 1, tempc = col + 1;
        tempr >= 0 && tempc < SIZE; tempr--, tempc++)
        if (board[tempr][tempc])
            return false;

    return true;
}
//------------------------------------------------
void print(const bool board[][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++)
            cout << ((board[row][col]) ? "+ " : "- ");
        cout << endl;
    }
    cout << "----- " << endl;
}