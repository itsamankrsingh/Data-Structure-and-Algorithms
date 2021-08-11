#include <iostream>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool checkPassword(char c[], int size, int min)
{
    if (size < min)
    {
        return false;
    }

    if (c[0] - '0' >= 0 && c[0] - '0' <= 9)
    {
        return false;
    }

    int i = 0, num = 0, cap = 0;

    while (i < size)
    {
        if (c[i] == ' ' || c[i] == '+')
        {
            return false;
            break;
        }
        else if (c[i] - '0' >= 65 && c[i] - '0' <= 90)
        {
            cap++;
        }
        else if (c[i] - '0' >= 0 && c[i] - '0' <= 9)
        {
            num++;
        }
        i++;
    }
    if (cap > 0 && num > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    inputOutput();
    string s;
    getline(cin, s);

    char *c = &s[0];
    int size = s.size();

    int min;
    cin >> min;

    if (checkPassword(c, size, min))
    {
        cout << "Valid\n";
    }
    else
    {
        cout << "Not Valid\n";
    }
}