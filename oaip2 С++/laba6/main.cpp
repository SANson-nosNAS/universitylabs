#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

struct Tree
{
    int num;
    string name;
    Tree *left, *right;
};

struct Info
{
    int num;
    string name;
};

Tree *List(Info a);                                  // создание
void Add_List(Tree *root, Info a);                   // добавление
void View1(Tree *p);                                 // просмотр (прямой обход)
void View2(Tree *p);                                 // просмотр (обратный обход)
void View3(Tree *p);                                 // просмотр (центрированный)(по возрастанию)
void Count(Tree *p, int &n);                         // функция подсчета колличества элементов в дереве
void Balanced_Mass(Tree *p, Info *a, int &i);        // создание отсортированного массива на основе дерева
void Balanced_Tree(Tree **p, int l, int r, Info *a); // создание сбалансированного дерева на основе отсортированного массива
void Srch(Tree *p, int key);                         // поиск
void Replacement(Tree *&k, Tree *&m);                // нахождение замены для удалееного элемента
void Del_uz(Tree *&T, int Passport);                 // удаление по заданному ключу
void Task(Tree *root, int &kol);                     // индивидуальное задание
void Del_Tree(Tree *t);                              // удаление дерева

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Tree *root = NULL;
    Info *a = NULL, dop;
    int n, sel, in, kol = 0;
    while (true)
    {
        do
        {
            cout << "Главное меню:\n1.Создание\n2.Добавление\n3.Просмотр\n4.Балансировка дерева\n5.Поиск по заданному ключу\n6.Удаление с заданным ключом\n7.Индивидуальное задание\n8.Удаление дерева\n9.Выход\n\nВыберите действие:";
            cin >> sel;
            cout << endl;
        } while (!((sel >= 1) && (sel <= 9)));
        switch (sel)
        {
        case 1: // создание
            if (root != NULL)
            {

                cout << "Очистите память!" << endl;
                break;
            }
            cout << "Введите колличество элементов в дереве: ";
            cin >> n;
            a = new Info[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Введите ФИО " << i + 1 << " гражданина: ";
                cin.ignore();
                getline(cin, a[i].name);
                cout << "Введите номер пасспорта (до 8 цифр): ";
                cin >> a[i].num;
            }
            root = List(a[0]);
            for (int i = 1; i < n; i++)
                Add_List(root, a[i]);
            View1(root);
            delete[] a;
            break;
        case 2: // добавление
            if (root == NULL)
            {
                cout << "Дерево поиска пусто! Сначала запустите процедуру создания дерева." << endl;
                break;
            }
            cout << "Введите ФИО гражданина: ";
            cin.ignore();
            getline(cin, dop.name);
            cout << "Введите номер пасспорта: ";
            cin >> dop.num;
            Add_List(root, dop);
            View1(root);
            cout << endl;
            break;
        case 3: // просмотр
            if (!root)
            {
                cout << "Дерево поиска не создано!" << endl
                     << endl;
                break;
            }
            cout << "Выберите обход: \n1.Прямой\n2.Обратный\n3.По возрастанию ключа" << endl;
            cin >> in;
            switch (in)
            {
            case 1:
                View1(root);
                break;
            case 2:
                View2(root);
                break;
            case 3:
                View3(root);
                break;
            default:
                cout << "Ошибка" << endl;
            }
            cout << endl;
            break;
        case 4: // балансирование дерева
            if (!root)
            {
                cout << "Дерево поиска не создано!" << endl
                     << endl;
                break;
            }
            n = 0;
            in = 0;
            Count(root, n);
            a = new Info[n];
            Balanced_Mass(root, a, in);
            Del_Tree(root);
            root = NULL;
            Balanced_Tree(&root, 0, n, a);
            cout << "---|Успешно выполненно|---" << endl;
            delete[] a;
            View3(root);
            cout << endl;
            break;
        case 5: // поиск по ключу
            if (!root)
            {
                cout << "Дерево поиска не создано!" << endl
                     << endl;
                break;
            }
            cout << "Введите ключ: ";
            cin >> in;
            Srch(root, in);
            cout << endl;
            break;
        case 6: // удаление по ключу
            if (!root)
            {
                cout << "Дерево поиска не создано!" << endl
                     << endl;
                break;
            }
            cout << "Введите ключ: ";
            cin >> in;
            Del_uz(root, in);
            View1(root);
            break;
        case 7: // индивидуальное задание
            if (!root)
            {
                cout << "Дерево поиска не создано!" << endl
                     << endl;
                break;
            }
            Task(root, kol);
            cout << "Число листов в дереве:" << kol << endl;
            break;
        case 8: // удаление всего дерева
            Del_Tree(root);
            root = NULL;
            cout << "Память очищена!" << endl
                 << endl;
            break;
        case 9: // выход
            if (root != NULL)
            {
                Del_Tree(root);
                root = NULL;
            }
            system("pause");
            return 0;
        }
    }
}

