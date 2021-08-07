#include <iostream>
#include <unordered_set>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int findUniqueElementUsingLoops(int arr[], int n)
{
    int flag = 0;
    int count = 0;
    // Pick all elements one by one
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
                break;
            }
        }
        // If not printed earlier, then print it
        if (flag == 0)
        {
            count++;
        }
    }
    return count;
}

/*
Hashing
*/
int findUniqueElement(int arr[], int n)
{
    unordered_set<int> set;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (set.find(arr[i]) == set.end())
        {
            set.insert(arr[i]);
            count++;
        }
    }
    return count;
}

int main()
{
    inputOutput();
    int arr[] = {1, 2, 3, 4, 5};
    cout << findUniqueElement(arr, 5) << endl;
    cout << findUniqueElementUsingLoops(arr, 5) << endl;
}