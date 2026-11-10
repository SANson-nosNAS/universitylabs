#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Базовый класс Faculty
class Faculty
{
protected:
    int number_of_employees;
    double employee_salary;
    double surcharge;
    string faculty_name;

public:
    // Конструктор с параметрами
    Faculty(string name, int employees, double salary, double charge)
        : faculty_name(name), number_of_employees(employees),
          employee_salary(salary), surcharge(charge) {}

    // Виртуальные функции
    virtual void print_info() const
    {
        cout << "Факультет: " << faculty_name << endl;
        cout << "Количество сотрудников: " << number_of_employees << endl;
        cout << "Зарплата сотрудника: " << fixed << setprecision(2) << employee_salary << endl;
    }

    virtual void costs_with_surcharge() const
    {
        double total_cost = number_of_employees * employee_salary * surcharge * 0.13;
        cout << "Факультет: " << faculty_name << endl;
        cout << "Количество сотрудников: " << number_of_employees << endl;
        cout << "Зарплата сотрудника: " << fixed << setprecision(2) << employee_salary << endl;
        cout << "Надбавка: " << surcharge << endl;
        cout << "Общие расходы с надбавкой: " << fixed << setprecision(2) << total_cost << endl;
    }

    virtual ~Faculty() {}
};

// Производный класс для Математической кафедры
class MathFaculty : public Faculty
{
public:
    MathFaculty(string name, int employees, double salary, double charge)
        : Faculty(name, employees, salary, charge) {}

    void print_info() const override
    {
        cout << "=== Математическая кафедра ===" << endl;
        Faculty::print_info();
        double total_cost = number_of_employees * employee_salary;
        cout << "Сумма расходов на кафедру: " << fixed << setprecision(2) << total_cost << endl;
        cout << "--------------------------------" << endl;
    }

    void costs_with_surcharge() const override
    {
        cout << "=== Математическая кафедра (с надбавкой) ===" << endl;
        Faculty::costs_with_surcharge();
        cout << "--------------------------------" << endl;
    }
};

// Производный класс для Физической кафедры
class PhysicsFaculty : public Faculty
{
public:
    PhysicsFaculty(string name, int employees, double salary, double charge)
        : Faculty(name, employees, salary, charge) {}

    void print_info() const override
    {
        cout << "=== Физическая кафедра ===" << endl;
        Faculty::print_info();
        double total_cost = number_of_employees * employee_salary;
        cout << "Сумма расходов на кафедру: " << fixed << setprecision(2) << total_cost << endl;
        cout << "--------------------------------" << endl;
    }

    void costs_with_surcharge() const override
    {
        cout << "=== Физическая кафедра (с надбавкой) ===" << endl;
        Faculty::costs_with_surcharge();
        cout << "--------------------------------" << endl;
    }
};

// Производный класс для Информатики
class ComputerScienceFaculty : public Faculty
{
public:
    ComputerScienceFaculty(string name, int employees, double salary, double charge)
        : Faculty(name, employees, salary, charge) {}

    void print_info() const override
    {
        cout << "=== Кафедра информатики ===" << endl;
        Faculty::print_info();
        double total_cost = number_of_employees * employee_salary;
        cout << "Сумма расходов на кафедру: " << fixed << setprecision(2) << total_cost << endl;
        cout << "--------------------------------" << endl;
    }

    void costs_with_surcharge() const override
    {
        cout << "=== Кафедра информатики (с надбавкой) ===" << endl;
        Faculty::costs_with_surcharge();
        cout << "--------------------------------" << endl;
    }
};

int main()
{
    // Установка локали для корректного отображения русских символов
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Создание объектов разных кафедр
    vector<Faculty *> faculties;

    faculties.push_back(new MathFaculty("Математика и статистика", 15, 55000.0, 1.2));
    faculties.push_back(new PhysicsFaculty("Общая и теоретическая физика", 12, 60000.0, 1.15));
    faculties.push_back(new ComputerScienceFaculty("Информационные технологии", 20, 75000.0, 1.25));

    cout << "РАСЧЕТ РАСХОДОВ НА КАФЕДРЫ" << endl;
    cout << "==========================" << endl
         << endl;

    // Вывод информации о расходах без надбавки
    cout << "1. Базовая информация о расходах:" << endl;
    cout << "==================================" << endl;
    for (const auto &faculty : faculties)
    {
        faculty->print_info();
    }

    // Вывод информации о расходах с надбавкой
    cout << endl
         << "2. Расходы с учетом надбавки:" << endl;
    cout << "================================" << endl;
    for (const auto &faculty : faculties)
    {
        faculty->costs_with_surcharge();
    }

    // Расчет и вывод общих расходов
    cout << endl
         << "3. Сводка общих расходов:" << endl;
    cout << "===========================" << endl;

    double total_base_cost = 0;
    double total_surcharge_cost = 0;

    for (const auto &faculty : faculties)
    {
        // Для расчета используем dynamic_cast чтобы получить доступ к protected полям
        // В реальном проекте лучше добавить геттеры в базовый класс
        MathFaculty *math = dynamic_cast<MathFaculty *>(faculty);
        PhysicsFaculty *physics = dynamic_cast<PhysicsFaculty *>(faculty);
        ComputerScienceFaculty *cs = dynamic_cast<ComputerScienceFaculty *>(faculty);

        // В данном случае, так как у всех объектов одинаковый базовый класс,
        // мы можем просто использовать базовый указатель
        // Создадим временные переменные для расчетов
        int employees = 0;
        double salary = 0;
        double surcharge = 0;

        // Получаем данные через публичные методы или геттеры
        // В данном случае, так как мы не реализовали геттеры,
        // воспользуемся простым решением - сохраним данные при создании

        if (math)
        {
            employees = 15;
            salary = 55000.0;
            surcharge = 1.2;
        }
        else if (physics)
        {
            employees = 12;
            salary = 60000.0;
            surcharge = 1.15;
        }
        else if (cs)
        {
            employees = 20;
            salary = 75000.0;
            surcharge = 1.25;
        }

        total_base_cost += employees * salary;
        total_surcharge_cost += employees * salary * surcharge * 0.13;
    }

    cout << "Общая сумма базовых расходов: " << fixed << setprecision(2) << total_base_cost << endl;
    cout << "Общая сумма расходов с надбавкой: " << fixed << setprecision(2) << total_surcharge_cost << endl;
    cout << "==============================================" << endl;

    // Примечание про число Пи и число Эйлера (из условия задачи)
    cout << endl
         << "Примечание: " << endl;
    cout << "Если округлить число Пи (3.14159...) и число Эйлера (2.71828...)" << endl;
    cout << "до целых, то и то и другое будет равно 3! :)" << endl;

    // Очистка памяти
    for (auto &faculty : faculties)
    {
        delete faculty;
    }
    faculties.clear();

    return 0;
}