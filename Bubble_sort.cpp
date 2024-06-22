#include<iostream>  //for C++
#include<stdio.h>   //for C
using namespace std;    //for C++
void BubbleSort(int *arr,int size)
{
    int temp;
    for(int r=1;r<size;r++) //for round
    {
        //comarison...
        for(int i=0;i<size-r;i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
    }
}
int main()
{
    int a[]={40,21,38,68,70,25,90,18,7,54};
    int s=sizeof(a)/sizeof(int);
    BubbleSort(a,s);
    for(int i=0; i<s; i++)
        // printf("%d ",a[i]);  //for C
        cout<<a[i]<<" ";    //for C++
}