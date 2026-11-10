#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");

    int rows, colums, k;
    double a;

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> colums;

    int *B = new int[rows];
    double **arr = new double *[rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new double[colums];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            cout << "Введите элемент " << i << " строки " << j << " столбца: ";
            cin >> a;
            arr[i][j] = a;
        }
    }
    cout << endl;

    cout << "Массив:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j + 1 < colums; j++)
        {
            if (arr[i][j] > arr[i][j + 1])
            {
                k = 1;
            }
            else
            {
                k = 0;
                break;
            }
        }
        if (k == 1)
        {
            B[i] = 1;
        }
        else
        {
            B[i] = 0;
        }
    }

    cout << "Вектор B:\n";
    for (int i = 0; i < rows; i++)
    {
        cout << B[i] << "\t";
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] B;
    return 0;
}