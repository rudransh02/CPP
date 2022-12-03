#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *BuildTree(Node *root)
{
    int data;
    cout << "Enter The Data To Insert In The Node: ";
    cin >> data;
    root = new Node(data);
    // Returns NULL Value And Backtrack When -1 Is Given As Input
    if (data == -1)
    {
        return NULL;
    }
    // Inserting Data Into The Left And The Right Nodes Of The Root Recursively
    cout << "Enter The Data To Insert In Left Node Of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter The Data To Insert In Right Node Of " << data << endl;
    root->right = BuildTree(root->right);
    return root;
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> Q1;
    // Pushing The Root Into The Queue
    Q1.push(root);
    // Line Break Depicting The End Of One Level Of Traversal
    Q1.push(NULL);
    while (Q1.empty() != true)
    {
        // Storing Queue's Front Into Temp
        Node *temp = Q1.front();
        // Popping Queue
        Q1.pop();
        // Add A Line Break If Temp = NULL To Depict Completion Of Printing Of One Level
        if (temp == NULL)
        {
            cout << endl;
            // Adding NULL Value To Queue To Depict Completion Of One Level Of Traversal
            if (Q1.empty() != true)
            {
                Q1.push(NULL);
            }
        }
        // Printing The Data Of Temp And Storing The Values Of Left And Right Nodes Into The Queue
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                Q1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                Q1.push(temp->right);
            }
        }
    }
}

void PreorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // Node -> Left -> Right
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void InorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // Left -> Node -> Right
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

void PostorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // Left -> Right -> Node
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    cout << endl;
    cout << "Levelorder Traversal: ";
    cout << endl;
    LevelOrderTraversal(root);
    cout << "Preorder Traversal: ";
    PreorderTraversal(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    InorderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    PostorderTraversal(root);
    return 0;
}