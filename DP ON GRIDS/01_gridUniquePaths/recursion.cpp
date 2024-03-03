#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int uniquePathsRecursive(int i, int j){
    
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    
    int up = uniquePathsRecursive(i-1,j);
    int left = uniquePathsRecursive(i,j-1);

    return  up + left;
}

int uniquePaths(int m, int n){

    return uniquePathsRecursive(m-1,n-1);
} 

int main()
{
    int m = 3;
    int n = 7;
    cout<<uniquePaths(m,n);
    return 0;
}