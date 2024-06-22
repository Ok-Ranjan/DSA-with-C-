#include<iostream>
#define EMPTY_P_QUEUE 1
using namespace std;
struct node
{
    int priorityN;
    int item;
    node* next;
};
class PriorityQueue
{
    private:
        node* start;
    public:
        PriorityQueue(); //default constructor to initialise member variable
        PriorityQueue(PriorityQueue&); //copy constructor to implement deep copy
        PriorityQueue& operator=(PriorityQueue&); //Copy assignment operator to implement deep copy
        void insert(int,int); //insert new item in Queue
        void del(); //delete highest priority element
        int getHighPriEle(); //get Highest priority element
        int getHighPriNum(); //get Highest priority number
        bool isEmptyPQueue(); //check if Priority Queue is empty
        ~PriorityQueue(); //destructor to deallcate the memory
};
PriorityQueue::PriorityQueue()
{
    start=NULL;
}
PriorityQueue::PriorityQueue(PriorityQueue &p)
{
    start=NULL;
    node* t=p.start;
    while(t)
    {
        insert(t->item,t->priorityN);
        t=t->next;
    }
}
PriorityQueue& PriorityQueue::operator=(PriorityQueue &p)
{
    
    while(start)
        del();
    node* t=p.start;
    while(t)
    {
        insert(t->item,t->priorityN);
        t=t->next;
    }
    return *this;
}
void PriorityQueue::insert(int data,int prio)
{
    node* n=new node;
    n->item=data;
    n->priorityN=prio;
    if(isEmptyPQueue())
    {
        start=n;
        n->next=NULL;
    }
    else{
        node* temp=start;
        if(n->priorityN > temp->priorityN)
        {
            n->next=start;
            start=n;
        }
        else{
            while(1)
            {
                if(n->priorityN < temp->priorityN)
                {
                    if(temp->next==NULL)
                    {
                        temp->next=n;
                        n->next=NULL;
                        break;
                    }
                    else if(n->priorityN > temp->next->priorityN)
                    {
                        n->next=temp->next;
                        temp->next=n;
                        break;
                    }
                    else
                        temp=temp->next;
                }
                else    //equal priority condition
                {
                    n->next=temp->next;
                    temp->next=n;
                    break;
                }
            }
        }
    }
}
void PriorityQueue::del()
{
    try{
        if(isEmptyPQueue())
            throw EMPTY_P_QUEUE;
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else{
            node* t=start;
            start=start->next;
            delete []t;
        }
    }
    catch(int e)
    {
        cout<<"Empty Queue, So cannot delete";
    }
}
int PriorityQueue::getHighPriEle()
{
    if(isEmptyPQueue())
        cout<<"Empty Queue";
    else
        return start->item;
    return -1;
}
int PriorityQueue::getHighPriNum()
{
    if(isEmptyPQueue())
        cout<<"Empty Queue";
    else
        return start->priorityN;
    return -1;
}
bool PriorityQueue::isEmptyPQueue()
{
    return start==NULL;
}
PriorityQueue::~PriorityQueue()
{
    while(start)
        del();
}
int main()
{
    PriorityQueue p,p1;
    p.insert(500,4);
    p.insert(100,5);
    p.insert(200,7); 
    // p.del();
    // p.del();
    // p.del();
    cout<<p.getHighPriNum()<<endl;
    cout<<p.getHighPriEle()<<endl;
    PriorityQueue p2=p;
    cout<<p2.getHighPriNum()<<endl;
    cout<<p2.getHighPriEle()<<endl;
    p1=p;
    cout<<p1.getHighPriNum()<<endl;
    cout<<p1.getHighPriEle()<<endl;
    p2=p1=p;
    cout<<p.getHighPriNum()<<endl;
    cout<<p.getHighPriEle()<<endl;
}