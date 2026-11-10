#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

class Garden
{

private:
    int rows;
    int cols;
    int **plants; // указатель на указатель - для двумерного динамического массива

public:
    Garden(int n, int m)
    {
        rows = n;
        cols = m;
        plants = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            plants[i] = new int[cols]; // каждый plants[i] - массив из 'cols' элементов
        }

        srand(time(0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                plants[i][j] = rand() % 101;
            }
        }
        cout << "Создан сад размером " << rows << "x" << cols << endl;
    }

    ~Garden()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] plants[i];
        }
        delete[] plants;

        cout << "Память сада освобождена." << endl;
    }

    friend void run(const Garden &g);                               // для подсчета растений
    friend void printMatrix(const Garden &g);                       // для вывода массива
    friend void setElement(Garden &g, int row, int col, int value); // для изменения элемента
};

void run(const Garden &g)
{
    int total = 0;

    for (int i = 0; i < g.rows; i++)
    {
        for (int j = 0; j < g.cols; j++)
        {
            total += g.plants[i][j];
        }
    }
    cout << "Общее количество растений в поле: " << total << endl;
}

// ОПРЕДЕЛЕНИЕ ДРУЖЕСТВЕННОЙ ФУНКЦИИ printMatrix
void printMatrix(const Garden &g)
{
    cout << "Текущее состояние поля:" << endl;
    for (int i = 0; i < g.rows; i++)
    {
        for (int j = 0; j < g.cols; j++)
        {
            cout << g.plants[i][j] << "\t";
        }
        cout << endl;
    }
}

// ОПРЕДЕЛЕНИЕ ДРУЖЕСТВЕННОЙ ФУНКЦИИ setElement
void setElement(Garden &g, int row, int col, int value)
{
    if (row >= 0 && row < g.rows && col >= 0 && col < g.cols)
    {
        g.plants[row][col] = value;
        cout << "Значение в ячейке [" << row << "][" << col << "] установлено в " << value << endl;
    }
    else
    {
        cout << "Ошибка: неверные координаты!" << endl;
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n, m;
    cout << "Введите размеры поля (N M): ";
    cin >> n >> m;

    Garden myGarden(n, m); // вызов конструктора

    cout << "\n Результаты работы " << endl;

    printMatrix(myGarden);
    run(myGarden); // подсчет общего количества растений

    cout << "\n Демонстрация изменения элемента " << endl;

    setElement(myGarden, 0, 0, 50); // меняем элемент [1][1] на значение 50
    printMatrix(myGarden);
    run(myGarden);

    cout << "\nПрограмма завершена." << endl;
    return 0;
}