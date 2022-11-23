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
            next = NULL;
            delete next;
        }
    }
};

class SLL
{
public:
    Node *head;
    Node *tail;
    SLL()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void Traverse()
    {
        if (head == NULL)
        {
            cout << "The List Is Empty!";
            return;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void InsertAtHead(int data)
    {
        if (head == NULL)
        {
            Node *NewNode = new Node(data);
            head = NewNode;
            tail = NewNode;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
    }
};

SLL MergeAndSort2SLL(SLL SLL1, SLL SLL2)
{
    SLL1.tail->next = SLL2.head;
    Node *current = SLL1.head;
    while (current != NULL)
    {
        Node *forward = current->next;
        while (forward != NULL)
        {
            if (current->data > forward->data)
            {
                swap(current->data, forward->data);
            }
            forward = forward->next;
        }
        current = current->next;
    }
    return SLL1;
}

int main()
{
    SLL SLL1;
    SLL SLL2;
    SLL1.InsertAtHead(5);
    SLL1.InsertAtHead(1);
    SLL1.InsertAtHead(8);
    SLL1.InsertAtHead(3);
    SLL1.InsertAtHead(12);
    SLL2.InsertAtHead(35);
    SLL2.InsertAtHead(85);
    SLL2.InsertAtHead(7);
    SLL2.InsertAtHead(25);
    SLL1.Traverse();
    SLL2.Traverse();
    SLL SLL3 = MergeAndSort2SLL(SLL1, SLL2);
    SLL3.Traverse();
}