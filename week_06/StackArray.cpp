#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
#include <vector>

#define MAX_SIZE 1000

class Stack
{
public:
    int top; // index of the top element in the stack
    int array[MAX_SIZE];

public:
    Stack() // Constructor to initialize an empty stack
    {
        top = -1;
    }

    // Function to push an element onto the stack
    void push(int x)
    {
        if (top >= MAX_SIZE - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        array[++top] = x;
    }

    // Function to pop an element from the stack
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    // Function to get the element at the top of the stack
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return array[top];
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top < 0;
    }

    // Function to display the stack elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are : ";
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stackArr;
    auto start_time = high_resolution_clock::now();
    stackArr.push(8);
    stackArr.push(10);
    stackArr.push(5);
    stackArr.push(11);
    stackArr.push(15);
    stackArr.push(23);
    stackArr.push(6);
    stackArr.push(18);
    stackArr.push(20);
    stackArr.push(17);
    stackArr.display();

    stackArr.pop();
    stackArr.pop();
    stackArr.pop();
    stackArr.pop();
    stackArr.pop();
    stackArr.display();

    stackArr.push(4);
    stackArr.push(30);
    stackArr.push(3);
    stackArr.push(1);
    stackArr.display();

    // Print the time taken for executing the operations on the stack
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Time taken for executing implementation using Array: " << duration.count() << " nanoseconds" << endl;
}