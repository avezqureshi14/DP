#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &height)
{
    if (n < 0|| n == 0)
    {
        return 0;
    }

    int step1 = frogJump(n - 1, height) + abs(height[n] - height[n - 1]);
    int step2 = INT_MAX;
    if (n > 1)
    {
        step2 = frogJump(n - 2, height) + abs(height[n] - height[n - 2]);
    }

    return min(step1, step2);
}
int main()
{
    vector<int> height = {30,10,60,10,60,50};
    int n = height.size();
    cout << frogJump(n, height);
    return 0;
}