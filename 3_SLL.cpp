//Singly Linked List Data Structure
#include<iostream>
using namespace std;
struct node
{
    public:
        int item;
        node *next;
};
class SLL
{
    private:
        node *start;
    public:
        SLL(); //default constructor
        SLL(SLL &);//deep copy constructor
        SLL& operator=(SLL &); //copy assignment operator
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        void edit(node*,int);
        node* search(int);
        int count();
        void printAllData();
        ~SLL();
};
SLL::SLL()
{
    start=NULL;
}
SLL::SLL(SLL &list)
{
    node *t=list.start;
    start=NULL;
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    }
}
SLL& SLL::operator=(SLL &list)
{
    node *t=list.start;
    while(start)
        deleteFirst();
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    }
    return (*this);
}
void SLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::insertAtLast(int data)
{
    node *n=new node;
    node *t=start;
    n->item=data;
    n->next=NULL;
    if(t)
    {
        while(t->next)
            t=t->next;
        t->next=n;
    }
    else
        start=n;
}
void SLL::insertAfter(node *t,int data)
{
    if(t)
    {
        node *n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
    else
        cout<<"This node is invalid\n";
}
void SLL::deleteFirst()
{
    node *t;
    t=start;
    try{
        if(!t)
            throw 1;
        start=t->next;
        delete []t;
    }
    catch(int e)
    {
        cout<<"No node";
    }
}
void SLL::deleteLast()
{
    node *t;
    try{
        if(!start)
            throw 1;
        if(start->next==NULL)
        {
            delete []start;
            start=NULL;
        }
        else{
            t=start;
            while(t->next->next)
                t=t->next;
            delete []t->next;
            t->next=NULL;
        }
    }
    catch(int e)
    {
        cout<<"No node\n";
    }
}
void SLL::deleteNode(node *r)
{
    node *t;
    try{
        if(start==NULL||r==NULL)
            throw 1;
        if(start==r)
            deleteFirst();
        else
        {
            t=start;
            while(t->next!=r)
                t=t->next;
            t->next=r->next;
            delete []r;
        }
    }
    catch(int e)
    {
        cout<<"This node is invalid\n";
    }
}
void SLL::edit(node *n,int data)
{
    if(n)
        n->item=data;
    else
        cout<<"This node is invalid\n";
}
node* SLL::search(int data)
{
    node *t=start;
    while(t)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
int SLL::count()
{
    node *t=start;
    int i=0;
    if(!t)
        return i;
    for(i=1;t->next;i++)
        t=t->next;
    return i;
}
void SLL::printAllData()
{
    node *t=start;
    int j=1;
    try{
        if(!t)
            throw 1;
        while(t)
        {
            cout<<j<<". "<<t->item<<endl;
            t=t->next;
            j++;
        }
    }
    catch(int e)
    {
        cout<<"NULL";
    }
}
SLL::~SLL()
{
    while(start)
        deleteFirst();
}
int main()
{

}