#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::chrono;

// Structure to represent a node in the linked list
struct Node
{
    int data;
    Node *next;
};

// Class to represent a stack
class Stack
{
public:
    Node *top; // Pointer to the top node of the stack
    Node *head;

    // Constructor to initialize an empty stack
    Stack()
    {
        top = NULL;
        head = NULL;
    }

    // Function to push an element onto the stack
    void push(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int val = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    // Function to get the element at the top of the stack
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Function to display the stack as a linked list
    void displayList()
    {
        if (top == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        cout << "Stack elements are : ";
        vector<int> elements; // store elements in a vector
        Node *current = top;
        while (current != NULL)
        {
            elements.push_back(current->data);
            current = current->next;
        }

        // iterate over the elements in reverse order and print them
        for (auto it = elements.rbegin(); it != elements.rend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stackLinked;
    auto start_time = high_resolution_clock::now();
    stackLinked.push(8);
    stackLinked.push(10);
    stackLinked.push(5);
    stackLinked.push(11);
    stackLinked.push(15);
    stackLinked.push(23);
    stackLinked.push(6);
    stackLinked.push(18);
    stackLinked.push(20);
    stackLinked.push(17);
    stackLinked.displayList();

    stackLinked.pop();
    stackLinked.pop();
    stackLinked.pop();
    stackLinked.pop();
    stackLinked.pop();
    stackLinked.displayList();

    stackLinked.push(4);
    stackLinked.push(30);
    stackLinked.push(3);
    stackLinked.push(1);
    stackLinked.displayList();

    // Print the time taken for executing the operations on the stack
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Time taken for executing implementation using LinkedList: " << duration.count() << " nanoseconds" << endl;

    return 0;
}