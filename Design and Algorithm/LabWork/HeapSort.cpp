#include <iostream>
using namespace std;
void HeapSort(int A[],int n)
{
    int i;
    if(n%2==0)
    {
        for(i=n/2;i>0;i--)
        {
            Heapify(i,n,A);
        }
    }
    else
    {
        for(i=n/2-1;i>0;i--)
        {
            Heapify(i,n,A);
        }
    }
    for(int j=0;j<n;j++)
    {
        swap(0,n-i,A);
        Heapify(n-1/2,n-i,A);
    }
}
void Heapify(int i,int n,int A[])
{
    if(A[2*i+1]>A[i])
    {
        swap(2*i+1,i,A);
    }
    if(A[2*i+2]>A[i])
    {
        swap(2*i+2,i,A);
    }
}
void swap(int m,int n,int A[])
{
    int temp=A[m];
    A[m]=A[n];
    A[n]=temp;
}
void Display(int A[],int n)
{
    for(int k=0;k<n;k++)
    {
        cout<<A[k]<<" ";
    }
}
int main()
{
    int n;
    int i=0;
    cout<<"Enter the number of elements : "<<endl;
    cin>>n;
    int A[n];
    while(i<n)
    {
        cout<<"Enter the elements : "<<endl;
        cin>>A[i];
        i++;
    }
    HeapSort(A,n);
    Display(A,n);  
}
