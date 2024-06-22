#include<iostream>
using namespace std;
#define HEAP_IS_FULL 1
#define HEAP_IS_EMPTY 2
class Heap
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Heap();
        Heap(int);
        inline int getTopEle();
        inline void createHeapArray(int);
        inline int getLeftChild(int);
        inline int getRightChild(int);
        inline int getParent(int);
        void insert(int);
        void del();
        inline bool isEmpty();
        inline int getLastEle();
};
int Heap::getLastEle()
{
    return ptr[lastIndex];
}
int Heap::getTopEle()
{
    return ptr[0];
}
bool Heap::isEmpty()
{
    return lastIndex==-1;
}
void Heap::del()
{
    //Always delete root node
    try{
        if(isEmpty())
            throw HEAP_IS_EMPTY;

        ptr[0]=ptr[lastIndex];
        lastIndex--;    //delete node
        
        // Heapify from the root to maintain the heap property
        if(lastIndex>0){
            int index=0;
            int temp;
            bool flag=true;
            while(flag){
                int leftChild=getLeftChild(index);
                int rightChild=getRightChild(index);
                int largest=index;

                if(leftChild<=lastIndex && ptr[leftChild]>ptr[largest])
                    largest=leftChild;

                if(rightChild<=lastIndex && ptr[rightChild]>ptr[largest])
                    largest=rightChild;

                if(largest!=index){
                    //swap with the larger child
                    temp=ptr[index];
                    ptr[index]=ptr[largest];
                    ptr[largest]=temp;
                    index=largest;
                } else{
                    flag=false;
                }
            }
        }
    }
    catch(int e)
    {
        cout<<"Heap is not available for deletion";
    }
}
void Heap::insert(int data)
{
    int temp;
    try{
        if(capacity==0 && lastIndex==capacity-1)
            throw HEAP_IS_FULL;
        lastIndex++;
        ptr[lastIndex]=data;
        if(lastIndex>=1)    //using Heap algorithm  Heapify
        {
            int in=lastIndex;
            bool flag=true;
            while(flag)
            {
                if(ptr[in]>ptr[getParent(in)])  
                {
                    temp=ptr[getParent(in)];
                    ptr[getParent(in)]=ptr[in];
                    ptr[in]=temp;
                    in=getParent(in);
                }
                else
                    flag=false;
            }
        }
    }
    catch(int e)
    {
        cout<<"Not available Heap for insertion";
    }
}
void Heap::createHeapArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
Heap::Heap()
{
    capacity=0;
    lastIndex=-1;
    ptr=NULL;
}
Heap::Heap(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
int Heap::getLeftChild(int index)
{
    return 2*index+1;
}
int Heap::getRightChild(int index)
{
    return 2*index+2;
}
int Heap::getParent(int index)
{
    return (index-1)/2;
}

void HeapSort(int *arr,int size)
{
     h1(size);
    for(int i=0;i<size;i++){
        h1.inert(arr[i]);
    }
    
        arr[j]=h1.getTopEle();
        h1.del();
    }
}
int main()
{

    int arr[]={80,72,70,60,20,35,54,14,30};
    Hert(arr,sizeof(arr)/sizeof(int));
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}