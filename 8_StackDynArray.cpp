#include<iostream>
using namespace std;
#define STACK_IS_EMPTY 1
class stack
{
    private:
        int capacity;
        int top;
        int *ptr;
        void doubleStack();
        void halfStack();
    public:
        stack();
        stack(int);
        stack(stack&);
        stack& operator=(stack&);
        void createStack(int);
        void push(int);
        int peek();
        void pop();
        bool isFull();
        bool isEmpty();
        bool isHalf();
        int getCap();
        int count();
        ~stack();
};
stack::stack()
{
    capacity=0;
    top=-1;
    ptr=NULL;
}
stack::stack(int cap)
{
    capacity=cap;
    top=-1;
    ptr=new int[capacity];
}
stack::stack(stack &s)
{
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
}
stack& stack::operator=(stack &s)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
    return (*this);
}
void stack::createStack(int cap)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=cap;
    top=-1;
    ptr=new int[capacity];
}
void stack::push(int data)
{
    if(isFull())
        doubleStack();
    top++;
    ptr[top]=data;
}
int stack::peek()
{
    if(isEmpty())
        throw STACK_IS_EMPTY;
    return ptr[top];
}
void stack::pop()
{
    try{
        if(isEmpty())
            throw 1;
        top--;
        if(capacity>1&&isHalf())
            halfStack();
    }
    catch(int e)
    {
        cout<<"Stack Underflow";
    }
}
bool stack::isFull()
{
    return top==capacity-1;
}
bool stack::isEmpty()
{
    return top==-1;
}
bool stack::isHalf()
{
    return top+1==capacity/2;
}
int stack::getCap()
{
    return capacity;
}
int stack::count()
{
    return top;
}
void stack::doubleStack()
{
    int *temp;
    temp=new int[capacity*=2];
    for(int i=0;i<=top;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}
void stack::halfStack()
{
    int *temp;
    temp=new int[capacity/=2];
    for(int i=0;i<=top;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}
stack::~stack()
{
    if(ptr!=NULL)
        delete []ptr;
}
int main()
{
    stack s1;
    s1.createStack(2);
    s1.push(10);
    s1.push(20);
    cout<<s1.peek();
    cout<<endl<<s1.getCap()<<endl;
}