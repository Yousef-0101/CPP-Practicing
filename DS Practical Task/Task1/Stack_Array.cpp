#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int val)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow! Cannot push " << val << endl;
            return;
        }
        arr[++top] = val;
        cout << val << " pushed to stack\n";
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow! Stack is empty\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (top -> bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;

    s.pop();
    s.pop();
    s.display();

    s.pop();
    s.pop();

    cout << "Is empty: " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}