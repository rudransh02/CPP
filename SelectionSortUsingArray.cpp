#include <iostream>
using namespace std;

// 6,2,8,4,10 -> 2,6,8,4,10 -> 2,4,8,6,10 -> 2,4,6,8,10 -> 2,4,6,8,10

void SelectionSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[MinIndex])
            {
                MinIndex = j;
            }
        }
        swap(array[i], array[MinIndex]);
    }
}

int main()
{
    int size = 10;
    int array[size] = {5, 14, 663, 2, 47, 69, 48, 63, 41, 255};
    SelectionSort(array, size);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}