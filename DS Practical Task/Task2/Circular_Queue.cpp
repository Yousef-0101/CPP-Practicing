#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueue
{
    Node *rear;
    int count;

public:
    CircularQueue() : rear(nullptr), count(0) {}

    ~CircularQueue()
    {
        if (!rear)
            return;
        Node *curr = rear->next;
        while (curr != rear)
        {
            Node *t = curr;
            curr = curr->next;
            delete t;
        }
        delete rear;
    }

    void enqueue(int val)
    {
        Node *n = new Node(val);
        if (!rear)
        {
            n->next = n;
            rear = n;
        }
        else
        {
            n->next = rear->next;
            rear->next = n;
            rear = n;
        }
        count++;
        cout << val << " enqueued\n";
    }

    void dequeue()
    {
        if (!rear)
        {
            cout << "Empty\n";
            return;
        }
        Node *front = rear->next;
        cout << front->data << " dequeued\n";
        if (front == rear)
        {
            rear = nullptr;
        }
        else
        {
            rear->next = front->next;
        }
        delete front;
        count--;
    }

    int peek()
    {
        if (!rear)
        {
            cout << "Empty\n";
            return -1;
        }
        return rear->next->data;
    }

    void display()
    {
        if (!rear)
        {
            cout << "Empty\n";
            return;
        }
        Node *curr = rear->next;
        cout << "Queue (front -> rear): ";
        do
        {
            cout << curr->data << (curr != rear ? " -> " : "\n");
            curr = curr->next;
        } while (curr != rear->next);
    }

    int size() { return count; }
    bool isEmpty() { return !rear; }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front: " << q.peek() << "\n";
    cout << "Size: " << q.size() << "\n\n";

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

    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}