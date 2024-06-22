#include<iostream>

using namespace std;
int quick(int A[],int,int);
void QuickSort(int A[],int,int);

int quick(int A[],int left,int right)
{
    int loc=left,temp;
    while(left<right)
    {
        while(left<right && A[loc]<=A[right])
            right--;
        if(left==right)
            break;
        temp=A[loc];
        A[loc]=A[right];
        A[right]=temp;
        loc=right;
        while(left<right && A[left]<=A[loc])
            left++;
        if(left==right)
            break;
        temp=A[loc];
        A[loc]=A[left];
        A[left]=temp;
        loc=left;
    }
    return loc;
}
void QuickSort(int A[],int lower,int upper)
{
    int loc;
    loc=quick(A,lower,upper);
    if(loc>lower+1)
        QuickSort(A,lower,loc-1);
    if(loc<upper-1)
        QuickSort(A,loc+1,upper);
}
int main()
{
    int a[]={40,21,38,68,70,25,90,18,7,54};
    int s=sizeof(a)/sizeof(int);
    QuickSort(a,0,s-1);
    for(int i=0; i<s; i++)
        // printf("%d ",a[i]);  //for C
        cout<<a[i]<<" ";    //for C++
}