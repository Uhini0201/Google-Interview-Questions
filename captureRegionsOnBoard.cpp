'''
/*

Problem Description

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 103



Input Format
First and only argument 2D character matrix A of size N X M.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]


Example Output
Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]


Example Explanation
Explanation 1:

 'O' in (4,2) is not surrounded by X from below.


*/
'''

CODE


bool vis[1002][1002];
vector<vector<char> >v;
int r,c;
void dfs(int i,int j){
    if(vis[i][j])
        return;
    if(i>=r||i<0||j<0||j>=c)
        return;
    if(v[i][j]=='X')
        return;
    vis[i][j]=true;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}
void Solution::solve(vector<vector<char> > &A) {
    memset(vis,0,sizeof(vis));
    r=A.size();
    c=A[0].size();
    v=A;
    for(int i=0;i<c;i++){
        if(A[0][i]=='O')
            dfs(0,i);
        if(A[r-1][i]=='O')
            dfs(r-1,i);
    }
    for(int i=0;i<r;i++){
        if(A[i][0]=='O')
            dfs(i,0);
        if(A[i][c-1]=='O')
            dfs(i,c-1);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!vis[i][j])
                A[i][j]='X';
        }
    }
}
