#include <iostream>
#include <stack>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    stack<int> stack;

    stack.push(low);
    stack.push(high);

    while (!stack.empty())
    {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        int pivot = partition(arr, low, high);

        if (pivot - 1 > low)
        {
            stack.push(low);
            stack.push(pivot - 1);
        }

        if (pivot + 1 < high)
        {
            stack.push(pivot + 1);
            stack.push(high);
        }
    }
}

int main()
{
    auto start_time = high_resolution_clock::now();

    int arr[50] = {7, 49, 73, 58, 30, 72, 44, 78, 23, 9, 40, 65, 92, 42, 87, 3, 27, 29, 40, 12, 3, 69, 9, 57, 60, 33, 99, 78, 16, 35, 97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Time taken to Iterative Quick sort the array: " << duration.count() << " nanoseconds" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
