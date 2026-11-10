#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");

    string text;
    cout << "Введите строку содержащую группы нулей и единиц: ";
    getline(cin, text);

    vector<string> words;
    string word;

    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word += text[i];
        }
    }
    words.push_back(word);

    string maxlword;
    for (int i = 0; i < words.size() - 1; i++)
    {
        if (words[i].size() < words[i + 1].size())
            maxlword = words[i + 1];
    }
    cout << maxlword;
}