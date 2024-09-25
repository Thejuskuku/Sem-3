#include <iostream>
using namespace std;
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

void CoinRow(int coin[],int length)
{
    if (length == 0) 
    {
        cout << 0 << endl;
        return;
    }
    if (length == 1) 
    {
        cout << coin[0] << endl;
        return;
    }

    int f[length+1];
    f[0]=0;
    f[1]=coin[0];
    int i=1;
    for(i;i<length;i++)
    {
        f[i+1]=max(coin[i]+f[i-1],f[i]);
    }
    cout<<f[length]<<endl;
}
int main()
{
    int coin []={7, 9, 10, 9, 3, 5, 2};
    int length=sizeof(coin)/sizeof(coin[0]);
    CoinRow(coin,length);
}
