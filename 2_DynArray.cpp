#include<iostream>
using namespace std;
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(); //default constructor
        DynArray(int); //parameterized constructor
        DynArray(DynArray &); //deep copy constructor
        DynArray& operator=(DynArray &); //copy assignment operator
        void createArray(int);
        void insert(int,int);
        void append(int);
        void edit(int,int);
        void del(int);
        bool isEmpty();
        bool isHalf();
        bool isFull();
        int getEle(int);
        int findElement(int);
        int getCapacity();
        int count();
        ~DynArray();
};
DynArray::DynArray()
{
    ptr=NULL;
}
DynArray::DynArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
DynArray::DynArray(DynArray &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
}
DynArray& DynArray::operator=(DynArray &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
        delete ptr;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
    return (*this);
}
void DynArray::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
}
void DynArray::insert(int index,int data)
{
    try{
        if(index<0||index>lastIndex+1)
            throw 1;
        if(isFull())
            doubleArray();
        for(int i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
    catch(int e)
    {
        cout<<"Index is not valid\n";
    }
}
void DynArray::append(int data)
{
    if(isFull())
        doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
}
void DynArray::edit(int index,int data)
{
    try{
        if(index<0||index>lastIndex)
            throw 1;
        ptr[index]=data;
    }
    catch(int e)
    {
        cout<<"Overflow or Index is empty\n";
    }
}
void DynArray::del(int index)
{
    try{
        if(index<0||index>lastIndex)
            throw 1;
        for(int i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
        if(capacity>1&&isHalf())
            halfArray();
    }
    catch(int e)
    {
        cout<<"Overflow or Index is empty\n";
    }
}
bool DynArray::isEmpty(){
    return lastIndex==-1;
}
bool DynArray::isHalf(){
    return lastIndex+1<=capacity/2;
}
bool DynArray::isFull(){
    return lastIndex==capacity-1;
}
int DynArray::count()
{
    return lastIndex+1;
}
int DynArray::getCapacity()
{
    return capacity;
}
int DynArray::getEle(int index)
{
    try{
        if(index<0||index>lastIndex)
            throw 1;
        return ptr[index];
    }
    catch(int e)
    {
        cout<<"Overflow or Index is Empty\n";
    }
    return -1;
}
int DynArray::findElement(int ele)
{
    int i;
    for(i=0;i<capacity;i++)
    {
        if(ptr[i]==ele)
            return i;
    }
    return -1;
}
void DynArray::doubleArray()
{
    int i,*temp;
    temp=new int[capacity*=2];
    for(i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}
void DynArray::halfArray()
{
    int i,*temp;
    temp=new int[capacity/=2];
    for(i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}
DynArray::~DynArray()
{
    delete []ptr;
}
int main()
{
    DynArray d1(2),d2(5);
    d1.insert(0,200);
    d1.insert(0,10);
    d1.insert(1,100);
    cout<<d1.getCapacity();
    // d1.del(2);
    // cout<<d1.getCapacity();
    cout<<d1.getEle(1)<<endl;
    cout<<d1.findElement(1000);
}