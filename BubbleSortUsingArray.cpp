#include <iostream>
using namespace std;

// 6,2,8,10,4 -> 2,6,8,10,4 -> 2,6,8,4,10 -> 2,6,4,8,10 -> 2,4,6,8,10

void BubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main()
{
    int size = 10;
    int array[size] = {5, 14, 663, 2, 47, 69, 48, 63, 41, 255};
    BubbleSort(array, size);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}