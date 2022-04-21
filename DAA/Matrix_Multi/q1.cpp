#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int row = 32, col = 32;
    int a[row][col], b[row][col], mul[row][col] ;

    cout << "First matrix:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            a[i][j] = rand() % 10;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\nSecond matrix:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            b[i][j] = rand() % 10;
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\nMultiplcation :- \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < col; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mul[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}