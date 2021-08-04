'''
  Given 2 integers A and B and an array of integars C of size N.

Element C[i] represents length of ith board.

You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.

Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003
'''
  
## Code
  
  bool isvalid(vector<int>&C, int mid,int A)
{  int i;
    int sum=0;
    int j=1;
    for(i=0;i<C.size();i++)
    {
        //if the current sum is greater than the threshold, then the current board
        //is the next count's start value
    if(sum+C[i]>mid)
    {
        j++;
        sum=C[i];
       
    }
    //update
    else{
        sum+=C[i];
    }
    //if painters required is more than the given
     if(j>A)
        {
            return false;
        }
    }
    return true;
}


int Solution::paint(int A, int B, vector<int> &C) {
    int i,l,r;
    int maxi=INT_MIN;
    int sum=0;
    for(i=0;i<C.size();i++)
    {
      if(maxi<C[i])
      {
          maxi=C[i];
      }
        sum=sum+C[i];
    }
   //the lowest time taken will be the maximum board to be painted by one painter
    l=maxi;
    r=sum;
     if(C.size()<=A)
    {
        return (l*B)%10000003;
    }
    long long ans=l;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        //if the minimum is on the left part we shift to it
        if(isvalid(C,mid,A))
        {
            ans=mid;
            r=mid-1;
        }
        //if more than the maximum time taken then the optimum is in the right
        else
        {
            l=mid+1;
        }
    }
    return (ans*B)%10000003;
}
