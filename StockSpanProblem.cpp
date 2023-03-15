#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int size = 6;
    int stocks[size]{10, 4, 5, 90, 120, 80};
    // int size = 7;
    // int stocks[size] {100, 80, 60, 70, 60, 75, 85};
    vector<int> answer;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = i; j >= 0; j--)
        {
            if (stocks[j] <= stocks[i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        answer.push_back(count);
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}