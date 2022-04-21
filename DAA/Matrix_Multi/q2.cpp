#include <stdlib.h>
#include <iostream>
using namespace std;

void add(int **a, int **b, int **c, int n){

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
}
void mul(int **a, int **b, int **c, int n){

    if (n == 1){
        c[0][0] = a[0][0] * b[0][0];
    }
    else{
        int **a11 = new int *[(n / 2)];
        int **a12 = new int *[(n / 2)];
        int **a21 = new int *[(n / 2)];
        int **a22 = new int *[(n / 2)];
        int **b11 = new int *[(n / 2)];
        int **b12 = new int *[(n / 2)];
        int **b21 = new int *[(n / 2)];
        int **b22 = new int *[(n / 2)];
        int **c11 = new int *[(n / 2)];
        int **c12 = new int *[(n / 2)];
        int **c21 = new int *[(n / 2)];
        int **c22 = new int *[(n / 2)];
        int **temp1 = new int *[(n / 2)];
        int **temp2 = new int *[(n / 2)];

        for (int i = 0; i < (n / 2); i++){

            a11[i] = new int[(n / 2)];
            a12[i] = new int[(n / 2)];
            a21[i] = new int[(n / 2)];
            a22[i] = new int[(n / 2)];
            b11[i] = new int[(n / 2)];
            b12[i] = new int[(n / 2)];
            b21[i] = new int[(n / 2)];
            b22[i] = new int[(n / 2)];
            c11[i] = new int[(n / 2)];
            c12[i] = new int[(n / 2)];
            c21[i] = new int[(n / 2)];
            c22[i] = new int[(n / 2)];
            temp1[i] = new int[(n / 2)];
            temp2[i] = new int[(n / 2)];
        }

        for (int i = 0; i < (n / 2); i++){
            for (int j = 0; j < (n / 2); j++){

                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j + (n / 2)];
                a21[i][j] = a[i + (n / 2)][j];
                a22[i][j] = a[i + (n / 2)][j + (n / 2)];

                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j + (n / 2)];
                b21[i][j] = b[i + (n / 2)][j];
                b22[i][j] = b[i + (n / 2)][j + (n / 2)];
            }
        }

        mul(a11, b11, temp1, (n / 2));
        mul(a12, b21, temp2, (n / 2));
        add(temp1, temp2, c11, (n / 2));
        mul(a11, b12, temp1, (n / 2));
        mul(a12, b22, temp2, (n / 2));
        add(temp1, temp2, c12, (n / 2));
        mul(a21, b11, temp1, (n / 2));
        mul(a22, b21, temp2, (n / 2));
        add(temp1, temp2, c21, (n / 2));
        mul(a21, b12, temp1, (n / 2));
        mul(a22, b22, temp2, (n / 2));
        add(temp1, temp2, c22, (n / 2));

        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n / 2; j++)
            {
                c[i][j] = c11[i][j];
                c[i][j + (n / 2)] = c12[i][j];
                c[i + (n / 2)][j] = c21[i][j];
                c[i + (n / 2)][j + (n / 2)] = c22[i][j];
            }
        }

        for (int i = 0; i < (n / 2); i++)
        {
            delete[] a11[i];
            delete[] a12[i];
            delete[] a21[i];
            delete[] a22[i];
            delete[] b11[i];
            delete[] b12[i];
            delete[] b21[i];
            delete[] b22[i];
            delete[] c11[i];
            delete[] c12[i];
            delete[] c21[i];
            delete[] c22[i];

            delete[] temp1[i];
            delete[] temp2[i];
        }
    }
}
void printArr(int **array, int n)
{
    int i;
    int j;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
}

int main(){
    int **arr1;
    int **arr2;
    int **arr3;
    int n = 32;
    arr1 = (int **)malloc(n * sizeof(int *));
    arr2 = (int **)malloc(n * sizeof(int *));
    arr3 = (int **)malloc(n * sizeof(int *));

    for (int row = 0; row < n; row++)
    {
        arr1[row] = (int *)malloc(n * sizeof(int));
        arr2[row] = (int *)malloc(n * sizeof(int));
        arr3[row] = (int *)malloc(n * sizeof(int));
    }
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            arr1[row][col] = rand() % 10;
        }
    }
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++){
            
            arr2[row][col] = rand() % 10;
        }
    }
    
    mul(arr1, arr2, arr3, n);
    cout << "Product Matrix:\n";

    printArr(arr3, n);
    return 0;
}