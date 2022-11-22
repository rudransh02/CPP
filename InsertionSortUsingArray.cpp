#include <iostream>
using namespace std;

// In This, The Elements Don't Get Swapped, They Get Shifted!
// 6,2,8,10,4 -> 2,6,8,10,4 -> 2,4,6,8,10

void InsertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {   
        int j;
        int temp = array[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (array[j] > temp)
            {
                array[j + 1] = array [j];
            }
            else
            {
                break;
            }
        }
        array[j + 1] = temp;
    }
}

int main()
{
    int size = 10;
    int array[size] = {5, 14, 663, 2, 47, 69, 48, 63, 41, 255};
    InsertionSort(array, size);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}