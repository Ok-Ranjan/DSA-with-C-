#include<iostream>
using namespace std;
#define EMPTY_STACK 1
struct node
{
    int item;
    node *next;
};
class stack
{
    private:
        node *top;
    public:
        stack();
        stack(stack&);
        stack& operator=(stack&);
        void push(int);
        int peek();
        void pop();
        void reverse();
        ~stack();
};
stack::stack()
{
    top=NULL;
}
stack::stack(stack &s)
{
    node *t;
    s.reverse();
    t=s.top;
    while(t)
    {
        push(t->item);
        t=t->next;
    }
    s.reverse();
}
stack& stack::operator=(stack &s)
{
    if(top!=NULL)
    {
        while(top)
            pop();
    }
    node *t;
    s.reverse();
    t=s.top;
    {
        push(t->item);
        t=t->next;
    }
    s.reverse();
    return *this;
}
void stack::push(int data)
{
    node *n=new node;
    n->item=data;
    n->next=top;
    top=n;
}
int stack::peek()
{
    if(top==NULL)
        throw EMPTY_STACK;
    return top->item;
}
void stack::pop()
{
    if(top==NULL)
        cout<<"Stack is Empty";
    else{
        node *t=top;
        top=top->next;
        delete []t;
    }
}
void stack::reverse()
{
    stack s1;
    while(top)
    {
        s1.push(peek());
        pop();
    }
    top=s1.top;
    s1.top=NULL; //SO THAT Destructor Not Call. 
}
stack::~stack()
{
    while(top)
        pop();
}
int main()
{
    
}