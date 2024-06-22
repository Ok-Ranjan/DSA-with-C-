#include<iostream>
using namespace std;
#define OVERFLOW 1
#define INVALID_Deque_STATE 2
#define EMPTY_LIST 3
class Deque
{
    private:
        int capacity;
        int front,rear;
        int *ptr;
        void doubleDeque();
        void halfDeque();
    public:
        Deque(int);
        Deque(Deque&);
        Deque& operator=(Deque&);
        void insertAtFront(int);
        void insertAtRear(int);
        void delFront();
        void delRear();
        int getFront();
        int getRear();
        bool isFull();
        bool isEmpty();
        int count();
        ~Deque();
};
Deque::Deque(int cap)
{
    capacity=cap;
    front=rear=-1;
    if(cap>0)
        ptr=new int[cap];
    else
        ptr=NULL;
}
Deque::Deque(Deque &d)
{
    capacity=d.capacity;
    front=d.front;
    rear=d.rear;
    ptr=new int[capacity];
    for(int i=0;i<capacity;i++)
        ptr[i]=d.ptr[i];
}
Deque& Deque::operator=(Deque &d)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=d.capacity;
    front=d.front;
    rear=d.rear;
    ptr=new int[capacity];
    for(int i=0;i<capacity;i++)
        ptr[i]=d.ptr[i];
    return *this;
}
void Deque::insertAtFront(int data)
{
    try{
        if(capacity<=0)
            throw INVALID_DEQUE_STATE;
        if(isFull())
            doubleDeque();
        if(isEmpty())
        {
            front=rear=0;
            ptr[front]=data;
        }
        else
        {
            for(int i=rear;i>=0;i--)
            {
                if(i==capacity-1)
                    ptr[0]=ptr[i];
                else{
                    ptr[i+1]=ptr[i];
                    if(i==0&&rear<front)
                        i=capacity;
                }
            }
            ptr[front]=data;
            if(rear==capacity-1)
                rear=0;
            else
                rear=rear+1;
        }
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Overflow";
        if(e==2)
            cout<<"Invalid Deque State";
    }
}
void Deque::insertAtRear(int data)
{
    try{
        if(capacity<=0)
            throw INVALID_DEQUE_STATE;
        if(isFull())
            doubleDeque();
        if(isEmpty())
        {
            front=rear=0;
            ptr[rear]=data;
        }
        else
        {
            if(rear==capacity-1)
                rear=0;
            else
                rear=rear+1;
            ptr[rear]=data;
        }
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Overflow";
        if(e==2)
            cout<<"Invalid Deque State";
    }
}
void Deque::delFront()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        if(front==rear)
            front=rear=-1;
        else if(front==capacity-1)
            front=0;
        else
            front++;
        if(count()==capacity/2)
            halfDeque();
    }
    catch(int e)
    {
        cout<<"Empty List";
    }
}
void Deque::delRear()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        if(front==rear)
            front=rear=-1;
        else if(rear==0)
            rear=capacity-1;
        else 
            rear--;
        if(count()==capacity/2)
            halfDeque();
    }
    catch(int e)
    {
        cout<<"Empty List";
    }
}
int Deque::getFront()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        return ptr[front];
    }
    catch(int e)
    {
        cout<<"Empty list";
    }
    return -1;
}
int Deque::getRear()
{
    try{
        if(isEmpty())
            throw EMPTY_LIST;
        return ptr[rear];
    }
    catch(int e)
    {
        cout<<"Empty list";
    }
    return -1;
}
bool Deque::isFull()
{
    return (front==rear+1||capacity+1);
}
bool Deque::isEmpty()
{
    return front==-1;
}
int Deque::count()
{
    if(isEmpty())
        return 0;
    else if(front==rear)
        return 1;
    else if(rear>front)
        return rear-front+1;
    else
        return capacity-front+rear+1;
}
void Deque::doubleDeque()
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
void Deque::halfDeque()
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
Deque::~Deque()
{
    delete []ptr;
}
int main()
{
    
}