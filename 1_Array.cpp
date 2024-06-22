//Array Data Structure
#include<iostream>
using namespace std;
class Array
{
    private:
        int capacity; //capacity of array
         int lastIndex; //last index of array
         int *ptr; //point the array
    public:
        Array(); //default constructor
        Array(int); //parameterized constructor
        Array(Array &); //Deep copy constructor
        Array& operator=(Array &); //copy assignment operator
        void createArray(int);
        void insert(int,int);
        void append(int);
        int getItem(int);
        bool isEmpty();
        bool isFull();
        void delet(int);
        void edit(int,int);
        int count();
        int findElement(int);
        int getCapacity();
        void sortEle_1();
        void sortEle_2();
        int greatest_Ele();
        int smallest_Ele();
        void printAllData();
        int sumAll_Ele();
        int averageAll_Ele();
        void remove_dup_Ele();
        ~Array();
};
Array::Array()
{
    ptr=NULL;
}
Array::Array(int size)
{
    capacity=size;
    lastIndex=-1;
    ptr=new int[capacity];
}
Array::Array(Array &a)
{
    capacity=a.capacity;
    lastIndex=a.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=a.ptr[i];
}
Array& Array::operator=(Array &a)
{
    capacity=a.capacity;
    lastIndex=a.lastIndex;
    if(ptr!=NULL)
        delete ptr;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=a.ptr[i];
    return (*this);
}
void Array::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
}
void Array::insert(int index,int data)
{
    try
    {
        if(index<0 || index>lastIndex+1)
            throw 1;
        if(isFull())
            throw 2;
        for(int i=lastIndex;i>=index;i--)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastIndex++;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Invalid Index";
        if(e==2)
            cout<<"Overflow";
    }
}
void Array::append(int data)
{
    try
    {
        if(isFull())
            throw 1;
        lastIndex++;
        ptr[lastIndex]=data;
    }
    catch(int e)
    {
       cout<<"\nOverflow: append not performed"<<endl;
    }
}
int Array::getItem(int index)
{
    try
    {
        if(index<0||index>lastIndex)
            throw 1;
        return ptr[index];
    }
    catch(int e)
    {
        cout<<"Invalid Index or Arra is Empty";
    }
    return -1;
}
bool Array::isEmpty()
{
    return lastIndex==-1;
}
bool Array::isFull()
{
    return lastIndex==capacity-1;
}
void Array::delet(int index)
{
    try
    {
        if(index<0||index>lastIndex)
            throw 1;
        for(int i=index; i<lastIndex; i++)
        {
            ptr[i]=ptr[i+1];
        }
        lastIndex--;
    }
    catch(int e)
    {
        cout<<"\nInvalid Index or Underflow";
    }
}
void Array::edit(int index,int value)
{
    try
    {
        if(index<0||index>lastIndex)
            throw 1;
        ptr[index]=value;
    }
    catch(int e)
    {
        cout<<"\nInvalid Index or Index is Empty ";
    }
}
int Array::count()
{
    return lastIndex+1;
}
int Array::findElement(int ele)
{
    int i;
    for(i=0;i<capacity;i++)
    {
        if(ptr[i]==ele)
            return i;
    }
    return -1;
}
int Array::getCapacity()
{
    return capacity;
}
void Array::sortEle_1()
{
    int i,j,last,s;
    for(last=lastIndex;last!=0;last--)
    {
        for(i=0;i<last;i++)
        {
            for(j=i+1;j<=last;j++)
            {
                if(ptr[i]>ptr[j])
                {
                    s=ptr[j];
                    ptr[j]=ptr[i];
                    ptr[i]=s;
                    break;
                }
            }
        }
    }

}
void Array::sortEle_2()
{
    int i,j,s,small;
    for(i=0;i<lastIndex;i++)
    {
        s=i;
        for(j=i+1;j<=lastIndex;j++)
        {
            if(ptr[j]<ptr[s])
                s=j;
        }
        if(s!=i)
        {
            small=ptr[s];
            ptr[s]=ptr[i];
            ptr[i]=small;
        }
    }
}
int Array::greatest_Ele()
{
    int i,great=0;
    for(i=1;i<=lastIndex;i++)
    {
        if(ptr[i]>ptr[great])
            great=i;
    }
    return ptr[great];
}
int Array::smallest_Ele()
{
    int i,small=0;
    for(i=1;i<=lastIndex;i++)
    {
        if(ptr[i]<ptr[small])
            small=i;
    }
    return ptr[small];
}
int Array::sumAll_Ele()
{
    int i,sum=0;
    for(i=0;i<=lastIndex;i++)
        sum=sum+ptr[i];
    return sum;
}
void Array::printAllData()
{
    for(int i=0;i<=lastIndex;i++)
    {
        cout<<ptr[i]<<" ";
    }
}
void Array::remove_dup_Ele()
{
    int i,j;
    for(i=0;i<lastIndex;i++)
    {
        for(j=i+1;j<=lastIndex;j++)
        {
            if(ptr[i]==ptr[j])
                delet(j);
        }
    }
}
int Array::averageAll_Ele()
{
    int i,sum=0,aver=0;
    for(i=0;i<=lastIndex;i++)
        sum=sum+ptr[i];
    aver=sum/lastIndex;
    return aver;
}
Array::~Array()
{
    delete []ptr;
}
int main()
{
    Array arr(6);
    arr.insert(0,10); 
    arr.insert(1,8); 
    arr.insert(2,10); 
    arr.insert(3,14); 
    arr.insert(4,5); 
    arr.insert(5,14); 
    arr.printAllData();
    arr.sortEle_2();
    cout<<endl;
    arr.printAllData();
    cout<<"\ngreatest = "<<arr.greatest_Ele();
    cout<<"\nsmallest = "<<arr.smallest_Ele();
    cout<<"\nsum = "<<arr.sumAll_Ele();
    cout<<"\naverage = "<<arr.averageAll_Ele()<<endl;
    arr.remove_dup_Ele();
    arr.printAllData();
}