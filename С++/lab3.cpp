#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

class Stars
{
private:
    // Структура для хранения информации о звезде
    struct Star
    {
        double distance; // расстояние в парсеках
        string name;     // название звезды
        double size;     // размер звезды
    };

    Star *starsArray; // динамический массив звезд
    int size;         // размер массива

public:
    // Конструктор с параметром
    Stars(int arrSize) : size(arrSize)
    {
        // Выделяем память для массива звезд
        starsArray = new Star[size];

        // Инициализация генератора случайных чисел
        srand(time(0));

        // Заполнение массива данными
        for (int i = 0; i < size; i++)
        {
            // Генерация расстояния от 1 до 100000
            starsArray[i].distance = rand() % 100000 + 1;

            // Генерация размера от 1 до 100000
            starsArray[i].size = rand() % 100000 + 1;

            // Ввод названия звезды
            cout << "Введите название звезды " << i + 1 << ": ";
            cin >> starsArray[i].name;
        }
    }

    // Метод для просмотра текущего состояния массива
    void display()
    {
        cout << "Текущее состояние массива звезд" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Звезда " << i + 1 << ":" << endl;
            cout << "  Название: " << starsArray[i].name << endl;
            cout << "  Расстояние: " << starsArray[i].distance << " парсек" << endl;
            cout << "  Размер: " << starsArray[i].size << endl;
            cout << "-----------------------------------" << endl;
        }
    }

    // Метод run для вывода информации о звездах в диапазоне 400<distance<90000
    void run()
    {
        cout << "Звезды в диапазоне 400-90000 парсек" << endl;
        bool found = false;

        for (int i = 0; i < size; i++)
        {
            if (starsArray[i].distance > 400 && starsArray[i].distance < 90000)
            {
                cout << "Звезда: " << starsArray[i].name << endl;
                cout << "  Расстояние: " << starsArray[i].distance << " парсек" << endl;
                cout << "  Размер: " << starsArray[i].size << endl;
                cout << "-----------------------------------" << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "Звезд в заданном диапазоне не найдено!" << endl;
        }
    }

    // Деструктор
    ~Stars()
    {
        delete[] starsArray; // освобождаем память
        cout << "Память освобождена!" << endl;
    }
};

// Демонстрация работы класса
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int starCount;
    cout << "Введите количество звезд: ";
    cin >> starCount;

    // Создание объекта класса Stars
    Stars telescope(starCount);

    // Просмотр всего массива
    telescope.display();

    // Вывод звезд в заданном диапазоне
    telescope.run();

    return 0;
}