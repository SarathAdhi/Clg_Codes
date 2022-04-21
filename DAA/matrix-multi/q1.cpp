#include <iostream>

using namespace std;

void MatrixCMul(int p[], int n){

    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++){
        for (i = 1; i < n - L + 1; i++){
            j = i + L - 1;
            m[i][j] = 1000000000;

            for (k = i; k <= j - 1; k++){
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    cout << m[1][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MatrixCMul(arr, n);
    return 0;
}