#include<iostream>
using namespace std;
void insertionSort(int A[],int);

void insertionSort(int A[],int size)
{
    int sortIn,i,temp;
    for(sortIn=0;sortIn<=size-2;sortIn++)
    {
        temp=A[sortIn+1];
        for(i=sortIn; i>=0 && A[i]>temp ;i--)
        {
           A[i+1]=A[i];
        }
        A[i+1]=temp;
    }
}
int main()
{
    int a[]={40,21,38,68,70,25,90,18,7,54};
    int s=sizeof(a)/sizeof(int);
    insertionSort(a,s);
    for(int i=0; i<s; i++)
        // printf("%d ",a[i]);  //for C
        cout<<a[i]<<" ";    //for C++
}