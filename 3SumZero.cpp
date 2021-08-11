'''
/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 

Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:

  (-1, 0, 1)

  (-1, -1, 2)

*/
'''

CODE

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    vector<vector<int>> ans;
    for(int i = 0; i < n - 2; ++i){
        if(i > 0 && A[i] == A[i - 1])
            continue;
        int l = i + 1, r = n - 1;

        while(l < r){
            // long long sum = A[i] + (long long)A[l] + (long long)A[r];
            long long sum = 0LL + A[i] + A[l] + A[r];
            if(sum == 0){
                ans.push_back({A[i], A[l], A[r]});
                while(l < n - 1 && A[l] == A[l + 1])
                    ++l;
                while(r > 0 && A[r] == A[r - 1])
                    --r;
                ++l, --r;
            }
            else if(sum > 0)
                --r;
            else
                ++l;
        }
    }
    return ans;
}
