'''
/*
Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note:  elements might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output

2

Explanation

-8 5 7

3 7 -8

5 -8 9

-8 5 7

3 7 -8

5 -8 9


*/
'''

Code

int Solution::solve(vector<vector<int> > &A) {
    //base cases
    if(A.size()==0 || A[0].size()==0) return 0;
    int dp[A.size()+1][A[0].size()+1];
    int n=A.size(),m=A[0].size();
    //forming the table to store the sub problems
    for(int i=0;i<=n;i++) 
        for(int j=0;j<=m;j++) 
            dp[i][j]=0;
    //the cost of the
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) {
            //the calculations of the prefix sums such that we include every
            //element exactly once and we are excluding i-1 and j-1 since it has
            //both the values of i-1 and j-1.
            dp[i][j]+=A[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    int ans=0;
    //here we are fixing two rows to calculate sum of A[0..i] and A[0..j]
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++) {
            //column wise
            int a[m+1];
            for(int k=0;k<=m;k++) 
            {
                //the sum of A[0..j]-A[0..i] at the kth column
                a[k] = dp[j][k]-dp[i][k];
            }
            sort(a,a+m+1);
            int c=1;
            for(int k=1;k<=m;k++){
                //it means that if both the sums are same
                //i.e A[0...j] and A[j+1...i] 
                if(a[k]==a[k-1])
                    c++;
                //if not same, we just count them and set it to 1
                else {
                    ans+=(c*(c-1))/2;
                    c=1;
                }
            }
            //then we add it to the final
            ans+=(c*(c-1))/2;  
        }
    }
    return ans;
}
