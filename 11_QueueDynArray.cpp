#include<iostream>
using namespace std;
#define INVALID_QUEUE_STATE 1
#define EMPTY_LIST 2
class Queue 
{
    private:
        int capacity;
        int front,rear;
        int *ptr;
        void doubleQueue();
        void halfQueue();
    public:
        Queue(int);
        Queue(Queue &);
        Queue& operator=(Queue&);
        void insert(int);
        void del();
        bool isFull();
        bool isEmpty();
        int getFront();
        int getBack();
        int count();
        ~Queue();
};
Queue::Queue(int cap)
{
    capacity=cap;
    front=rear=-1;
    if(cap>0)
        ptr=new int[cap];
    else
        ptr=NULL;
}
Queue::Queue(Queue &Q)
{
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    ptr=new int[capacity];
    for(int i;i<capacity;i++)
        ptr[i]=Q.ptr[i];
}
Queue& Queue::operator=(Queue &Q)
{
    if(ptr)
        delete []ptr;
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    ptr=new int[capacity];
    for(int i;i<capacity;i++)
        ptr[i]=Q.ptr[i];
    return *this;
}
void Queue::insert(int data)
{
    try{
        if(capacity<=0)
            throw INVALID_QUEUE_STATE;
        if(isFull())
            doubleQueue();
        if(rear==-1)
        {
            front=rear=0;
            ptr[rear]=data;
        }
        else if(rear==capacity-1)
        {
            rear=0;
            ptr[rear]=data;
        }
        else
        {
            rear++;
            ptr[rear]=data;
        }
    }
    catch(int e)
    {
        cout<<"Invalid Queue State";
    }
}
void Queue::del()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        if(rear==front)
            rear=front=-1;
        else if(front==capacity-1)
            front=0;
        else 
            front++;
        if(count()==capacity/2)
            halfQueue();
    }
    catch(int e)
    {
        cout<<"Empty List";
    }
}
bool Queue::isFull()
{
    return (front==rear+1||rear==capacity);
}
bool Queue::isEmpty()
{
    return rear==-1;
}
int Queue::getFront()
{
    if(isEmpty())
        throw EMPTY_LIST;
    return ptr[front];
}
int Queue::getBack()
{
    if(isEmpty())
        throw  EMPTY_LIST;
    return ptr[rear];
}
int Queue::count()
{
    if(front==-1)
        return 0;
    else if(front==rear)
        return 1;
    else if(rear>front)
        return rear-front+1;
    else
        return capacity-front+rear+1;
}
void Queue::doubleQueue()
{
    int f=front;
    int *temp=new int[capacity*2];
    for(int i=0;i<capacity;i++)
    {
        temp[i]=ptr[f];
        if(f==capacity-1)
            f=0;
        else
            f++;
    }
    front=0;
    rear=capacity-1;
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
void Queue::halfQueue()
{
    int f=front;
    int c=count();
    int *temp=new int[capacity/2];
    for(int i=0;i<c;i++)
    {
        temp[i]=ptr[f];
        if(f==capacity-1)
            f=0;
        else
            f++;
    }
    front=0;
    rear=c-1;
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
Queue::~Queue()
{
    delete []ptr;
}
int main()
{
    
}