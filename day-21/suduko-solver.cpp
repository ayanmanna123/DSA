#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
    for (int i = 0; i < 9; i++) {
        // Row check
        if (board[row][i] == val)
            return false;

        // Column check
        if (board[i][col] == val)
            return false;

        // 3x3 subgrid check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char val = '1'; val <= '9'; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;

                        
                        bool aageSolutionPossible = solve(board);
                        if (aageSolutionPossible)
                            return true;
                        else
                            board[row][col] = '.'; 
                    }
                }
                return false;  
            }
        }
    }
    return true;  
}

void printBoard(const vector<vector<char>>& board) {
    for (auto row : board) {
        for (auto ch : row)
            cout << ch << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (solve(board)) {
        cout << "Sudoku solved successfully:\n";
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
