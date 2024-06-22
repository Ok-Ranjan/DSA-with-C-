#include<iostream>
using namespace std;
#define STACK_IS_EMPTY 1
class stack
{
    private:
        int capacity;
        int top;
        int *ptr;
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
    for(int i=0;i<top;i++)
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
    try{
        if(isFull())
            throw 1;
        top++;
        ptr[top]=data;
    }
    catch(int e)
    {
        cout<<"stack overflow";
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
int stack::peek()
{
    if(isEmpty())
        throw STACK_IS_EMPTY;
    return ptr[top];
}
void stack::pop()
{
    if(isEmpty())
        cout<<"\nstack underflow";
    else
        top--;
}
stack::~stack()
{
    if(ptr!=NULL)
        delete []ptr;
}
int main()
{
    stack s1,s3;
    s1.createStack(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout<<s1.peek()<<endl;
    stack s2=s3=s1;
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    cout<<s2.peek()<<endl;
    s3.pop();
    cout<<s3.peek();
}