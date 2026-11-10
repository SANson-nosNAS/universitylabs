#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int n, k, f;
double a, b, x, h;

double Sx(double x)
{
    double summres = 0;

    for (k = 1; k <= n; k++)
    {
        summres += pow(-1, k + 1) * (pow(x, 2 * k)) / (2 * k * (2 * k - 1));
    }

    return summres;
}

double Yx(double x)
{
    double result;
    result = x * atan(x) - log(pow(1 + pow(x, 2), 0.5));
    return result;
}

double YX()
{
    return fabs(Yx(x) - Sx(x));
}

void OutRez(int f)
{
    if (f == 1)
    {
        cout << "Yx \n ";
        while (x <= b)
        {

            cout << Yx(x) << endl;

            x += h;
        }
    }
    else if (f == 2)
    {
        cout << "Sx \n ";
        while (x <= b)
        {

            cout << Sx(x) << endl;

            x += h;
        }
    }
    else if (f == 3)
    {
        cout << "|Y(x) - S(x)|\n ";
        while (x <= b)
        {

            cout << YX() << endl;

            x += h;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "russian");
    cout << "Введите значение a = ";
    cin >> a;

    cout << "Введите значение b = ";
    cin >> b;

    cout << "Введите значение h = ";
    cin >> h;

    cout << "Введите значение n = ";
    cin >> n;

    cout << "Выберите функцию f: \n 1) Yx \n 2) Sx \n 3) |Yx - Sx| \n";
    cin >> f;

    x = a;

    OutRez(f);

    return 0;
}
