#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Stack
{
    char info;
    Stack *next;
} *beg;

Stack *t, *Op = NULL;
char a, str1[50] = "(a+b)*(c-d)/e", str2[50];
int k = 0, l = 0;
double mas[45] = {7.4, 3.6, 2.8, 9.5, 0.9};

int Prior(char);
Stack *InStack(Stack *, char);
Stack *OutStack(Stack *, char *);
void Post(char *);
void result(char *);

Stack *InStack(Stack *p, char info)
{
    Stack *t = new Stack;
    t->info = info;
    t->next = p;
    return t;
}
Stack *OutStack(Stack *p, char *info)
{
    Stack *t = p;
    *info = t->info;
    p = p->next;
    delete t;
    return p;
}
int Prior(char a)
{
    switch (a)
    {

    case '*':
    case '/':
        return 3;
    case '-':
    case '+':
        return 2;
    case '(':
        return 1;
    }
    return 0;
}
void Post(char *In)
{
    while (In[k] != '\0')
    {
        if (In[k] == ')')
        {
            while ((Op->info) != '(')
            {
                Op = OutStack(Op, &a);
                if (!Op)
                    a = '\0';
                str2[l++] = a;
            }
            t = Op;
            Op = Op->next;
            delete t;
        }
        if (In[k] >= 'a' && In[k] <= 'z')
            str2[l++] = In[k];
        if (In[k] == '(')
            Op = InStack(Op, In[k]);
        if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/')
        {

            while (Op != NULL && Prior(Op->info) >= Prior(In[k]))
            {
                Op = OutStack(Op, &a);
                str2[l++] = a;
            }
            Op = InStack(Op, In[k]);
        }
        k++;
    }
    while (Op != NULL)
    {
        Op = OutStack(Op, &a);
        str2[l++] = a;
    }
    str2[l] = '\0';
    cout << "ОПЗ:" << str2 << endl;
}
void result(char *Str)
{
    char ch, ch1, ch2;
    double res = 0, op1, op2;
    char chr = 'z';
    for (int i = 0; i < strlen(Str); i++)
    {
        ch = Str[i];
        if (ch >= 'a' && ch <= 'z')
            beg = InStack(beg, ch);
        else
        {
            beg = OutStack(beg, &ch1);
            beg = OutStack(beg, &ch2);
            op1 = mas[int(ch1) - 97];
            op2 = mas[int(ch2) - 97];

            switch (ch)
            {
            case '+':
                res = op2 + op1;
                break;
            case '-':
                res = op2 - op1;
                break;
            case '*':
                res = op2 * op1;
                break;
            case '/':
                res = op2 / op1;
                break;
            }
            mas[int(chr) - 97] = res;
            beg = InStack(beg, chr);
            chr--;
        }
    }
    cout << "Численное значение ОПЗ:" << res;
    cout << endl;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Post(str1);
    result(str2);
    system("pause");
    return 0;
}