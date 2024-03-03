#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool equalSumPartition(int set[], int n){
    int arraySum = 0;
    for (int i = 0; i < n; i++)
    {
        arraySum += set[i];
    }

    if (arraySum%2 != 0)
    {
        return false;
    }
    
    int sum = arraySum/2;
    
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
                dp[i][j] = dp[i-j][j];
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
    int set[] = { 3, 1, 1, 2, 2, 1 };
    int n = sizeof(set)/sizeof(set[0]);
    if (equalSumPartition(set, n) == true)
        cout <<"Can be divided into two subsets of equal length";
    else
        cout <<"Cannot be divided into two subsets of equal length";
    return 0;
}