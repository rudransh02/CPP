#include <iostream>
using namespace std;

#define QueueSize 10

class Queue
{
    public:
    int front;
    int rear;
    int array[QueueSize];
    Queue()
    {
        front = 0;
        rear = 0;
    }
    void Enqueue(int data)
    {
        if (rear == QueueSize - 1)
        {
            cout << "Queue Is Full!" << endl;
            return;
        }
        else
        {
            array[rear] = data;
            rear++;
        }
    }
    void Dequeue()
    {
        if (rear <= front)
        {
            cout << "Queue Is Empty!" << endl;
            return;
        }
        else
        {
            array[front] = 0;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }
    void Traverse()
    {
        if (rear <= front)
        {
            cout << "The Queue Is Empty!" << endl;
            return;
        }
        else
        {
            int i = front;
            while (i < rear)
            {
                cout << array[i] << " ";
                i++;
            }
            cout << endl;
        }
    }
    bool IsFull()
    {
        if (rear >= QueueSize - 1)
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
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
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
    Q1.Dequeue();
    Q1.Dequeue();
    Q1.Dequeue();
    Q1.Dequeue();
    cout << Q1.IsEmpty() << endl;
    Q1.Traverse();
}