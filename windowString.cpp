'''
/*

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.

Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

Note:

If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

*/
'''

CODE

string Solution::minWindow(string A, string B) {

string ans;

if(B.length()>A.length())
//return null string
return ans;

//keeping the count of the final string to be searched
unordered_map<char,int> m;
for(auto c: B)
m[c]++;

int n=B.length();
int max=INT_MAX;
int p1=0,p2=0,flag=0;
unordered_map<char,int> freq;
int start=0,end=0,count=0;

for(int i=0; i<A.length(); i++)
{
    if(m.find(A[i])!=m.end())
    {
      //updating the frequency when b is present at a
        freq[A[i]]++;
        //if freq of b is less than a , we ommit that b and search for a new one
        if(freq[A[i]]<=m[A[i]])
        {count++;}
    }
    //if we have got all the characters of b in a
    if(count==n)
    {
        flag++;
        //we iterate from the start of the current substring
        while(start<end)
        {
            if(freq.find(A[start])!=freq.end())
            {
              //if found that he freq is more than the required, we reduce it 
              //so as to include only those needed.
                if(freq[A[start]]>m[A[start]])
                freq[A[start]]--;
                else
                break;
            }
            //this will execute untl we get the freq same as that of required 
            //or tleast the minumum greatest
            start++;
        }
        if(max>(end-start+1))
        {
          //we keep a note of the start and end of the substring
            max=end-start+1;
            p1=start;
            p2=end;
        }
    }
    end++;
}
if(flag==0)
return ans;
for(int i=p1; i<=p2; i++)
ans.push_back(A[i]);

return ans;
}
