#include <stdbool.h>
#include <stdio.h>
#include <iostream>

int N;
using namespace std;
void Display(int board[100][100], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

bool Possible(int board[100][100], int r, int c)
{
    int i, j;

    for (i = 0; i < c; i++)
        if (board[r][i])
            return false;

    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = r, j = c; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool Queens(int board[100][100], int c, int N)
{

    if (c >= N)
        return true;

    for (int i = 0; i < N; i++)
    {

        if (Possible(board, i, c))
        {

            board[i][c] = 1;

            if (Queens(board, c + 1, N))
                return true;

            board[i][c] = 0;
        }
    }

    return false;
}

bool SolveN_Q()
{
    int N;
    cin >> N;
    int board[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (Queens(board, 0, N) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
    if (N == 1)

    {
        cout << "1" << endl;
        cout << "Completed";
    }
    else
    {
        Display(board, N);
        cout << "Completed";
        return true;
    }
}

int main()
{
    SolveN_Q();
    return 0;
}