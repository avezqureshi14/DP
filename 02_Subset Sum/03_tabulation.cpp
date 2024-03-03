#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSubSetSum(int set[], int n, int sum){
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }
    // j = target/sum //i = element
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            //if element is greater than target then we will be leaving it 
            if (j < set[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            if (j >= set[i-1])
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
            }
        }
    }
    

    //return the last box of matrix
    return dp[n][sum];
    
    
}

int main()
{
    // int set[] = {3,34,4,10,5,2};
    int set[] = {1,2,5};
    int sum = 4;
    int n = sizeof(set)/sizeof(set[0]);
    if (isSubSetSum(set, n, sum) == true)
        cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}