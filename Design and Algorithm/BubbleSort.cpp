#include <iostream>
using namespace std;
void BubbleSort(int A[],int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-i-1;j++)
        {
            if(A[j]>=A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}
void Display(int A[],int n)
{
    for(int k=0;k<n;k++)
    {
        cout<<A[k];
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
    BubbleSort(A,n);
    Display(A,n);
}