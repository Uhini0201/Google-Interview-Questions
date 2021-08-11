'''
/*

Problem Description

Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.


*/
'''

CODE

int Solution::majorityElement(const vector<int> &A) {
    map<int,int>mp;
    for(int i=0;i<A.size();i++){
        mp[A[i]]++;
    }
    for(auto i:mp){
        if(i.second>floor(A.size()/2)){
            return i.first;
        }
    }
}
