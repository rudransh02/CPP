#include <iostream>
using namespace std;

// The Following Values Of Array Will Be Returned Everytime The Recursive Call Is Made:
// 1,2,3,4,8,12,14,26,54,78 -> 2,3,4,5,8,12,14,26,54,78 -> 3,4,8,12,26,54,78 -> 4,8,12,14,26,54,78 -> 8,12,14,26,54,78 -> 12,14,26,54,78

bool IsSorted(int array[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (array[0] > array[1])
    {
        return false;
    }
    return IsSorted(++array, --size);
}

int ArraySum(int array[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return array[0] + ArraySum(++array, --size);
}

int LinearSearch(int array[], int size, int fsize, int element)
{
    if (size == 0)
    {
        return -1;
    }
    if (array[0] == element)
    {
        return fsize - size;
    }
    return LinearSearch(++array, --size, fsize, element);
}

bool BinarySearch(int array[], int start, int end, int element)
{
    if (start > end)
    {
        return false;
    }
    int mid = start + ((end - start) / 2);
    if (array[mid] == element)
    {
        return true;
    }
    if (array[mid] < element)
    {
        BinarySearch(array, mid + 1, end, element);
    }
    else
    {
        BinarySearch(array, start, mid - 1, element);
    }
}

int main()
{
    int array[10] = {1, 2, 3, 4, 8, 12, 14, 26, 54, 78};
    // cout << IsSorted(array, 10) << endl;
    // cout << ArraySum(array, 10) << endl;
    // cout << LinearSearch(array, 10, 10, 78);
    cout << BinarySearch(array, 0, 10 - 1, 4);
}