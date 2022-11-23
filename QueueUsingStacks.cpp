#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
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

class Stack
{
public:
    Node *top;
    int size;
    Stack()
    {
        this->size = 0;
        this->top = NULL;
    }
    void Push(int data)
    {
        if (top == NULL)
        {
            Node *NewNode = new Node(data);
            top = NewNode;
            size++;
            return;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = top;
            top = temp;
            size++;
        }
    }
    void Pop()
    {
        if (top == NULL)
        {
            cout << "The Stack Is Already Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
    }
    int Peek()
    {
        if (top == NULL)
        {
            cout << "The Stack Is Empty!" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    void Traverse()
    {
        if (top == NULL)
        {
            cout << "The Stack Is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

class Queue
{
public:
    Stack S1;
    Stack S2;
    void Enqueue(int data)
    {
        S1.Push(data);
    }
    void StacksToQueue()
    {
        int size = S1.size;
        int i = 0;
        while (i < size)
        {
            S2.Push(S1.Peek());
            S1.Pop();
            i++;
        }
    }
    void Traverse()
    {
        int size = S2.size;
        int i = 0;
        Node *temp = S2.top;
        while (i < size)
        {
            cout << temp->data << " ";
            temp = temp->next;
            i++;
        }
    }
    void Dequeue()
    {
        if (S2.top == NULL)
        {
            cout << "The Queue Is Empty!" << endl;
            return;
        }
        else
        {
            S2.Pop();
        }
    }
    int Size()
    {
        return S2.size;
    }
    int Peek()
    {
        return S2.Peek();
    }
};

int main()
{
    Queue Q1;
    Q1.Enqueue(1);
    Q1.Enqueue(2);
    Q1.Enqueue(3);
    Q1.Enqueue(4);
    Q1.Enqueue(5);
    Q1.Enqueue(6);
    Q1.Enqueue(7);
    Q1.Enqueue(8);
    Q1.Enqueue(9);
    Q1.Enqueue(10);
    Q1.StacksToQueue();
    Q1.Dequeue();
    Q1.Dequeue();
    Q1.Traverse();
    cout << Q1.Peek();
}