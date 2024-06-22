//Binary Search Tree Data-Structure
#include<iostream>
#include<stdlib.h>
using namespace std;
#define EMPTY_TREE 1
#define DATA_NOT_FOUND 2
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
    private:
        node *root;
        void recPreorder(node*);
        void recInorder(node*);
        void recPostorder(node*);
        void preorderCopy(BST&,node*);
        node* createNode(int);
    public:
        BST();
        BST(BST&);
        BST& operator=(BST&);
        bool isEmpty();
        void insert(int);
        void preOrder();
        void inOrder();
        void postOrder();
        void del(int);
        node* serach(int);
        ~BST();
};
BST::BST()
{
    root=NULL;
}
void BST::preorderCopy(BST &b,node *ptr)
{
    if(ptr)
    {
        b.insert(ptr->item);
        preorderCopy(b,ptr->left);
        preorderCopy(b,ptr->right);
    }
}
BST::BST(BST &bst)
{
    root=NULL;
    if(bst.root)
    {
        bst.preorderCopy(*this,bst.root);
    }
}
BST& BST::operator=(BST &bst)
{
    while(root)
        del(root->item);
    bst.preorderCopy(*this,bst.root);
    return *this;
}
bool BST::isEmpty()
{
    return root==NULL;
}
node* BST::createNode(int data)
{
    node *n=new node;
    n->left=NULL;
    n->item=data;
    n->right=NULL;
    return n;
}
void BST::insert(int data)
{
   node *ptr;
   if(root==NULL)
   {
        node *N;
        N=createNode(data);
        root=N;
   }
   else
   {
        bool flag=true;
        ptr=root;
        while(flag)
        {
            if(data==ptr->item) //this data is already exits in the tree
                break;
            if(data<ptr->item) //left subtree
            {
                if(ptr->left==NULL)
                {
                    node *N=createNode(data);
                    ptr->left=N;
                    flag=false;
                }
                else
                    ptr=ptr->left;
            }
            else //right subtree
            {
                if(ptr->right==NULL)
                {
                    node *N=createNode(data);
                    ptr->right=N;
                    flag=false;
                }
                else
                    ptr=ptr->right;
            }
        }
   }
}
void BST::del(int data)
{
    node *ptr,*parptr;
    if(root==NULL)
    {
        throw EMPTY_TREE;
    }
    parptr=NULL;
    ptr=root;
    while(ptr)
    {
        if(ptr->item==data)
            break;
        if(data<ptr->item)
        {
            parptr=ptr;
            ptr=ptr->left;
        }
        else
        {
            parptr=ptr;
            ptr=ptr->right;
        }
    }
    if(ptr==NULL)
    {
        throw DATA_NOT_FOUND;
    }
    if(parptr==NULL&&ptr!=NULL) //root node to be deleted
    {
        if(ptr->left==NULL&&ptr->right==NULL) //No child
        {
            delete ptr;
            root=NULL;
        }
        else if(ptr->left&&ptr->right) //Two children
        {
            node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left!=NULL)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            //Now delete successor
            if(suc==parsuc->left)
                parsuc->left=suc->right;
            else
                parsuc->right=suc->right;
            delete suc;
        }
        else //One children
        {
            if(ptr->left)
                root=ptr->left;
            else
                root=ptr->right;
            delete ptr;
        }
    }
    else //node to be deleted is not a root node
    {
        if(ptr->left==NULL&&ptr->right==NULL) //No child
        {
            if(ptr==parptr->left) //ptr is left child of parptr
            {
                parptr->left=NULL;
                delete ptr;
            }
            else //ptr is right child of parptr
            {
                parptr->right=NULL;
                delete ptr;
            }
        }
        else if(ptr->left&&ptr->right) //Two children
        {
            node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left!=NULL)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            //Now delete successor
            if(suc==parsuc->left)
                parsuc->left=suc->right;
            else
                parsuc->right=suc->right;
            delete suc;
        }
        else //One child
        {
            if(ptr==parptr->left) //ptr is left child of parptr
            {
                if(ptr->left)
                    parptr->left=ptr->left;
                else
                    parptr->left=ptr->right;
                delete ptr;
            }
            else //ptr is right child of parptr
            {
                if(ptr->left)
                    parptr->right=ptr->right;
                else
                    parptr->right=ptr->right;
                delete ptr;
            }
        }
    }
}
void BST::recPreorder(node *ptr)
{
    if(ptr)
    {
        cout<<ptr->item<<" ";
        recPreorder(ptr->left);
        recPreorder(ptr->right);
    }
}
void BST::recInorder(node *ptr)
{
    if(ptr)
    {
        recInorder(ptr->left);
        cout<<ptr->item<<" ";
        recInorder(ptr->right);
    }
}
void BST::recPostorder(node *ptr)
{
    if(ptr)
    {
        recPostorder(ptr->left);
        recPostorder(ptr->right);
        cout<<ptr->item<<" ";
    }
}
void BST::preOrder()
{
    recPreorder(root);
}
void BST::inOrder()
{
    recInorder(root);
}
void BST::postOrder()
{
    recPostorder(root);
}
node* BST::serach(int data)
{
    node *ptr=root;
    while(ptr)
    {
        if(ptr->item==data)
            return ptr;
        if(data<ptr->item) //left subtree
            ptr=ptr->left;
        else //right subtree
            ptr=ptr->right;
    }
    return NULL;
}
BST::~BST()
{
    while(root)
        del(root->item);
}
int main()
{
    BST b1,b3;
    b1.insert(50);
    b1.insert(30);
    b1.insert(70);
    b1.insert(60);
    b1.insert(90);
    b1.insert(10);
    b1.insert(20);
    b1.insert(15);
    b1.insert(25);
    b1.insert(80);
    b1.insert(75);
    b1.insert(85);
    b1.preOrder(); 
    cout<<endl;
    b1.del(70); //two children
    b1.del(10); //one child
    b1.del(60); //No child
    b1.preOrder();
    cout<<endl;
    BST b2=b1;
    b2.preOrder();
    cout<<endl;
    b3=b1;
    b3.preOrder();
}