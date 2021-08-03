'''
  Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].




Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

 Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Constraints

1 <= N <= 10^6
1 <= A[i], B <= 10^9
For Example

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]
'''

  
  # Code
  
  vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int l=0,r=A.size(),mid;
    int st=-1,end=-1;
    vector<int>v(2);
    // Lower Bound
    while(l<r){
        mid = (l+r)/2; 
        if(A[mid]>=B) r = mid; 
        else l=mid+1;
    }
    if(r>=A.size()||A[r]!=B) return {-1,-1};
    st=r; 
    v[0]=st;
    // Upper Bound
    l=0,r=A.size();
    while(l<r){
        mid = (l+r)/2; 
        if(A[mid]<=B) l=mid+1; 
        else r=mid;
    }
    end = l-1;
    v[1]=end;
    return v;
}

      
