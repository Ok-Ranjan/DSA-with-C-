#include<iostream>
using namespace std;
#define INVALID_QUEUE_STATE 1
#define OVERFLOW 2
#define UNDERFLOW 3
class Queue
{
    private:
        int capacity;
        int front,rear;
        int *ptr;
    public:
        Queue(int);
        Queue(Queue&);
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
    front=-1;
    rear=-1;
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
            throw OVERFLOW;
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
        if(e==1)
            cout<<"Invalid Queue State\n";
        if(e==2)
            cout<<"Overflow\n";
    }
}
void Queue::del()
{
    try{
        if(isEmpty())
            throw UNDERFLOW;
        if(front==rear)
            front=rear=-1;
        else if(front==capacity-1)
            front=0;
        else
            front++;
    }
    catch(int e)
    {
        cout<<"Overflow\n";
    }
}
bool Queue::isFull()
{
    return (front==0&&rear==capacity-1 || rear+1==front);
}
bool Queue::isEmpty()
{
    return front==-1;
}
int Queue::getFront()
{
    try{
        if(isEmpty())
            throw UNDERFLOW;
        return ptr[front];
    }
    catch(int e)
    {
        cout<<"Underflow\n";
    }
    return -1;
}
int Queue::getBack()
{
    try{
        if(isEmpty())
            throw UNDERFLOW;
        return ptr[rear];
    }
    catch(int e)
    {
        cout<<"Underflow\n";
    }
    return -1;
}
int Queue::count()
{
    if(front==-1)
        return 0;
    if(front==rear)
        return 1;
    if(rear>front)
        return rear-front+1;
    else
        return capacity-front+rear+1;
}
Queue::~Queue()
{
    delete []ptr;
}
int main()
{
    Queue q1(2);
    q1.insert(20);
    q1.insert(30);
    q1.del();
    cout<<q1.getFront()<<endl;
    cout<<q1.getBack()<<endl;
    q1.insert(40);
    cout<<q1.count()<<endl;
}