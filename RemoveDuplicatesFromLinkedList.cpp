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

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert(int data)
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
            tail = temp;
        }
    }
    void traverse()
    {
        if (head == NULL)
        {
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
        }
    }
    void removeduplicates()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp1 = head;
            while (temp1 != NULL)
            {
                Node *temp2 = temp1->next;
                Node *previous = temp1;
                while (temp2 != NULL)
                {
                    if (temp1->data == temp2->data)
                    {
                        if (temp2->next == NULL)
                        {
                            previous->next = NULL;
                            tail = previous;
                        }
                        else
                        {
                            previous->next = temp2->next;
                            temp2 = temp2->next;
                        }
                    }
                    previous = previous->next;
                    temp2 = temp2->next;
                }
                temp1 = temp1->next;
            }
        }
    }
};

int main()
{
    LinkedList l;
    l.insert(10);
    l.insert(12);
    l.insert(18);
    l.insert(12);
    l.insert(106);
    l.insert(121);
    l.insert(18);
    l.insert(121);
    l.removeduplicates();
    l.traverse();
}