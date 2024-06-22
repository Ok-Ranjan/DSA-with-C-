//CIRCULAR DOUBLY LINKED LIST DATA STRUCTURE
#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
    private:
        node *last;
    public:
        CDLL(); //default constructor
        CDLL(CDLL&); //deep copy constructor
        CDLL& operator=(CDLL&); //copy assignment operator
        void insertAtstart(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deletelast();
        void deleteNode(node*);
        node* search(int);
        void getAllItem();
        int count();
        ~CDLL();
};
CDLL::CDLL()
{
    last=NULL;
}
CDLL::CDLL(CDLL &list)
{
    node *t=list.last;
    last=NULL;
    if(t)
    {
        while(t->prev!=list.last)
        {
            insertAtstart(t->item);
            t=t->prev;
        }
        insertAtstart(t->item);
    }
}
CDLL& CDLL::operator=(CDLL &list)
{
    node *t=list.last;
    while(last)
        deleteFirst();
    if(t)
    {
        while(t->prev!=list.last)
        {
            insertAtstart(t->item);
            t=t->prev;
        }
        insertAtstart(t->item);
    }
    return (*this);
}
void CDLL::insertAtstart(int data)
{
    node *n=new node;
    n->item=data;
    if(last!=NULL)
    {
        n->prev=last;
        n->next=last->next;
        last->next->prev=n;
        last->next=n;
    }
    else{
        n->prev=n;
        n->next=n;
        last=n;
    }
}
void CDLL::insertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(last!=NULL)
    {
        last->next->prev=n;
        n->next=last->next;
        last->next=n;
        n->prev=last;
        last=n;
    }
    else{
        n->prev=n;
        n->next=n;
        last=n;
    }
}
void CDLL::insertAfter(node *t,int data)
{
    node *n=new node;
    n->item=data;
    try{
        if(!t)
            throw 1;
        if(last==t)
            insertAtLast(data);
        else{
            n->prev=t;
            n->next=t->next;
            t->next->prev=n;
            t->next=n;
        }     
    }
    catch(int e)
    {
        cout<<"Node is invalid 'so don't run insertAfter'"<<endl;
    }
}
void CDLL::deleteFirst()
{
    try{
        if(!last)
            throw 1;
        if(last==last->next)
        {
            delete []last;
            last=NULL;
        }
        else{
            node *r=last->next;
            r->next->prev=last;
            last->next=r->next;
            delete []r;
        }
    }
    catch(int e)
    {
        cout<<"Node is Empty,so don't call delete\n";
    }
}
void CDLL::deletelast()
{
    try{
        if(!last)
            throw 1;
        if(last==last->next)
        {
            delete  []last;
            last=NULL;
        }
        else{
            node *r=last->prev;
            r->next=last->next;
            last->next->prev=r;
            delete []r;
            last=r;
        }
    }
    catch(int e)
    {
        cout<<"Empty,So don't delete\n";
    }
}
void CDLL::deleteNode(node *t)
{
    try{
        if(!t)
            throw 1;
        if(t->prev==t)
        {
            last=NULL;
            delete []t;
        }
        else{
            t->prev->next=t->next;
            t->next->prev=t->prev;
            if(t==last)
                last=t->prev;
            delete []t;
        }
    }
    catch(int e)
    {
        cout<<"Empty or invalid node\n";
    }
}
node* CDLL::search(int data)
{
    node *t=last->next;
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
int CDLL::count()
{
    node *t=last;
    int count=0;
    try{
        if(!t)
            throw 1;
        while(t->prev!=last)
        {
            count++;
            t=t->prev;
        }
        count++;
        // return count;
    }
    catch(int e)
    {
        cout<<"Empty"<<endl;
    }
    return count;
}
void CDLL::getAllItem()
{
    try{
        if(!last)
            throw 1;
        node *t=last->next;
        int i=0;
        while(t!=last)
        {
            cout<<++i<<". "<<t->item<<endl;
            t=t->next;
        }
        cout<<++i<<". "<<t->item<<endl;
    }  
    catch(int e)
    {
        cout<<"Empty"<<endl;
    }
}
CDLL::~CDLL()
{
    while(last)
        deleteFirst();
}
int main()
{
    CDLL a1,c1;;
    a1.insertAtLast(30);
    a1.insertAtstart(10);
    a1.insertAfter(a1.search(10),20);
    a1.deletelast();
    cout<<a1.count()<<endl;
    a1.getAllItem();   
    CDLL b1=a1;
    b1.getAllItem(); 
    c1=b1;
    c1.getAllItem();
}