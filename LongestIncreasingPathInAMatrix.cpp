'''
/*
Problem Description

Given a 2D integer matrix A of size N x M.

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.


Problem Constraints
1 <= N, M <= 103

1 <= A[i][j] <= 108



Input Format
First and only argument is an 2D integer matrix A of size N x M.



Output Format
Return a single integer denoting the length of longest path in the matrix if no such path exists return -1.



Example Input
Input 1:

 A = [  [1, 2]
        [3, 4]
     ]
Input 2:

 A = [  [1, 2, 3, 4]
        [2, 2, 3, 4]
        [3, 2, 3, 4]
        [4, 5, 6, 7]
     ]


Example Output
Output 1:

 3
Output 2:

 7


Example Explanation
Explanation 1:

 Longest path is either 1 2 4 or 1 3 4.
Explanation 2:

 Longest path is 1 2 3 4 5 6 7.





  
*/  
'''
  
  
CODE





//to check whether the path exists or not
void dfs(int i,int j,int n,int m,vector<vector<int>>& vis,vector<vector<int>>& A){
    vis[i][j]=1;
    if(i+1<=n-1 && vis[i+1][j]==0 && A[i+1][j]>A[i][j])
        dfs(i+1,j,n,m,vis,A);
    if(j+1<=m-1 && vis[i][j+1]==0 && A[i][j+1]>A[i][j])
        dfs(i,j+1,n,m,vis,A);
}

int Solution::solve(vector<vector<int>> &A) {
    int n=A.size(),m=A[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    dfs(0,0,n,m,vis,A);
    //there will exist only two solutions
    //if path exists the n+m-1
    if(vis[n-1][m-1]==1)
        return n+m-1;
    //if no then return -1
    else
        return -1;

}
