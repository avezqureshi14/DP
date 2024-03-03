#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int &target, int sum, int &count)
{
    if (sum > target)
    {
        return;
    }

    if (sum == target)
    {
        count++;
        return;
    }

    if (sum + 1 <= target)
    {
        solve(target, sum + 1, count);
    }
    if (sum + 2 <= target)
    {
        solve(target, sum + 2, count);
    }
}

int climbingStairs(int n)
{
    int count = 0;
    solve(n, 0, count);
    return count;
}


int climbingStairsII(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return climbingStairsII(n-1) + climbingStairsII(n-2);
}

int main()
{
    int n = 2;
    cout << climbingStairsII(n);
    return 0;
}