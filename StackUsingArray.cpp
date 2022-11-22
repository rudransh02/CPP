#include <iostream>
using namespace std;

#define STACKSIZE 10

class Stack
{
public:
    int top;
    int array[STACKSIZE];
    Stack()
    {
        this->top = -1;
    }
    void Traverse()
    {
        if (top == -1)
        {
            cout << "Stack Underflowed!" << endl;
            return;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
    bool IsFull()
    {
        if (top == STACKSIZE - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool IsEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Push(int data)
    {
        if (top < STACKSIZE - 1)
        {
            top++;
            array[top] = data;
            return;
        }
        else
        {
            cout << "Stack Overflowed!" << endl;
            return;
        }
    }
    void Pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflowed!" << endl;
            return;
        }
        else if (top == 0)
        {
            array[top] = 0;
            top = -1;
        }
        else
        {
            array[top] = 0;
            top--;
        }
    }
    int Peek()
    {
        if (top == -1)
        {
            return 0;
        }
        else
        {
            return array[top];
        }
    }
};

int main()
{
    Stack S1;
    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);
    S1.Push(50);
    S1.Push(60);
    S1.Push(70);
    S1.Push(80);
    S1.Push(90);
    S1.Push(100);
    S1.Traverse();
    cout << S1.IsFull();
}