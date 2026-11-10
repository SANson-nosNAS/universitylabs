#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int n, k;
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

    cout << setw(20) << "№" << setw(20) << "x" << setw(20) << "S(x)" << setw(20) << "Y(x)" << setw(23) << "|Y(x) - S(x)|" << endl;

    x = a;
    int num = 1;

    while (x <= b)
    {

        cout << setw(20) << num << setw(20) << x << setw(20) << Sx(x) << setw(20) << Yx(x) << setw(20) << fabs(Yx(x) - Sx(x)) << endl;

        x += h;

        num++;
    }

    return 0;
}