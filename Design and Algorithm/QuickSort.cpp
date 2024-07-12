#include <iostream>
using namespace std;
int partition(int A[],int n)
{
    int pivot=A[n-1];
    int i=-1;
    for(int j=0;j<n;j++)
    {
        if(A[j]<=pivot)
        {
            i++;
            int temp=A[j];
            A[j]=A[i];
            A[i]=temp;
        }
    }
    return i;
}
void QuickSort(int A[],int LB,int UB)
{
    if(LB<UB)
    {
        int pos1=partition(A,UB);
        QuickSort(A,LB,pos1-1);
        QuickSort(A,pos1+1,UB);
    }
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
    int pos=partition(A,n);
    QuickSort(A,0,pos);
    QuickSort(A,pos+1,n);
    Display(A,n);  
}