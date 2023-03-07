#include <iostream>
using namespace std;

#define QueueSize 10

class CircularQueue
{
public:
    int front;
    int rear;
    int array[QueueSize];
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }
    void Enqueue(int data)
    {
        if ((front == 0 && rear == QueueSize - 1) || (rear == (front - 1) % (QueueSize - 1)))
        {
            return;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            array[rear] = data;
        }
        else if (rear == QueueSize - 1 && front != 0)
        {
            rear = 0;
            array[rear] = data;
        }
        else
        {
            rear++;
            array[rear] = data;
        }
    }
    void Dequeue()
    {
        if (front == -1)
        {
            return;
        }
        else if (front == rear)
        {
            array[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == QueueSize - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void Traverse()
    {
        if (front == -1)
        {
            return;
        }
        else if (front > rear)
        {
            int temp1 = front;
            while (temp1 < QueueSize)
            {
                cout << array[temp1++] << " ";
            }
            int temp2 = 0;
            while (temp2 <= rear)
            {
                cout << array[temp2++] << " ";
            }
        }
        else
        {
            int temp = front;
            while (temp <= rear)
            {
                cout << array[temp++] << " ";
            }
        }
    }
};

int main()
{
    CircularQueue CQ;
    CQ.Enqueue(10);
    CQ.Enqueue(20);
    CQ.Enqueue(30);
    CQ.Enqueue(40);
    CQ.Enqueue(50);
    CQ.Enqueue(60);
    CQ.Enqueue(70);
    CQ.Enqueue(80);
    CQ.Enqueue(90);
    CQ.Enqueue(100);
    CQ.Dequeue();
    CQ.Dequeue();
    CQ.Dequeue();
    CQ.Dequeue();
    CQ.Dequeue();
    CQ.Enqueue(10);
    CQ.Enqueue(20);
    CQ.Dequeue();
    CQ.Traverse();
}