#include<iostream>
using namespace std;
void modifiedBubbleSort(int arr[],int size);

void modifiedBubbleSort(int arr[],int size)
{
    int i,r,temp;
    bool flag;
    for(r=1;r<size;r++)
    {
        flag=false;
        for(i=0;i<size-r;i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=true;
            }
        }
        if(flag==false)
            break;
    }
}
int main()
{
    int a[]={40,21,38,68,70,25,90,18,7,54};
    int s=sizeof(a)/sizeof(int);
    modifiedBubbleSort(a,s);
    for(int i=0; i<s; i++)
        // printf("%d ",a[i]);  //for C
        cout<<a[i]<<" ";    //for C++
}