#include <iostream>
#include <string>
#include <vector>

using namespace std;
int boardcnt = 0;

bool IsBoardOk(vector<string> &Board, int row, int col)
{

    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--)
    {
        if (Board[r][c] == '1')
        {
            return false;
        }
    }
    for (int r = row + 1, c = col - 1; c >= 0 && r < Board.size(); r++, c--)
    {
        if (Board[r][c] == '1')
        {
            return false;
        }
    }
    for (int c = 0; c < col; c++)
    {
        if (Board[row][c] == '1')
        {
            return false;
        }
    }

    return true;
}

void DisplayBoard(vector<string> &Board)
{
    int x = 0, y = 0;
    for (auto &row : Board)
    {
        for (auto &ch : row)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void PlaceQueens(vector<string> &Board, int col)
{

    if (col >= Board.size())
    {

        DisplayBoard(Board);
        cout << "Completed " << ++boardcnt << endl;
    }
    else
    {

        for (int row = 0; row < Board.size(); row++)
        {

            Board[row][col] = '1';

            if (IsBoardOk(Board, row, col) == true)
            {
                PlaceQueens(Board, col + 1);
            }

            Board[row][col] = '0';
        }
    }
}

int main()
{

    vector<string> Board;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string row("0", N);
        Board.push_back(row);
    }

    PlaceQueens(Board, 0);

    return 0;
}