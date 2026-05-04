#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class SLL
{
    Node *head;
    int count;

public:
    SLL() : head(nullptr), count(0) {}

    ~SLL()
    {
        while (head)
        {
            Node *t = head;
            head = head->next;
            delete t;
        }
    }

    void insertFront(int val)
    {
        Node *n = new Node(val);
        n->next = head;
        head = n;
        count++;
    }

    void insertBack(int val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = n;
        }
        else
        {
            Node *curr = head;
            while (curr->next)
                curr = curr->next;
            curr->next = n;
        }
        count++;
    }

    void insertAt(int val, int pos)
    {
        if (pos < 0 || pos > count)
        {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 0)
        {
            insertFront(val);
            return;
        }
        Node *n = new Node(val);
        Node *curr = head;
        for (int i = 0; i < pos - 1; i++)
            curr = curr->next;
        n->next = curr->next;
        curr->next = n;
        count++;
    }

    void deleteFront()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        Node *t = head;
        head = head->next;
        delete t;
        count--;
    }

    void deleteBack()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            count--;
            return;
        }
        Node *curr = head;
        while (curr->next->next)
            curr = curr->next;
        delete curr->next;
        curr->next = nullptr;
        count--;
    }

    void deleteAt(int pos)
    {
        if (pos < 0 || pos >= count)
        {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 0)
        {
            deleteFront();
            return;
        }
        Node *curr = head;
        for (int i = 0; i < pos - 1; i++)
            curr = curr->next;
        Node *t = curr->next;
        curr->next = t->next;
        delete t;
        count--;
    }

    bool search(int val)
    {
        Node *curr = head;
        int pos = 0;
        while (curr)
        {
            if (curr->data == val)
            {
                cout << val << " found at position " << pos << "\n";
                return true;
            }
            curr = curr->next;
            pos++;
        }
        cout << val << " not found\n";
        return false;
    }

    void reverse()
    {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display()
    {
        if (!head)
        {
            cout << "Empty\n";
            return;
        }
        for (Node *c = head; c; c = c->next)
            cout << c->data << (c->next ? " -> " : " -> null\n");
    }

    int size() { return count; }
    bool isEmpty() { return !head; }
};

int main()
{
    SLL list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertFront(5);
    list.insertAt(15, 2);
    list.display();
    cout << "Size: " << list.size() << "\n";

    list.search(15);
    list.search(99);

    list.deleteFront();
    list.deleteBack();
    list.deleteAt(1);
    list.display();

    list.insertBack(40);
    list.insertBack(50);
    list.reverse();
    list.display();

    return 0;
}