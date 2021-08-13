'''
/*

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 

Given array S = {1 0 -1 0 -2 2}, and target = 0

A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.

Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

*/
'''


CODE

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>>ans;
    sort(A.begin(),A.end());
    int n=A.size();
    for(int i=0;i<n-3;i++)
    {
        if(i>0 && A[i]==A[i-1])
        {
            continue;
        }
        for(int j=i+1;j<n-2;j++)
        {
            if(j>i+1 && A[j]==A[j-1])
            {
                continue;
            }
            int k=j+1,l=n-1;
            while(k<l)
            {
                int sum=A[i]+A[j]+A[k]+A[l];
                if(sum==B)
                {
                    ans.push_back({A[i],A[j],A[k],A[l]});
                    int currVal=A[k];
                    while(k<n && A[k]==currVal)
                    {
                        k++;
                    }
                    currVal=A[l];
                    while(l>=0 && A[l]==currVal)
                    {
                        l--;
                    }
                }
                else if(sum<B)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}
