#include<iostream>

/*Program for implementing insertion in a binary search tree in C++
and printing using inorder traversal to verify
-Prakhar Gautam*/


struct node
{
    int data;
    node *left;
    node *right;
};

node* getnode(int item)
{
    node *new1;
    new1= new node;
    new1->data=item;
    new1->left=NULL;
    new1->right=NULL;
    return new1;
}
node* insert1(node *root, node *new1)
{
    if(root->data>new1->data)
    {
        if(root->left==NULL)
            root->left=new1;
        else
            insert1(root->left,new1);
    }
    else
    {
        if(root->right==NULL)
            root->right=new1;
        else
            insert1(root->right,new1);
    }
    return root;
}

node* create(node *root, int item)
{
    if(root==NULL)
    {
        root= new node;
        root->data=item;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        node *new1=getnode(item);
        root=insert1(root,new1);
    }
    return root;

}



void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}



int main()
{
    node *root =NULL;
    //entries in the tree will be- 20, 55, 12, 5, 8, 31, 48
    int data[7]= {66,2,99,5,8,31,48};
    for(int i=0; i<7; i++)
        root=create(root,data[i]);

    inorder(root);


    return 0;
}
