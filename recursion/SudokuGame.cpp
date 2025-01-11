#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        Sudoku(board);
    }
    bool Sudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isSudoku(board, i, j, c))
                        {
                            board[i][j] = c;
                            if (Sudoku(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isSudoku(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
            {
                return false;
            }
            if (board[row][i] == c)
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution solution;
    vector<vector<char>> board(9, vector<char>(9));
    // Taking user input for the Sudoku board
    cout << "Enter the Sudoku board (use '.' for empty cells):" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "Row " << i + 1 << ", Column " << j + 1 << ": ";
            cin >> board[i][j];
        }
    }
    solution.solveSudoku(board);
    // Displaying the solved Sudoku board
    cout << "Solved Sudoku:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
