#include <iostream>
using namespace std;

// Sorting Using Pivot Element By Placing All The Element Smaller Than The Pivot To Its Left And All The Elements Bigger Than The Pivot To Its Right

int Partition(int array[], int start, int end)
{
    // Taking The First Element Of Array As Pivot
    int pivot = array[start];
    // Counting The Total Number Of Elements Smaller Than Pivot
    int smallerthanpivot = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (array[i] <= pivot)
        {
            smallerthanpivot++;
        }
    }
    // Finding The Index Of Pivot Where It Should Be
    int pivotindex = smallerthanpivot + start;
    // Swapping Values To Place The Pivot Element On Its Correct Index
    swap(array[pivotindex], array[start]);
    // Placing The Elements Smaller Than Pivot To Its Left And The Elements Bigger Than Pivot To Its Right
    int i = start;
    int j = end;
    while (i < pivotindex && j > pivotindex)
    {
        // Increment i If Element At The Left Is Smaller Than Pivot
        while (array[i] < pivot)
        {
            i++;
        }
        // Increment j If Element At The Right Is Greater Than Pivot
        while (array[j] > pivot)
        {
            j--;
        }
        // Swap Values Of Array On Index i And j If Value At Index i is Greater Than Pivot And Value At Index j is Smaller Than Pivot
        if (i < pivotindex && j > pivotindex)
        {
            swap(array[i++], array[j--]);
        }
    }
    return pivotindex;
}

void QuickSort(int array[], int start, int end)
{
    if (start > end)
    {
        return;
    }
    // Returning The Index Of The Pivot Element Where It Should Exist
    int pivot = Partition(array, start, end);
    // For Sorting The Left Partition Of The Array
    QuickSort(array, start, pivot - 1);
    // For Sorting The Right Partitioin Of The Array
    QuickSort(array, pivot + 1, end);
}

int main()
{
    int array[10] = {12, 54, 65, 87, 321, 65, 87, 61, 1, 5};
    QuickSort(array, 0, 10 - 1);
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}