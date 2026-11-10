#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

struct Spisok
{
    int info;
    Spisok *next, *prev;
};

void Create(Spisok **, Spisok **, int);
void Add(int, Spisok **, Spisok **, int);
void View(int, Spisok *, Spisok *);
void Del_All(Spisok **);
void Task(Spisok **, Spisok **);
void Del_One(Spisok **);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Spisok *begin = NULL, *end = NULL, *t = NULL;
    srand(time(NULL));
    int in, ch, ch1, n;
    while (true)
    {
        cout << "1.Создание\n2.Добавление\n3.Просмотр\n4.Удаление\n5.Задание\n0.Выход\nВыбор : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (begin != NULL)
            {
                Del_All(&begin);
            }
            in = rand() % 200 - 100;
            Create(&begin, &end, in);
            break;
        case 2:
            cout << "Введите кол-во элементов, которое хотите добавить : ";
            cin >> n;
            cout << "Добавить в начало - 1\nДобавить в конец - 2\nВыбор : ";
            cin >> ch1;
            for (int i = 0; i < n; i++)
            {
                in = rand() % 200 - 100;
                Add(ch1, &begin, &end, in);
            }
            break;
        case 3:
            if (!begin)
            {
                cout << "Пусто (" << endl
                     << endl;
                break;
            }
            cout << "Просмотр с\n1.Начала \n2.Конца" << endl;
            cin >> ch1;
            View(ch1, begin, end);
            cout << endl;
            break;
        case 4:
            Del_All(&begin);
            break;
        case 5:
            Task(&begin, &end);
            break;
        case 0:
            if (begin != NULL)
                Del_All(&begin);
            system("pause");
            return 0;
        }
    }
}

void Create(Spisok **b, Spisok **e, int in)
{
    Spisok *t = new Spisok;
    t->info = in;
    t->next = t->prev = NULL;
    *b = *e = t;
}

void Add(int ch1, Spisok **b, Spisok **e, int in)
{
    Spisok *t = new Spisok;
    t->info = in;
    if (ch1 == 1)
    {
        t->prev = NULL;
        t->next = *b;
        (*b)->prev = t;
        *b = t;
    }
    else
    {
        t->next = NULL;
        t->prev = *e;
        (*e)->next = t;
        *e = t;
    }
}

void View(int ch1, Spisok *b, Spisok *e)
{
    if (ch1 == 1)
    {
        cout << "Список:" << endl;
        while (b != NULL)
        {
            cout << "\t" << b->info;
            b = b->next;
        }
    }
    if (ch1 == 2)
    {
        cout << "Список:" << endl;
        while (e != NULL)
        {
            cout << "\t" << e->info;
            e = e->prev;
        }
    }
}

void Del_All(Spisok **k)
{
    Spisok *t;
    while (*k != NULL)
    {
        t = *k;
        *k = (*k)->next;
        delete t;
    }
}

void Task(Spisok **p, Spisok **ending)
{
    Spisok *el = *p;
    Spisok *t = el;
    Spisok *dop;
    while ((*p)->info % 2 == 0)
    {
        Del_One(p);
    }
    t = *p;
    while (true)
    {
        el = t;
        if (el->next == NULL)
            break;
        el = el->next;
        while (true)
        {
            if (el->info % 2 == 0)
            {
                if (el->next != NULL)
                {
                    dop = el;
                    el = el->next;
                    el->prev = t;
                    delete dop;
                }
                else
                {
                    delete el;
                    t->next = NULL;
                    (*ending) = t;
                    break;
                }
            }
            else
            {
                t->next = el;
                break;
            }
        }
        if (t->next == NULL)
            break;
        t = t->next;
    }
}

void Del_One(Spisok **p)
{
    Spisok *t = NULL;
    t = *p;
    *p = (*p)->next;
    (*p)->prev = NULL;
    delete t;
}
