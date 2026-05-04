#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int val)
    {
        if (count == capacity)
        {
            cout << "Queue Overflow! Cannot enqueue " << val << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
        cout << val << " enqueued to queue\n";
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "Queue Underflow! Queue is empty\n";
            return;
        }
        cout << arr[front] << " dequeued from queue\n";
        front = (front + 1) % capacity;
        count--;
    }

    int peek()
    {
        if (count == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue (front -> rear): ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % capacity] << " ";
        cout << endl;
    }
};

int main()
{
    Queue q(5);

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