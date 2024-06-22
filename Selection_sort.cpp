#include<iostream>
using namespace std;
void selectionSort(int A[],int);

void selectionSort(int A[],int size)
{
    int i,j,temp;
    for(i=0;i<=size-2;i++)
    {
        for(j=i+1;j<=size-1;j++)
        {
            if(A[i]>A[j])
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
}
int main()
{
    int a[]={40,21,38,68,70,25,90,18,7,54};
    int s=sizeof(a)/sizeof(int);
    selectionSort(a,s);
    for(int i=0; i<s; i++)
        // printf("%d ",a[i]);  //for C
        cout<<a[i]<<" ";    //for C++
}