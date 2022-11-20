#include <iostream>
using namespace std;

int BinarySearch(int array[], int size, int value)
{
    int index = 0;
    int start = 0;
    int end = size - 1;
//Because Range Of 'int' is (2^31) - 1 And If Values Like 2^31 and 2^30 Are Summed Up To Get Divided By 2 Then The Code Will Break In The 'mid' Variable!
    int mid = start + ((end - start) / 2);
    while (start <= end)
    {
//If Element Is Equal To The Mid Element
        if (array[mid] == value)
        {
            return mid;
        }
//If Element Is Smaller Than The Mid Element
        else if (array[mid] < value)
        {
            start = mid + 1;
        }
//If Element Is Greater Than The Mid Element
        else
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
//If Element Is Not Found
    return -1;
}

int main()
{
    int value = 102;
    int size = 10;
    int array[size] = {3,5,8,14,54,98,102,147,158,164};
    cout << "The Element Is Found At " << BinarySearch(array, size, value) << "th Index!";
}