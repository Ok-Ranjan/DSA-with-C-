//Circular Linked List Data Structure
#include<iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CLL
{
    private:
        node *last;
    public:
        CLL(); //default constructor
        CLL(CLL&); //deep copy constructor
        CLL& operator=(CLL&); //copy assignment operator
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        node* searchNode(int);
        int count();
        void getAllData();
        ~CLL();
};
CLL::CLL()
{
    last=NULL;
}
CLL::CLL(CLL &list)
{
    last=NULL;
    if(list.last)
    {
        node *t=list.last->next;
        while(t->next!=list.last->next)
        {
            insertAtLast(t->item);
            t=t->next;
        }
        insertAtLast(t->item);
    }
}
CLL& CLL::operator=(CLL &list)
{
    while(last)
        deleteFirst();
    if(list.last)
    {
        node *t=list.last->next;
        while(t->next!=list.last->next)
        {
            insertAtLast(t->item);
            t=t->next;
        }
        insertAtLast(t->item);
    }
    return (*this);
}
void CLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(last)
    {
        n->next=last->next;
        last->next=n;
    }
    else
    {
        last=n;
        n->next=last;
    }
}
void CLL::insertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(last)
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
    else
    {
        last=n;
        n->next=last;
    }
}
void CLL::insertAfter(node *t,int data)
{
    try{
        if(!t)
            throw 1;
        node *n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
        if(last==t)
            last=n;
    }
    catch(int e)
    {
        cout<<"Invalid Node";
    }
}
void CLL::deleteFirst()
{
    try{
        if(!last)
            throw 1;
        node *t=last->next;
        last->next=t->next;
        if(last==t)
            last=NULL;
        delete []t;
    }
    catch(int e)
    {
        cout<<"No Data in list";
    }
}
void CLL::deleteLast()
{
    try{
        if(!last)
            throw 1;
        node *t=last->next;
        if(last==t)
        {
            last=NULL;
            delete []t;
        }
        else
        {
            while(t->next!=last)
                t=t->next;
            t->next=last->next;
            delete []last;
            last=t;
        }
    }
    catch(int e)
    {
        cout<<"No data in list";
    }
}
void CLL::deleteNode(node *t)
{
    try{
        if(!t)
            throw 1;
        if(last==t)
            deleteLast();
        else if(t==last->next)
            deleteFirst();
        else
        {
            node *r=last->next;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete []t;
        }
    }
    catch(int e)
    {
        cout<<"No node/data in this list";
    }
}
node* CLL::searchNode(int data)
{
    node *t=last->next;
    if(!last)
        return NULL;
    while(t!=last)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    if(t->item==data)
        return t;
    return NULL;
}
int CLL::count()
{
    int i=0;
    if(last)
    {
        node *t=last->next;
        for(i=1;t->next!=last->next;i++)
            t=t->next;
        return i;
    }
    return i;
}
void CLL::getAllData()
{
    if(!last)
        cout<<"No Data in list";
    else
    {
        int i=1;
        node *t=last->next;
        for(i=1;t->next!=last->next;i++)
        {
            cout<<i<<". "<<t->item<<endl;
            t=t->next;
        }
        cout<<i<<". "<<t->item<<endl;
    }
}
CLL::~CLL()
{
    while(last)
        deleteFirst();
}
int main()
{
    CLL a1,b1;
    a1.insertAtLast(200);
    a1.insertAfter(a1.searchNode(200),300);
    a1.insertAtStart(100);
    a1.getAllData();
    CLL c1=b1=a1;
    cout<<"List of b1:-"<<endl;
    b1.getAllData();
    cout<<"List of c1:-"<<endl;
    c1.getAllData();
}