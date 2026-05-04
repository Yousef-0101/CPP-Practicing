#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    ~Queue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << val << " enqueued to queue\n";
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue Underflow! Queue is empty\n";
            return;
        }
        Node *temp = front;
        cout << front->data << " dequeued from queue\n";
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        count--;
    }

    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    int size()
    {
        return count;
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue (front -> rear): ";
        Node *curr = front;
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
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front: " << q.peek() << endl;
    cout << "Size: " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}