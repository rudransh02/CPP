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

class CLL
{
public:
    Node *current;
    CLL()
    {
        this->current = NULL;
    }
    int Length()
    {
        if (current == NULL)
        {
            cout << "The List Is Empty!";
            return 0;
        }
        else
        {
            Node *temp = current;
            int count = 1;
            while (temp->next != current)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    void Traverse()
    {
        if (current == NULL)
        {
            cout << "The List Is Empty!";
            return;
        }
        else
        {
            Node *temp = current;
            while (temp->next != current)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
    }
    void InsertAfterNode(int node, int data)
    {
        if (current == NULL)
        {
            Node *NewNode = new Node(data);
            current = NewNode;
            current->next = current;
        }
        else
        {
            Node *temp = current;
            while (temp->data != node)
            {
                temp = temp->next;
            }
            Node *NodeToInsert = new Node(data);
            NodeToInsert->next = temp->next;
            temp->next = NodeToInsert;
        }
    }
    void DeleteNode(int node)
    {
        if (current == NULL)
        {
            cout << "The List Is Empty!";
            return;
        }
        else
        {
            Node *prev = current;
            Node *curr = prev->next;

            while (curr->data != node)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            if (curr == prev)
            {
                currentz = NULL;
            }
            else if (current == curr)
            {
                current = prev;
            }

            curr->next = NULL;
            delete curr;
        }
    }
};

int main()
{
    CLL CLL1;
    CLL1.InsertAfterNode(0, 50);
    CLL1.Traverse();
    CLL1.InsertAfterNode(50, 40);
    CLL1.Traverse();
    CLL1.InsertAfterNode(40, 30);
    CLL1.Traverse();
    CLL1.InsertAfterNode(30, 20);
    CLL1.Traverse();
    CLL1.InsertAfterNode(20, 10);
    CLL1.Traverse();
    CLL1.DeleteNode(50);
    CLL1.Traverse();
}