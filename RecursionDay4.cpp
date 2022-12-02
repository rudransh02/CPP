#include <iostream>
using namespace std;

void ReverseString(string &string, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(string[start], string[end]);
    ReverseString(string, ++start, --end);
}

bool CheckPalindrome(string string, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    else if (string[start] != string[end])
    {
        return false;
    }
    else
    {
        return CheckPalindrome(string, ++start, --end);
    }
}

int Power(int number, int power)
{
    if (power == 0)
    {
        return 1;
    }
    return number * Power(number, power - 1);
}

void BubbleSort(int array[], int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i] > array[i + 1])
        {
            swap(array[i], array[i + 1]);
        }
    }
    BubbleSort(array, size - 1);
}

int main()
{
    int array[5] = {50, 47, 58, 61, 20};
    string string = "ABBCCBBA";
    // ReverseString(string, 0, string.length() - 1);
    // cout << string;
    // cout << CheckPalindrome(string, 0, string.length() - 1);
    // cout << Power(3, 4);
    BubbleSort(array, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}