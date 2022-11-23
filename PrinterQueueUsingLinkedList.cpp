#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    string data;
    Node(string data)
    {
        this->next = NULL;
        this->data = data;
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

class PrinterQueue
{
public:
    Node *front;
    Node *rear;
    PrinterQueue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void EnqueuePrint(string data)
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
    void PrintAndDequeue()
    {
        if (front == NULL)
        {
            cout << "The Printer Queue Is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = front;
            cout << "Printed: " << temp->data << endl << endl;
            front = front->next;
            temp->next = NULL;
            delete temp;
        }
    }
    int PrinterQueueLength()
    {
        if (front == NULL)
        {
            return 0;
        }
        else
        {
            Node *temp = front;
            int count = 0;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    void DisplayPrinterQueue()
    {
        if (front  == NULL)
        {
            cout << "The Printer Queue Is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    PrinterQueue PQ1;
    PQ1.EnqueuePrint("Aadhaar Card");
    PQ1.EnqueuePrint("Voter ID Card");
    PQ1.EnqueuePrint("Driving Licence");
    PQ1.EnqueuePrint("PAN Card");
    PQ1.EnqueuePrint("Bank Pass Book");
    PQ1.PrintAndDequeue();
    PQ1.EnqueuePrint("Driving Licence");
    cout << PQ1.PrinterQueueLength() << endl;
    PQ1.DisplayPrinterQueue();
}