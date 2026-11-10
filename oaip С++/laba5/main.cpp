#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    int m, n, i;
    double sum = 0;
    cout << "Введите количество символов в массиве: \n";
    cin >> n;
    cout << "Каким способом создать массив?\n1. C клавиатуры\n2. Рандомные числа \n";
    cin >> m;
    double a[n];

    switch (m)
    {
    case 1:
        cout << "Массив: \n";

        for (i = 0; i < n; i++)
        {
            cout << "Введите " << i << " элемент массива\n";
            cin >> a[i];
        }

        for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        break;

    case 2:
        cout << "Массив: \n";

        for (i = 0; i < n; i++)
        {
            a[i] = rand();
            cout << a[i] << " ";
        }
        break;
    }

    int firstZeroIndex = -1;
    int lastZeroIndex = -1;

    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (firstZeroIndex == -1)
            {
                firstZeroIndex = i;
            }
            lastZeroIndex = i;
        }
    }

    if (firstZeroIndex == -1 || firstZeroIndex == lastZeroIndex)
    {
        cout << "\nСуммы между нулевыми элементами нету.";
        return 0;
    }

    for (i = firstZeroIndex + 1; i < lastZeroIndex; ++i)
    {
        sum += a[i];
    }

    cout << "\nСумма элементов массива, расположенных между первым и последним нулевыми элементами:\n";
    cout << sum;

    return 0;
}
