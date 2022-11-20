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
    Stack()
    {
        this->top = NULL;
    }
    void Traverse()
    {
        if (top == NULL)
        {
            cout << "The Stack Is Empty!";
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
    int Length()
    {
        if (top == NULL)
        {
            cout << "The Stack Is Empty!";
            return 0;
        }
        else
        {
            Node *temp = top;
            int count = 0;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    void Push(int data)
    {
        if (top == NULL)
        {
            Node *NewNode = new Node(data);
            top = NewNode;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = top;
            top = temp;
        }
    }
    void Pop()
    {
        if (top == NULL)
        {
            cout << "The Stack Is Already Empty!";
            return;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }
    int Peek()
    {
        if (top == NULL)
        {
            cout << "The Stack Is Empty!";
            return 0;
        }
        else
        {
            return top->data;
        }
    }
};

int main()
{
    Stack S1;
    S1.Push(50);
    S1.Push(40);
    S1.Push(30);
    S1.Push(20);
    S1.Push(10);
    cout << S1.Length();
}