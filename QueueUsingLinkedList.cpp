#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
    }
};

class Queue
{
    public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    int Length()
    {
        if (front == NULL)
        {
            cout << "The Queue Is Empty!";
            return 0;
        }
        else
        {
            int count = 0;
            Node *temp = front;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    void Traverse()
    {
        if (front == NULL)
        {
            cout << "The Queue Is Empty!";
            return;
        }
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void Enqueue(int data)
    {
        if (front == NULL)
        {
            Node *NewNode = new Node(data);
            front = NewNode;
            rear = NewNode;
        }
        else
        {
            Node *temp = new Node(data);
            rear->next = temp;
            rear = temp;
        }
    }
    void Dequeue()
    {
        if (front == NULL)
        {
            cout << "The Queue Is Already Empty!";
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
        }
    }
    bool IsEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Peek()
    {
        if (front  == NULL)
        {
            cout << "The Queue Is Empty!";
            return 0;
        }
        else
        {
            return front->data;
        }
    }
};

int main()
{
    Queue Q1;
    Q1.Enqueue(10);
    Q1.Traverse();
    Q1.Enqueue(20);
    Q1.Traverse();
    Q1.Enqueue(30);
    Q1.Traverse();
    Q1.Enqueue(40);
    Q1.Traverse();
    Q1.Enqueue(50);
    Q1.Traverse();
    Q1.Enqueue(60);
    Q1.Traverse();
    Q1.Enqueue(70);
    Q1.Traverse();
    Q1.Dequeue();
    Q1.Traverse();
    cout << Q1.Length() << endl;
    cout << Q1.Peek();
}