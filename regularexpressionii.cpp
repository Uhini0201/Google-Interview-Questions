'''
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.

'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

'''

##Code

int Solution::isMatch(const string A, const string B) {
    int R=A.length(),C=B.length();
    //to store the values of the subproblems
    vector<vector<bool>>dp(R+1,vector<bool>(C+1,false));
    //the empty space is always true
    dp[0][0]=true;
    //we are checking the previous element
    for(int i=2;i<=C;i++)
        //if it is equal to '*' which means it should be the same as 
        //its preceding elements match
        if(B[i-1]=='*')
            dp[0][i]=dp[0][i-2];
    //the outer loop runs for string a
    for(int i=1;i<=R;i++){
        //this is for string b
        for(int j=1;j<=C;j++){
            //if equal or having a '.' then we do nothing, we just store the previous
            //values stired
            if(A[i-1]==B[j-1] || B[j-1]=='.')dp[i][j]=dp[i-1][j-1];
            //if equal to a '*' then we store its previous value
            //or preceding elements match
            else if(B[j-1]=='*'){
                dp[i][j]=dp[i][j-2];
                //if the preceding and the next of it are same or we have a 
                //'.' then we take the max of the two of the previous characters
                //in the inital string.
                if(A[i-1]==B[j-2] || B[j-2]=='.')dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
    }
    //the last indexes will give the final answer 
    return dp[R][C];
}

