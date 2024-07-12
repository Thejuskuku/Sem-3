#include <iostream>
using namespace std;
void InsertionSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min = j;
            }
        }
        int temp=A[min];
        A[min]=A[i];
        A[i]=temp;
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
    InsertionSort(A,n);
    Display(A,n);  
}