#include <cstddef>
#include <stdio.h>
#include <iostream>
#include <conio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

queue <int> PreOrder;
class Solution{
  public:
    void printPreorder(Node* Node)
    {
        if (Node == NULL)
            return;
        PreOrder.push(Node->data);
        printPreorder(Node->left);
        printPreorder(Node->right);
    }

    Node* newNode()
    {
        struct Node* nwnode;
        nwnode = (struct Node*)malloc(sizeof(struct Node));
        nwnode->left = nwnode->right = NULL;
        return nwnode;
    }

Node* binaryTreeToBST(Node *root)
{
    struct Node *temp,*newnode;
    temp = newNode();
    temp->data = PreOrder.front();
    PreOrder.pop();
    root = temp;
    while(!PreOrder.empty())
    {
        if(PreOrder.front()<temp->data)
        {
            while(temp->left!=NULL && PreOrder.front()<temp->data)
                temp=temp->left;
            if(temp->left == NULL)
            {
                newnode = newNode();
                newnode->data = PreOrder.front();
                temp->left=newnode;
            }
        }
        if(PreOrder.front()>temp->data)
        {
            while(temp->right!=NULL && PreOrder.front()>temp->data)
                temp=temp->right;
            if(temp->right == NULL)
            {
                newnode = newNode();
                newnode->data = PreOrder.front();
                temp->right=newnode;
            }
        }
        PreOrder.pop();
    }
    return root;
    }
    //Node *binaryTreeToBST (Node *root)
    //{
    //
    //}
};

// { Driver Code Starts.
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}
