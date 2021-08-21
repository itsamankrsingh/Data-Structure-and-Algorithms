#include <iostream>
#include <cstring>
using namespace std;

void inputOutput()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int t[1001][1001];

int lcsUtil(int x, int y, string s1, string s2)
{
    //base
    if (x == 0 || y == 0)
    {
        return 0;
    }

    if (t[x][y] != -1)
    {
        return t[x][y];
    }
    int ans;
    if (s1[x - 1] == s2[y - 1])
    {
        ans = (1 + lcsUtil(x - 1, y - 1, s1, s2));
        t[x][y] = ans;
    }
    else
    {

        ans = max(lcsUtil(x - 1, y, s1, s2), lcsUtil(x, y - 1, s1, s2));
    }
    return ans;
}

int lcs(int x, int y, string s1, string s2)
{
    memset(t, -1, sizeof(t));
    return lcsUtil(x, y, s1, s2);
}

int main()
{
    inputOutput();
    int x, y;
    string s1, s2;
    cin >> x >> y;
    cin >> s1 >> s2;
    cout << lcs(x, y, s1, s2);
    return 0;
}