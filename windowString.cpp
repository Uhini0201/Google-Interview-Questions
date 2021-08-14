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

    //keeping the c of the final string to be searched
    unordered_map<char,int> m;
    for(auto c: B)
        m[c]++;

    int n=B.length();
    int maxi=INT_MAX;
    int final_s=0,final_e=0,flag=0;
    unordered_map<char,int> f;
    int l=0,r=0,c=0;

    for(int i=0; i<A.length(); i++){
        if(m.find(A[i])!=m.end()){
        //updating the fuency when b is present at a
            f[A[i]]++;
            //if f of b is less than a , we ommit that b and search for a new one
            if(f[A[i]]<=m[A[i]]){
                c++;
            }
        }
        //if we have got all the characters of b in a
        if(c==n){
            flag++;
            //we iterate from the l of the current substring
            while(l<r){
                if(f.find(A[l])!=f.end()){
                //if found that he f is more than the required, we reduce it 
                //so as to include only those needed.
                    if(f[A[l]]>m[A[l]])
                        f[A[l]]--;
                    else
                        break;
                }
                //this will execute untl we get the f same as that of required 
                //or tleast the minumum greatest
                l++;
            }
            if(maxi>(r-l+1)){
            //we keep a note of the l and r of the substring
                maxi=r-l+1;
                final_s=l;
                final_e=r;
            }
        }
        r++;
    }
    if(flag==0)
        return ans;
    for(int i=final_s; i<=final_e; i++)
        ans.push_back(A[i]);
    return ans;
}
