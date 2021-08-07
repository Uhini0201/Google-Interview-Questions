'''
// Problem Description

// Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

// i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

// NOTE: Sub-sequence length should be greater than or equal to 2.



// Problem Constraints
//  1 <= |A| <= 100



// Input Format
// The first and the only argument of input contains a string A.



// Output Format
// Return an integer, 0 or 1:

//     => 0 : False
//     => 1 : True


// Example Input
// Input 1:

//  A = "abab"
// Input 2:

//  A = "abba"


// Example Output
// Output 1:

//  1
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  "ab" is repeated.
// Explanation 2:

//  There is no repeating subsequence.

'''


Code

int Solution::anytwo(string A) {
    int n=A.size();
    int dp[n+1][n+1];//to store the values of the sub problems
    memset(dp,0,sizeof(dp));

    //traverse through the string 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //if the characters match but the indexes doesn't
            if(A[i-1]==A[j-1] && i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    //if present return true
    if(dp[n][n]>=2)
        return 1;
    else
        return 0;
}
