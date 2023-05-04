#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Partition function to find the pivot element
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Driver code
int main()
{
    auto start_time = high_resolution_clock::now();
    int arr[50] = {7, 49, 73, 58, 30, 72, 44, 78, 23, 9, 40, 65, 92, 42, 87, 3, 27, 29, 40, 12, 3, 69, 9, 57, 60, 33, 99, 78, 16, 35, 97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Time taken to Recursive Quick sort the array: " << duration.count() << " nanoseconds" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
