#include<iostream>
using namespace std;
#define EMPTY_LIST 1
struct node
{
    node *prev;
    int item;
    node *next;
};
class Deque
{
    private:
        node *front;
        node *rear;
    public:
        Deque();
        Deque(Deque&);
        Deque& operator=(Deque&);
        void insertAtFront(int);
        void insertAtRear(int);
        void delFront();
        void delRear();
        int getFront();
        int getRear();
        bool isEmpty();
        int count();
        ~Deque();
};
Deque::Deque()
{
    front=NULL;
    rear=NULL;
}
Deque::Deque(Deque &D)
{
    front=rear=NULL;
    node *t=D.front;
    while(t)
    {
        insertAtRear(t->item);
        t=t->next;
    }
}
Deque& Deque::operator=(Deque &D)
{
    while(front)
        delFront();
    node *t=D.front;
    while(t)
    {
        insertAtRear(t->item);
        t=t->next;
    }
    return *this;
}
void Deque::insertAtFront(int data)
{
    node *n=new node;
    n->item;
    n->prev=NULL;
    n->next=front;
    if(front==NULL)
    {
        front=n;
        rear=n;
    }
    else
    {
        front->prev=n;
        front=n;
    }
}
void Deque::insertAtRear(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    n->prev=rear;
    if(rear==NULL)
    {
        front=n;
        rear=n;
    }
    else
    {
        rear->next=n;
        rear=n;
    }
}
void Deque::delFront()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        if(front==rear)
        {
            delete []rear;
            front=rear=NULL;
        }
        else
        {
            node *t=front;
            front=front->next;
            front->prev=NULL;
            delete []t;
        }
    }
    catch(int e)
    {
        cout<<"Empty List/n";
    }
}
void Deque::delRear()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        if(front==rear)
        {
            delete []rear;
            front=rear=NULL;
        }
        else
        {
            node *t=rear;
            rear=rear->prev;
            rear->next=NULL;
            delete []t;
        }
    }
    catch(int e)
    {
        cout<<"Empty List\n";
    }
}
int Deque::getFront()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        return front->item;
    }
    catch(int e)
    {
        cout<<"Empty List";
    }
    return -1;
}
int Deque::getRear()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        return rear->item;
    }
    catch(int e)
    {
        cout<<"Empty List";
    }
    return -1;
}
bool Deque::isEmpty()
{
    return front==NULL;
}
int Deque::count()
{
    int c=0;
    node *t=front;
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;
}
Deque::~Deque()
{
    while(front)
        delFront();
}
int main()
{

}