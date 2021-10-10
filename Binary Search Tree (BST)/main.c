#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

void createnode(struct node* root,int data);
void PreOrder(struct node* root);
void InOrder(struct node *root);
void PostOrder(struct node *root);
struct node* search(struct node *root,int data);
struct node* findMax(struct node *root);
struct node* del(struct node *root,int data);


int main()
{
    int ch,data,n;
    struct node *root=NULL,*temp;
    do{
        printf("1.Create Node\n2.Insert Nodes\n3.Delete Nodes\n4.Search Nodes\n5.Display Tree\n6.Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("enter data\n");
                scanf("%d", &data);
                if(root == NULL)
                {
                    temp = (struct node*)malloc(sizeof(struct node));
                    temp->left=NULL;
                    temp->right=NULL;
                    temp->data=data;
                    root=temp;
                }
                else
                    createnode(root,data);
                break;
            case 2:
                if(root == NULL)
                    printf("First create tree\nGoto option 1 create a tree first\n");

                else
                {
                    printf("enter data\n");
                    scanf("%d", &data);
                    createnode(root,data);
                }
                break;
            case 3:
                printf("enter data\n");
                scanf("%d", &data);
                root=del(root,data);
                break;
            case 4:
                if(root == NULL)
                    printf("First create tree\nGoto option 1 create a tree first\n");
                else
                {
                    printf("enter search data\n");
                    scanf("%d", &data);
                    search(root,data);
                }
                break;
            case 5:
                printf("1.Inorder\n2.Preorder\n3.PostOrder\n");
                scanf("%d", &ch);
                switch(ch)
                {
                    case 1:
                        printf("InOrder: ");
                        InOrder(root);
                        printf("\n");
                        break;
                    case 2:
                        printf("PreOrder: ");
                        PreOrder(root);
                        printf("\n");
                        break;
                    case 3:
                        printf("PostOrder: ");
                        PostOrder(root);
                        printf("\n");
                        break;
                }
                break;
            case 6:
                n=6;
                break;
        }
    }while(n!=6);
    return 0;
}

void createnode(struct node* root,int data)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    while(root != NULL)
    {
        if(data < root->data)
        {
            if(root->left != NULL)
                root = root->left;
            else
            {
                root->left = temp;
                break;
            }
        }
        else if(data > root->data)
        {
            if(root->right != NULL)
                root = root->right;
            else
            {
                root->right = temp;
                break;
            }
        }

    }
};
void PreOrder(struct node *root)
{
    if(root)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void InOrder(struct node *root)
{
    if(root)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
void PostOrder(struct node *root)
{
    if(root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
struct node* search(struct node *root,int data)
{
    struct node *ptr=root;
    while(root)
    {
        if(root->data == data)
        {
            printf("Data found %d\n",root->data);
            return ptr;
        }
        else if(data < root->data)
        {
            ptr = root;
            root = root->left;
        }
        else
        {
            ptr = root;
            root = root->right;
        }
    }
    printf("Data not found");
    return root;
};
struct node* findMax(struct node *root)
{
    if (root->right == NULL || root == NULL)
        return root;
    else
        return findMax(root->right);
};
struct node* del(struct node *root,int data)
{
    struct node *ptr;
	if(root==NULL)
		printf("\n%d is not present\n", data);
	else if(data < root->data)
		 root->left =  del(root->left, data);
	else if(data > root->data)
		 root->right = del(root->right, data);
	else
	{
		if(root->left && root->right)
		{
			ptr = findMax(root->left);
			root->data = ptr->data;
            root->left = del(root->left, ptr->data);
		}
        else
		{
			ptr = root;
			if(root->left==NULL && root->right==NULL)
			{
                free(ptr);
                root = NULL;
			}
			else if(root->left!=NULL)
			{
                struct node* temp=root->left;
                free(root);
                return temp;
			}
			else
			{
                struct node* temp= root->right;
                free(root);
                return temp;
			}
		}
	}
	return root;

}



