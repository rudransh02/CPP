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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *InsertIntoBST(Node *root, int data)
{
    // Creating New Node As The Root Of The Tree If No Node Already Exists
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // Inserting The Node At The Left Of The Root If The Data Is Smaller Than The Node Recursively
    if (data < root->data)
    {
        root->left = InsertIntoBST(root->left, data);
    }
    // Inserting The Node At The Right Of The Root If The Data Is Greate Than The Node Recursively
    else
    {
        root->right = InsertIntoBST(root->right, data);
    }
    return root;
}

void TakeInput(Node *&root)
{
    int data;
    cin >> data;
    // Keep Taking Input From User Until The User -1 As The Data To Insert
    while (data != -1)
    {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
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

bool SearchForNode(Node *root, int element)
{
    // Using A Queue To Implement And Store Data
    queue<Node *> Q;
    Q.push(root);
    // Repeat Untill The Queue Becomes Empty
    while (Q.empty() != true)
    {
        Node *temp = Q.front();
        Q.pop();
        // Comparing The Data Of Every Node With The Element And Returns True When Found Same
        if (temp->data == element)
        {
            return true;
        }
        // Pushing The Left Node Of The Root Into The Queue If Present
        if (temp->left != NULL)
        {
            Q.push(temp->left);
        }
        // Pushing The Right Node Of The Root Into The Queue If Present
        if (temp->right != NULL)
        {
            Q.push(temp->right);
        }
    }
    // Returns False If The Element Is Not Found
    return false;
}

int MinimumValue(Node *root)
{
    Node *temp = root;
    // Traversing The BST Until We Get To The Left Most Element Which Is The Smallest
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int MaximumValue(Node *root)
{
    Node *temp = root;
    // Traversing The BST Until We Get To The Right Most Element Which Is The Greatest
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// Two Ways To Delete Node With 2 Children:
// 1. Replace Node With Maximum Value Of Left Subtree
// 2. Replace Node With Minimum Value Of Right Subtree

Node *DeleteFromBST(Node *root, int element)
{
    if (root == NULL)
    {
        return root;
    }
    // If We Get To The Node Whose Data Is Equal To The Given Element
    if (root->data == element)
    {
        // If The Node We Want To Delete Has Zero Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // If The Node We Want To Delete Has One Right Child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // If The Node We Want To Delete Has One Left Child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // If The Node We Want To Delete Has Right As Well As Left Child
        else
        {
            int MinInBST = MinimumValue(root->right);
            root->data = MinInBST;
            root->right = DeleteFromBST(root->right, MinInBST);
            return root;
        }
    }
    // If The Data Of The Root We Are On Is Greater Than The Element Then We Will Go The Left Of The Tree
    else if (root->data > element)
    {
        root->left = DeleteFromBST(root->left, element);
    }
    // If The Data Of The Root We Are On Is Smaller Than The Element Then We Will Go The Right Of The Tree
    else
    {
        root->right = DeleteFromBST(root->right, element);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter The Data Into The Binary Search Tree: ";
    TakeInput(root);
    cout << "Levelorder Traversal: ";
    cout << endl;
    LevelOrderTraversal(root);
    DeleteFromBST(root, 36);
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
    cout << endl;
    cout << "Element Found Or Not: " << SearchForNode(root, 55);
    cout << endl;
    cout << "Maximum Value: " << MaximumValue(root) << endl;
    cout << "Minimum Value: " << MinimumValue(root) << endl;
    return 0;
}