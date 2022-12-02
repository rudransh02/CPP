#include <iostream>
using namespace std;

// [50,20,30,40,10] -> [50,20] | [30,40,10] -> [50] [20] | [30] [40,10] -> [50] [20] | [30] | [40] [10]
// [20,50] | [30] | [10,40] -> [20,50] | [10,30,40] -> [10,20,30,40,50]

void Merge(int array[], int start, int end)
{
    int mid = start + ((end - start) / 2);
    // Length Of Array 1
    int length1 = mid - start + 1;
    // Length Of Array 2
    int length2 = end - mid;
    // Array 1
    int first[length1];
    // Array 2
    int second[length2];
    // Index Of Main Array In Which Both Sorted Array Will Be Merged
    int MainArrayIndex = start;
    // Copying The First Half Of The Array Into Array 1
    for (int i = 0; i < length1; i++)
    {
        first[i] = array[MainArrayIndex++];
    }
    // Updating Value Of Index Of Our Main Array To Copy The Second Half
    MainArrayIndex = mid + 1;
    // Copying The Second Half Of The Array Into Array 2
    for (int i = 0; i < length2; i++)
    {
        second[i] = array[MainArrayIndex++];
    }
    // Actual Code To Merge Two Arrays With Sorting
    // Index Of Array 1
    int index1 = 0;
    // Index Of Array 2
    int index2 = 0;
    // Updating Index Of Our Final Answer Array To Start From Zero
    MainArrayIndex = start;
    while (index1 < length1 && index2 < length2)
    {
        // Checking And Inserting The Smallest Value From Both The Arrays First So That The Array Stays Sorted After Insertion
        if (first[index1] < second[index2])
        {
            array[MainArrayIndex++] = first[index1++];
        }
        else
        {
            array[MainArrayIndex++] = second[index2++];
        }
    }
    // Inserting Extra Elements From Array 1 If Any Left
    while (index1 < length1)
    {
        array[MainArrayIndex++] = first[index1++];
    }
    // Inserting Extra Elements From Array 2 If Any Left
    while (index2 < length2)
    {
        array[MainArrayIndex++] = second[index2++];
    }
    // Deleting Array First And Second To Deallocate Memory
    delete[] first;
    delete[] second;
}

void MergeSort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + ((end - start) / 2);
    // Sorting Left Part Of The Array
    MergeSort(array, start, mid);
    // Sorting Right Part Of The Array
    MergeSort(array, mid + 1, end);
    // Function To Merge The Above 2 Sorted Arrays
    Merge(array, start, end);
}

int main()
{
    int array[10] = {21, 45, 78, 41, 58, 14, 69, 52, 77, 47};
    MergeSort(array, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}