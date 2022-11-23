#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    string CName;
    string CNumber;
    Node(string CName, string CNumber)
    {
        this->next = NULL;
        this->CName = CName;
        this->CNumber = CNumber;
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

class ContactList
{
public:
    Node *head;
    Node *tail;
    ContactList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void PrintContacts()
    {
        if (head == NULL)
        {
            cout << "The Contact List Is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "Name: " << temp->CName << endl
                     << "Contact: " << temp->CNumber << endl
                     << endl;
                temp = temp->next;
            }
        }
    }
    void InsertContact(string CName, string CNumber)
    {
        if (head == NULL)
        {
            Node *NewNode = new Node(CName, CNumber);
            head = NewNode;
            tail = NewNode;
        }
        else
        {
            Node *temp = new Node(CName, CNumber);
            tail->next = temp;
            tail = temp;
        }
    }
    int TotalContacts()
    {
        if (head == NULL)
        {
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
    void DeleteByName(string CName)
    {
        if (head == NULL)
        {
            cout << "Contact List Is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (CName != temp->next->CName)
            {
                temp = temp->next;
            }
            Node *NodeToDelete = temp->next;
            temp->next = temp->next->next;
            NodeToDelete->next = NULL;
            delete NodeToDelete;
        }
    }
    void DeleteByNumber(string CNumber)
    {
        if (head == NULL)
        {
            cout << "Contact List Is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (CNumber != temp->next->CNumber)
            {
                temp = temp->next;
            }
            Node *NodeToDelete = temp->next;
            temp->next = temp->next->next;
            NodeToDelete->next = NULL;
            delete NodeToDelete;
        }
    }
};

int main()
{
    ContactList CL1;
    CL1.InsertContact("Rudransh Rajpurohit", "+91-8181816477");
    CL1.InsertContact("Devika Solanki", "+91-8181816478");
    CL1.InsertContact("Shreyans Sethia", "+91-8181816479");
    CL1.InsertContact("Samriddhi Srivastava", "+91-8181816476");
    CL1.InsertContact("Prince Poonia", "+91-8181816474");
    CL1.InsertContact("Chaitya Khanna", "+91-8181816473");
    CL1.DeleteByName("Samriddhi Srivastava");
    CL1.DeleteByNumber("+91-8181816474");
    CL1.InsertContact("Prince Poonia", "+91-8181816474");
    CL1.PrintContacts();
    cout << CL1.TotalContacts();
}