void Replacement(Tree *&k, Tree *&m)
{
    if (m->right != NULL)
    {
        Replacement(k, m->right);
    }
    else
    {
        k->num = m->num;
        k = m;
        m = m->left;
    }
}

void Del_uz(Tree *&T, int Passport)
{
    if (T == NULL)
    {
        cout << "Дерева нет(";
        return;
    }
    else if (T->num > Passport)
        return Del_uz(T->left, Passport);
    else if (T->num < Passport)
        return Del_uz(T->right, Passport);
    else
    {
        Tree *DEL;
        DEL = T;
        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)
            T = T->left;
        else
        {
            Replacement(DEL, T->left);
        }
        delete DEL;
    }
}

void Task(Tree *root, int &kol)
{
    if (root != NULL)
    {
        if (!root->left && !root->right)
            kol++;
        Task(root->left, kol);
        Task(root->right, kol);
    }
}

Tree *List(Info a)
{
    Tree *lt = new Tree;
    lt->num = a.num;
    lt->name = a.name;
    lt->left = lt->right = NULL;
    return lt;
}

void Add_List(Tree *root, Info a)
{
    Tree *prev = NULL, *t = NULL;

    bool find = true;
    t = root;

    while (t && find)
    {
        prev = t;
        if (a.num == t->num)
        {
            find = false;

            cout << "Dublucate Key!" << endl;
        }
        else if (a.num < t->num)
            t = t->left;
        else
            t = t->right;
    }
    if (find)
    {

        t = List(a);

        if (a.num < prev->num)
            prev->left = t;
        else
            prev->right = t;
    }
}
void View1(Tree *p)
{
    if (p)
    {
        cout << "ФИО:" << p->name << "\t№:" << p->num << endl;
        View1(p->left);

        View1(p->right);
    }
}
void View2(Tree *p)
{
    if (p)
    {
        View2(p->left);
        View2(p->right);
        cout << "ФИО:" << p->name << "\t№:" << p->num << endl;
    }
}
void View3(Tree *p)
{
    if (p)
    {

        View3(p->left);
        cout << "ФИО:" << p->name << "\t№:" << p->num << endl;
        View3(p->right);
    }
}
void Srch(Tree *p, int key)
{
    if (p)
    {
        if (key == p->num)
        {
            cout << "ФИО:" << p->name << "\t№:" << p->num << endl;
            return;
        }
        else if (key > p->num)
        {
            Srch(p->right, key);
        }
        else if (key < p->num)
        {
            Srch(p->left, key);
        }
    }
    else
        cout << "В дереве нет элемента с таким значением" << endl;
}
void Del_Tree(Tree *t)
{
    if (t != NULL)
    {
        Del_Tree(t->left);
        Del_Tree(t->right);
        delete t;
    }
}

void Count(Tree *p, int &n)
{
    if (p)
    {
        Count(p->left, n);
        Count(p->right, n);
        n++;
    }
}
void Balanced_Mass(Tree *p, Info *a, int &i)
{
    if (p)
    {
        Balanced_Mass(p->left, a, i);
        a[i].name = p->name;
        a[i].num = p->num;
        i++;
        Balanced_Mass(p->right, a, i);
    }
}
void Balanced_Tree(Tree **p, int l, int r, Info *a)
{
    if (l == r)
    {
        *p = NULL;
        return;
    }
    else
    {
        int m = (l + r) / 2;
        *p = new Tree;
        (*p)->num = a[m].num;
        (*p)->name = a[m].name;
        Balanced_Tree(&(*p)->left, l, m, a);
        Balanced_Tree(&(*p)->right, m + 1, r, a);
    }
}
