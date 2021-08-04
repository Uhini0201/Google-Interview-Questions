'''
Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.



Input Format:

The first and the only argument contains the string A.
Output Format:

Return an integer, representing the answer as described in the problem statement.
Constraints:

1 <= length(A) <= 501
Examples:

Input 1:
    A = "aba"

Output 1:
    0

Explanation 1:
    "aba" is already a palindrome, so no cuts are needed.

Input 2:
    A = "aab"
    
Output 2:
    1

Explanation 2:
    Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
'''


## Code
      
      //to check for the pallindrome 
bool is_pallindrome(string a,int l,int r){
    int i=l,j=r;
    while(i<=j){
        if(a[i]!=a[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
string B;
int dp[1002][1002];//the both indexes means the subtring from the first to the 2nd
//to count the minimum cuts needed in the string
int find(string A,int l,int r){
    //if the total is passed(the base case)
    if(r==A.size()){
        //if not a pallindrome the A.size()-1 is the minimum cut needed
        if(!is_pallindrome(A,l,r-1)){
            return 1<<30;
        }
        else{//if pallindrome no cut needed
            return 0;
        }
    }
    if(dp[l][r]){
        return dp[l][r];
    }
    //if the current substring is a pallindrome
    if(is_pallindrome(A,l,r)){//the value of the string from l to r is the minimum 
    //of the 1+substring from r+1 and from substring l to r+1 
        return dp[l][r]=min(1+find(A,r+1,r+1),find(A,l,r+1));
    }
    else{
        //if not a substring then the r is incremented keeping the starting index constant
        return dp[l][r]=find(A,l,r+1);
    }
}
int Solution::minCut(string A) {
    B=A;
    int mini=A.size()-1;
    int l=0,r=A.size()-1;
    memset(dp,0,sizeof(dp));//to store the minimum cuts needed
    return min(mini,find(A,0,0));
}
