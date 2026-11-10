#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

struct Stack
{
    int info;
    Stack *next;
};

void InStack(Stack **, int);
void Task(Stack **);
void View(Stack *);
void Del_All(Stack **);
void Sort_info(Stack *);
void Sort_p(Stack **);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    int in, n, ch;
    Stack *begin = NULL, *t;
    while (true)
    {
        cout << "1.Создание\n2.Добавление\n3.Просмотр\n4.Удаление\n5.Задание\n6.Адресная сортировка \n7.Сортировка с помощью информационной части\n0.Выход\nВыбор: ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
        case 2:
            if (ch == 1 && begin != NULL)
            {
                Del_All(&begin);
            }
            cout << "Введите количество элементов стека = ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                in = rand() % 200 - 100;
                InStack(&begin, in);
            }
            View(begin);
            cout << endl;
            break;
        case 3:
            if (!begin)
            {
                cout << "Пустой стек" << endl
                     << endl;
            }
            else
            {
                View(begin);
                cout << endl;
            }
            break;
        case 4:
            Del_All(&begin);
            cout << "СТЕК ОЧИЩЕН" << endl;
            break;
        case 5:
            Task(&begin);
            View(begin);
            cout << endl;
            break;
        case 6:
            InStack(&begin, 0);
            Sort_p(&begin);
            t = begin;
            begin = begin->next;
            delete t;
            View(begin);
            break;
        case 7:
            Sort_info(begin);
            View(begin);
            cout << endl;
            break;
        case 0:
            if (begin != NULL)
                Del_All(&begin);
            system("pause");
            return 0;
        }
    }
}

void InStack(Stack **begin, int in)
{
    Stack *t = new Stack;
    t->info = in;
    t->next = *begin;
    *begin = t;
}

void View(Stack *vag)
{
    while (vag != NULL)
    {
        cout << " " << vag->info << endl;
        vag = vag->next;
    }
}

void Del_All(Stack **vag)
{
    Stack *t;
    while (*vag != NULL)
    {
        t = *vag;
        *vag = (*vag)->next;
        delete t;
    }
}

void Task(Stack **vag)
{
    Stack *k = *vag, *t = *vag, *dop;
    while ((*vag)->info % 2 == 0)
    {
        *vag = (*vag)->next;
        delete k;
        k = *vag;
    }
    t = *vag;
    while (true)
    {
        k = t;
        if (k->next == NULL)
            break;
        k = k->next;
        while (true)
        {
            if (k->info % 2 == 0)
            {
                if (k->next != NULL)
                {
                    dop = k;
                    k = k->next;
                    delete dop;
                }
                else
                {
                    delete k;
                    t->next = NULL;
                    break;
                }
            }
            else
            {
                t->next = k;
                break;
            }
        }
        if (t->next == NULL)
            break;
        t = t->next;
    }
}

void Sort_p(Stack **p)
{
    Stack *t = NULL, *t1, *r;
    if ((*p)->next->next == NULL)
        return;
    do
    {
        for (t1 = *p; t1->next->next != t; t1 = t1->next)
            if (t1->next->info > t1->next->next->info)
            {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        t = t1->next;
    } while ((*p)->next->next != t);
}

void Sort_info(Stack *p)
{
    Stack *t = NULL, *t1 = NULL;
    int r;
    if (p->next != NULL)
    {
        do
        {
            for (t1 = p; t1->next != t; t1 = t1->next)
                if (t1->info > t1->next->info)
                {
                    r = t1->info;
                    t1->info = t1->next->info;
                    t1->next->info = r;
                }
            t = t1;
        } while (p->next != t);
    }
}
