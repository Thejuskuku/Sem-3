#include <iostream>
using namespace std;
int minCoin(int coin[],int n,int amount)
{
    int dp[amount+1];
    dp[0]={0};
    for(int i=1;i<=amount;i++)
    {
        dp[i]=1000;
    }
    for(int i=1;i<=amount;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(coin[j]<=i && dp[i-coin[j]]!=1000)
            {
                dp[i]=min(dp[i],1+dp[i-coin[j]]);
            }
        }
    }
    return dp[amount]==1000 ? -1 : dp[amount];

}
int main()
{
    int coin[]={1,2,5};
    int n=sizeof(coin)/sizeof(coin[0]);
    int amount= 11;
    int result=minCoin(coin,n,amount);
    if(result==-1)
    {cout<<"Not Possible"<<endl;}
    else
    {cout<<"Minimum number of coins required is "<<result<<endl;}
    return 0;
}