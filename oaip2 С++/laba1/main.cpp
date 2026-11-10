#include <iostream>
#include <windows.h>
using namespace std;

// Класс Mildew для моделирования роста и отмирания плесени
class Mildew
{
private:
    int *speed;       // Указатель на прирост плесени в день
    int *day;         // Указатель на количество дней
    int *percentage;  // Указатель на начальное количество плесени
    int *death_speed; // Указатель на скорость отмирания плесени в день

public:
    // Конструктор без параметров
    Mildew();

    // Конструктор с параметрами
    Mildew(int s, int d, int p, int ds);

    // Деструктор
    ~Mildew();

    // Метод для установки новых значений
    void set(int s, int d, int p, int ds);

    // Метод для просмотра текущих значений полей
    void display();

    // Метод для вычисления количества плесени через заданное время
    int calculateMildew();
};

// Реализация конструктора без параметров
Mildew::Mildew()
{
    // Выделение памяти под указатели
    speed = new int(5);       // Значение по умолчанию
    day = new int(1);         // Значение по умолчанию
    percentage = new int(50); // Значение по умолчанию
    death_speed = new int(0); // Значение по умолчанию
}

// Реализация конструктора с параметрами
Mildew::Mildew(int s, int d, int p, int ds)
{
    // Выделение памяти и инициализация значениями параметров
    speed = new int(s);
    day = new int(d);
    percentage = new int(p);
    death_speed = new int(ds);
}

// Реализация деструктора
Mildew::~Mildew()
{
    // Освобождение всей занятой памяти
    delete speed;
    delete day;
    delete percentage;
    delete death_speed;

    // Обнуление указателей (хорошая практика)
    speed = nullptr;
    day = nullptr;
    percentage = nullptr;
    death_speed = nullptr;

    cout << "Память освобождена в деструкторе" << endl;
}

// Реализация метода set
void Mildew::set(int s, int d, int p, int ds)
{
    // Установка новых значений для полей класса
    *speed = s;
    *day = d;
    *percentage = p;
    *death_speed = ds;
}

// Реализация метода display
void Mildew::display()
{
    cout << "Начальное количество плесени: " << *percentage << "%" << endl;
    cout << "Прирост плесени в день: " << *speed << "%" << endl;
    cout << "Количество дней: " << *day << endl;
    cout << "Отмирание плесени в день: " << *death_speed << "%" << endl;
}

// Реализация метода calculateMildew
int Mildew::calculateMildew()
{
    // Расчет общего количества плесени с учетом прироста и отмирания
    int total = *percentage + (*speed - *death_speed) * *day;
    // Проверка на отрицательное значение
    return total > 0 ? total : 0;
}

int main()
{
    // Установка русской локали для Windows
    setlocale(LC_ALL, "Russian");

    cout << "  Исследование плесени - Лабораторная работа 2  " << endl;
    cout << "Научно-практический центр исследований 'Explore all you want'" << endl
         << endl;

    // Демонстрация работы конструктора без параметров
    Mildew mold1; // Создание объекта с конструктором без параметров
    cout << "Первый эксперимент (конструктор без параметров):" << endl;
    mold1.display();
    cout << "Количество плесени: " << mold1.calculateMildew() << "%" << endl
         << endl;

    // Демонстрация работы конструктора с параметрами
    Mildew mold2(10, 5, 100, 2); // Создание объекта с конструктором с параметрами
    cout << "Второй эксперимент (конструктор с параметрами):" << endl;
    mold2.display();
    cout << "Количество плесени через " << 5 << " дней: " << mold2.calculateMildew() << "%" << endl
         << endl;

    // Демонстрация работы метода set
    cout << "Третий эксперимент (использование метода set):" << endl;
    mold1.set(15, 3, 200, 5); // Изменение значений через метод set
    mold1.display();
    cout << "Количество плесени через " << 3 << " дней: " << mold1.calculateMildew() << "%" << endl
         << endl;

    // Работа с динамической памятью через указатели
    cout << "Четвертый эксперимент (динамическое выделение памяти):" << endl;
    Mildew *moldPtr = new Mildew(8, 7, 150, 3); // Динамическое создание объекта
    moldPtr->display();
    cout << "Количество плесени через " << 7 << " дней: " << moldPtr->calculateMildew() << "%" << endl;

    // Освобождение динамически выделенной памяти
    delete moldPtr;

    cout << "\nИсследование завершено" << endl;

    return 0; // Завершение программы (деструкторы вызываются автоматически)
}

/*#include <iostream>
using namespace std;

int usfunc(int arr[], int n, int c)
{
    int left = 0;
    int right = n - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == c)
        {
            return mid;
        }
        if (arr[mid] < c)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int recfunc(int arr[], int left, int right, int c)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == c)
        {
            return mid;
        }
        if (arr[mid] < c)
        {
            return recfunc(arr, mid + 1, right, c);
        }
        else
        {
            return recfunc(arr, left, mid - 1, c);
        }
    }
    return -1;
}

int main()
{
    setlocale(LC_ALL, "russian");
    int n, c;

    cout << "Введите n: ";
    cin >> n;

    int arr[n];

    cout << "Массив: \n";

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        cout << arr[i] << " ";
    }

    cout << "\n";

    cout << "Введите элемент для поиска: ";
    cin >> c;

    int resultIterative = usfunc(arr, n, c);
    if (resultIterative != -1)
    {
        cout << "Элемент " << c << " найден на позиции: " << resultIterative << endl;
    }
    else
    {
        cout << "Элемент " << c << " не найден." << endl;
    }

    // Рекурсивный поиск
    int resultRecursive = recfunc(arr, 0, n - 1, c);
    if (resultRecursive != -1)
    {
        cout << "Элемент " << c << " найден на позиции: " << resultRecursive << endl;
    }
    else
    {
        cout << "Элемент " << c << " не найден." << endl;
    }

    return 0;
}
*/