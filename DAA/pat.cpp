// Consider a sequence of ‘n’ matrices <M1,M2,..,Mn>, where the matrix Mi is of dimension di-1*di. The sequence of ‘n’ matrices <M1,M2,..,Mn> must have “n+1”
// dimensions. Design and implement an algorithm that minimizes the number of multiplications required to perform matrix chain multiplication between the
// sequence of ‘n’ matrices with n+1 dimensions and print the optimal parenthesization for the sequence of dimensions and multiplication.
// Input:
// Dimensions
// <30 1 40 10 25>
// Output:

// 30*1=30, 40*10=400 10*25=250

// Cost Matrix 1
// 0   1200  700  1400
// 0     0   400  650
// 0     0    0   10000
// 0     0    0   0

// Distance Matrix  2
// 0 1 1 1
// 0 0 2 3
// 0 0 0 3
// 0 0 0 0

// Optimal Paranthesis  3
// (A*((B*C)*D))

// Multiplications  4
// 1400

// 0                166         64          0
// 3                 0         1200         700
// 70494208        32759        0           400
// 70497632        32759    70209895        0

#include <iostream>
#include <limits.h>

using namespace std;

void Optimal_Paranthesis(int i, int j, int n, int *brack, char &nam)
{
    if (i == j) {
        cout << nam++;
        return;
    }

    cout << "(";
    Optimal_Paranthesis(i, *((brack + i * n) + j), n, brack, nam);

    cout << "*";
    Optimal_Paranthesis(*((brack + i * n) + j) + 1, j, n, brack, nam);
    cout << ")";
    if (nam == 'A')
        cout << ")";
}

void MatrixCMul(int mat[], int n)
{
    int m[n][n], c[n][n];
    int L, q, count = 0;

    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;
        c[i][i] = 0;
    }

    for (L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX; // assigning to maximum value

            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + mat[i - 1] * mat[k] * mat[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    c[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i == j)
            {
                m[i][j] = 0;
                c[i][j] = 0;
            }
            if (i >= j)
            {
                m[i][j] = 0;
                c[i][j] = 0;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     m[i][1] = 0;
    //     m[n - 1][i] = 0;
    // }

    // Cost Matrix
    cout << "Cost Matrix" << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    // Distance Matrix
    cout << "Distance Matrix" << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Optimal Paranthesis" << endl;
    char nam = 'A';
    Optimal_Paranthesis(1, n - 1, n, (int *)c, nam);

    // Multiplication
    cout << endl << m[1][n - 1];
}

int main()
{
    int n = 4;
    // cin >> n;
    n++;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MatrixCMul(arr, n);
    return 0;
}