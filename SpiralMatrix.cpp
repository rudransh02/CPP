#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // your code goes here
    // If Online Judge Is Not Defined Use Input And Output Files For Execution
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int a[4][4] = {{1,  2,  3,  4},
                   {5,  6,  7,  8},
                   {9,  10, 11, 12},
                   {13, 14, 15, 16}};
    int rowStart = 0;
    int columnStart = 0;
    int rowEnd = 3;
    int columnEnd = 3;
    while (rowStart <= rowEnd && columnStart <= columnEnd)
    {
        for (int i = columnStart; i <= columnEnd; i++)
        {
            cout << a[rowStart][i] << " ";
        }
        rowStart++;
        for (int i = rowStart; i <= rowEnd; i++)
        {
            cout << a[i][columnEnd] << " ";
        }
        columnEnd--;
        if (rowStart <= rowEnd)
        {
            for (int i = columnEnd; i >= columnStart; i--)
            {
                cout << a[rowEnd][i] << " ";
            }
            rowEnd--;
        }
        if (columnStart <= columnEnd)
        {
            for (int i = rowEnd; i >= rowStart; i--)
            {
                cout << a[i][columnStart] << " ";
            }
            columnStart++;
        }
    }
}