#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void chahging_word_2_vowel_letters(string& a, ofstream& k)
{
    string glasn = "аоиыуэяюёеАОИЫУЭЯЮЁЕ";
    bool f = false;
    string itog;
    for (int j = 0; j < a.size() - 1; j++)
    {
        for (int i = 0; i < glasn.size(); i++)
        {
            if (a[j] == glasn[i] && tolower(a[j]) == tolower(a[j + 1]))
            {
                a[j] = toupper(a[j]);
                a[j + 1] = toupper(a[j + 1]);
                itog += a[j];
                f = true;
            }
            
        }
    }
    if (f == true)
        k << a << "(" << itog << ")" << " ";
    else
        k << a << " ";
}

int main()
{


    setlocale(LC_ALL, "rus");
    string s;
    ifstream in("in.txt");
    ofstream out("out.txt");
    while (!in.eof())
    {
        in >> s;
        chahging_word_2_vowel_letters(s, out);     
    }
}


