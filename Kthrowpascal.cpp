'''
Problem Description

Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3


Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?
  
'''


# Code

vector<int> Solution::getRow(int A) {
    vector<int>v;
    v.push_back(1);//NC0
    int p=1;
    //NCi=NCi-1*(N-i+1) / i
    for(int i=1;i<=A;i++){
        int c=(p*(A-i+1))/i;
        v.push_back(c);
        p=c;
    }
    return v;
}
