'''
/*

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: 

Given [100, 4, 200, 1, 3, 2],

The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/
'''



CODE

int Solution::longestConsecutive(const vector<int> &A) {
    map<int,int>mp;
    for(auto i: A){
        mp[i]++;
    }
    int c=1,ans=1;
    for(auto i:mp){
        if(mp.find(i.first+1)!=mp.end()){
            c++;
        }
        else{
            ans=max(ans,c);
            c=1;
        }
    }
    return max(ans,c);
}
