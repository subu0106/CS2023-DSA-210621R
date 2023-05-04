#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    vector<int> array; // create a vector to store input integers
    int n;
    while (cin >> n)
    {                                     // read integers from input stream
        array.push_back(n);               // add the integer to the list
        sort(array.begin(), array.end()); // sort the list
        int arrayLength = array.size();   // get the arrayLengthgth of the vector
        if (arrayLength % 2 == 1)
        { // if the arrayLengthgth is odd
            cout << "[";
            for (int i = 0; i < arrayLength; i++)
            {
                cout << array[i] << (i == arrayLength - 1 ? "]" : ", "); // print sorted list
            }
            cout << " " << fixed << setprecision(1) << (double)array[arrayLength / 2] << endl; // print median
        }
        else
        { // if the arrayLengthgth is even
            cout << "[";
            for (int i = 0; i < arrayLength; i++)
            {
                cout << array[i] << (i == arrayLength - 1 ? "]" : ", "); // print sorted list
            }
            double median = (array[arrayLength / 2 - 1] + array[arrayLength / 2]) / 2.0; // calculate the median
            cout << " " << fixed << setprecision(1) << median << endl;                   // print median
        }
    }
    return 0;
}
