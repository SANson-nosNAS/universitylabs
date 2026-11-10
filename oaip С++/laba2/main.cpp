#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    double a, b, y, f, z, x;
    int c;

    cout << "Введите z\n";
    cin >> z;
    cout << "Введите a\n";
    cin >> a;
    cout << "Введите b\n";
    cin >> b;
    cout << "Выберете f:\n 1: f= x * 3\n 2: f= x^2\n 3: f = x / 3\n";
    cin >> c;

    if (z < 1)
    {
        x = 2 + z;
        cout << "Так как Z меньше единицы, то выполняется выражениие Z+2\n";
    }
    else if (z >= 1)
    {
        x = pow(sin(z), 2);
        cout << "Так как Z больше либо равно единице, то выполняется выражениие sin^2Z\n";
    }

    switch (c)
    {
    case 1:
        f = 2 * x;
        break; // cmath
    case 2:
        f = pow(x, 2);
        break;
    case 3:
        f = x / 3;
        break;
    }

    y = (2 * a * f + b * cos(pow(fabs(x), 0.5))) / (pow(x, 2) + 5);

    cout << "При значении функции f = " << f << "\nОтвет: " << y;
    return 0;
}