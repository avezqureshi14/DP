#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int uniquePathsIIRecursive(int i, int j, vector<vector<int>>&mat){
    
    if (i >= 0 && j >= 0 && mat[i][j] == -1)
    {
        return 0;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    
    int up = uniquePathsIIRecursive(i-1,j,mat);
    int left = uniquePathsIIRecursive(i,j-1,mat);

    return  up + left;
}

int uniquePathsII(int m, int n, vector<vector<int>>&mat){

    return uniquePathsIIRecursive(m-1,n-1,mat);
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>>matrix = { { 0 , 0 , 0 },{0, -1 ,0},{0 , 0 , 0}};
    cout<<uniquePathsII(m,n,matrix);
    return 0;
}