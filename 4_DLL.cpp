//Doubly Linked List Data Structure
#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL
{
    private:
        node *start;
    public:
        DLL(); //default constructor
        DLL(DLL&); //deep copy constructor
        DLL& operator=(DLL&); //copy assignment operator
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        node* search(int);
        void edit(node*,int data);
        int count();
        void printAllData();
        ~DLL();
};
DLL::DLL()
{
    start=NULL;
}
DLL::DLL(DLL &list)
{
    node *t=list.start;
    start=NULL;
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    }
}
DLL& DLL::operator=(DLL &list)
{
    node *t=list.start;
    while(start!=NULL)
        deleteFirst();
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    }
    return (*this);
}
void DLL::insertAtFirst(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=NULL;
    n->next=start;
    if(start)
        start->prev=n;
    start=n;
}
void DLL::insertAtLast(int data)
{
    node *n=new node;
    node *t;
    n->item=data;
    n->next=NULL;
    if(!start)
    {
        n->prev=NULL;
        start=n;
    }
    else{
        t=start;
        while(t->next)
            t=t->next;
        t->next=n;
        n->prev=t;
    }
}
void DLL::insertAfter(node *t,int data)
{
    node *n=new node;
    n->item=data;
    try{
        if(!t)
            throw 1;
        n->prev=t;
        n->next=t->next;
        if(t->next!=NULL)
            t->next->prev=n;
        t->next=n;
    }
    catch(int e)
    {
        cout<<"This node is invalid";
    }
}
void DLL::deleteFirst()
{
    node *t=start;
    if(t)
    {
        start=t->next;
        start->prev=NULL;
        delete []t;
    }
    else
        cout<<"NULL";
}
void DLL::deleteLast()
{
    node *t=start;
    try{
        if(!t)
            throw 1;
        if(!t->next)
        {
            start=NULL;
            delete []t;
        }
        else
        {
            while(t->next->next)
                t=t->next;
            delete []t->next;
            t->next=NULL;
        }
    }
    catch(int e)
    {
        cout<<"NULL";
    }
}
void DLL::deleteNode(node *t)
{
    try{
        if(!t)
            throw 1;
        if(start==t)
        {
            start=t->next;
            delete []t;
        }
        else{
            t->prev->next=t->next;
            t->next->prev=t->prev;
            delete []t;
        }
    }
    catch(int e)
    {
        cout<<"This node is invalid";
    }
}
node* DLL::search(int data)
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
void DLL::edit(node *t,int data)
{
    if(t)
        t->item=data;
    else
        cout<<"This node is invalid";
}
int DLL::count()
{
    node *t=start;
    int i=0;
    if(!t)
        return i;
    for(i=1;t->next;i++)
        t=t->next;
    return i;
}
void DLL::printAllData()
{
    node *t=start;
    try{
        if(!t)
            throw 1;
        for(int i=1;t;i++)
        {
            cout<<i<<". "<<t->item<<endl;
            t=t->next;
        }
    }
    catch(int e)
    {
        cout<<"NULL";
    }
}
DLL::~DLL()
{
    while(start)
        deleteFirst();
}
int main()
{
    DLL a1,a2;
    a1.insertAtFirst(100);
    a1.insertAtLast(300);
    a1.insertAfter(a1.search(100),200);
    cout<<"data of a1:-"<<endl;
    a1.printAllData();
    a1.deleteNode(a1.search(200));
    a1.printAllData();
    
}