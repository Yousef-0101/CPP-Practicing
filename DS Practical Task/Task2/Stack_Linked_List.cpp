#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack
{
private:
    Node *top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}

    ~Stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        count++;
        cout << val << " pushed to stack\n";
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow! Stack is empty\n";
            return;
        }
        Node *temp = top;
        cout << top->data << " popped from stack\n";
        top = top->next;
        delete temp;
        count--;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int size()
    {
        return count;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (top -> bottom): ";
        Node *curr = top;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

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