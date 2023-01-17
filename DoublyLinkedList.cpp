#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
            this->previous = NULL;
            delete next;
            delete previous;
        }
    }
};

class DLL
{
public:
    Node *head;
    Node *tail;
    DLL()
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
            int count = 0;
            Node *temp = head;
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
            head->previous = temp;
            head = temp;
        }
    }
    void InsertAtTail(int data)
    {
        if (head == NULL)
        {
            InsertAtHead(data);
        }
        else
        {
            Node *temp = new Node(data);
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
    }
    void InsertAtPosition(int position, int data)
    {
        if (position == 0 || position == 1)
        {
            InsertAtHead(data);
            return;
        }
        else if (position <= Length() + 1)
        {
            int count = 1;
            Node *temp = head;
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
            Node *NodeToInsert = new Node(data);
            NodeToInsert->next = temp->next;
            NodeToInsert->previous = temp;
            temp->next->previous = NodeToInsert;
            temp->next = NodeToInsert;
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
            head->previous = NULL;
            temp->next = NULL;
            delete temp;
        }
        else if (position <= Length() + 1)
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
            current->next->previous = previous;
            current->next = NULL;
            current->previous = NULL;
            delete current;
        }
        else
        {
            cout << "Position You Entered Was Out Of Range!";
            return;
        }
    }
    void Reverse()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *current = head;
            Node *prev = NULL;
            Node *forward;
            while (current != NULL)
            {
                forward = current->next;
                current->next = prev;
                prev = current;
                current = forward;
            }
            tail = head;
            head = prev;
        }
    }
};

int main()
{
    DLL DLL1;
    DLL1.InsertAtHead(50);
    DLL1.InsertAtHead(40);
    DLL1.InsertAtHead(30);
    DLL1.InsertAtHead(20);
    DLL1.InsertAtHead(10);
    DLL1.InsertAtTail(60);
    DLL1.InsertAtTail(80);
    DLL1.InsertAtTail(90);
    DLL1.InsertAtPosition(7, 70);
    DLL1.Traverse();
    DLL1.DeleteAtPosition(5);
    DLL1.Traverse();
}