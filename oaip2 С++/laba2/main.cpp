#include <iostream>
#include <windows.h>
using namespace std;

struct date
{
    int dd;
    int mm;
    int yy;
};

struct sklad
{
    char name[30];
    int num;
    double price;
    date d;
};

void quicksort(sklad *mas, int first, int last)
{
    int mid;
    sklad count;
    int f = first, l = last;
    mid = mas[(f + l) / 2].name[0]; // вычисление опорного элемента
    do
    {
        while (mas[f].name[0] < mid)
            f++;
        while (mas[l].name[0] > mid)
            l--;
        if (f <= l) // перестановка элементов
        {
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l)
        quicksort(mas, first, l);
    if (f < last)
        quicksort(mas, f, last);
}

void search(sklad *arr, date currentDate, int N)
{
    cout << endl
         << "Товары которые соответствуют: " << endl;

    for (int i = 0; i < N; i++)
    {
        if (arr[i].price * arr[i].num > 100000)
        {
            if (currentDate.yy > arr[i].d.yy)

                cout << arr[i].name << endl;

            else
            {
                if (currentDate.yy == arr[i].d.yy && currentDate.mm > arr[i].d.mm && currentDate.dd > arr[i].d.dd)
                {
                    cout << arr[i].name << endl;
                }
            }
        }
    }
}

void set(sklad *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].name;
        cin >> arr[i].num;
        cin >> arr[i].price;
        cin >> arr[i].d.dd;
        cin >> arr[i].d.mm;
        cin >> arr[i].d.yy;
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    sklad ar[50];

    int N = 4;

    date currentDate;

    currentDate.dd = 5;
    currentDate.mm = 11;
    currentDate.yy = 2021;

    set(ar, N);

    quicksort(ar, 0, N - 1);

    search(ar, currentDate, N);

    return 0;
}
