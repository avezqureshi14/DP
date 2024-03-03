#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//This is top down approach => Required ans to base case
/*
TC : O(n)
SC : Stack Space : O(1) + O(1) 
*/

int fib(int n, int prev2, int prev)
{
   for (int i = 2; i <= n; i++)
   {
      int curr = prev + prev2;
      prev2 = prev;
      prev = curr;
   }
   return prev;
}
int main()
{
    int n = 5;
    int prev2 = 0;
    int prev = 1;
    cout << fib(n, prev2,prev);
    return 0;
}