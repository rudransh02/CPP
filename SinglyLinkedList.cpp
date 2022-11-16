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

class LL
{
public:
    Node *head;
    Node *tail;
    LL()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    int Length()
    {
        if (head == NULL)
        {
            cout << "The List Is Empty!";
            return 0;
        }
        else
        {
            Node *temp = head;
            int count = 0;
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
    void InsertAtTail(int data)
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
            tail->next = temp;
            tail = tail->next;
        }
    }
    void InsertAtPosition(int position, int data)
    {
        if (position == 1 || position == 0)
        {
            InsertAtHead(data);
            return;
        }
        else if (position <= Length() + 1)
        {
            Node *temp = head;
            int count = 1;
            while (count < position - 1)
            {
                temp = temp->next;
                count++;
            }
            if (temp->next == NULL)
            {
                InsertAtTail(data);
                return;
            }
            else
            {
                Node *NodeToInsert = new Node(data);
                NodeToInsert->next = temp->next;
                temp->next = NodeToInsert;
            }
        }
        else
        {
            cout << "Position You Entered Was Out Of Range!";
            return;
        }
    }
    void DeleteAtPosition(int position)
    {
        if (position == 1 || position == 0)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else if (position <= Length())
        {
            Node *current = head;
            Node *previous = NULL;
            int count = 1;
            while (count < position)
            {
                previous = current;
                current = current->next;
                count++;
            }
            previous->next = current->next;
            current->next = NULL;
            delete current;
        }
        else
        {
            cout << "Position You Entered Was Out Of Range!";
            return;
        }
    }
};

int main()
{
    LL LL1;
    LL1.InsertAtHead(50);
    LL1.Traverse();
    LL1.InsertAtHead(40);
    LL1.Traverse();
    LL1.InsertAtHead(30);
    LL1.Traverse();
    LL1.InsertAtHead(20);
    LL1.Traverse();
    LL1.InsertAtHead(10);
    LL1.Traverse();
    LL1.InsertAtTail(60);
    LL1.Traverse();
    LL1.InsertAtTail(80);
    LL1.Traverse();
    LL1.InsertAtTail(90);
    LL1.Traverse();
    LL1.InsertAtTail(100);
    LL1.Traverse();
    LL1.InsertAtPosition(7, 70);
    LL1.Traverse();
    LL1.InsertAtPosition(11, 110);
    LL1.Traverse();
    LL1.DeleteAtPosition(11);
    LL1.Traverse();
}