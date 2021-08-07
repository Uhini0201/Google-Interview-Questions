'''
/*

Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Note : Make sure the strings are sorted in your result.

Input Format:

The first argument is a string, A.
The second argument is an array of strings, B.
Output Format:

Return a vector of strings representing the answer as described in the problem statement.
Constraints:

1 <= len(A) <= 50
1 <= len(B) <= 25
1 <= len(B[i]) <= 20
Examples:

Input 1:
    A = "b"
    B = ["aabbb"]

Output 1:
    []

Input 1:
    A = "catsanddog",
    B = ["cat", "cats", "and", "sand", "dog"]

Output 1:
    ["cat sand dog", "cats and dog"]



*/
'''


Code

void find(string A,unordered_set<string>mp,string ans, vector<string> &res){
    for(int i=1;i<=A.size();i++){
        string word=A.substr(0,i);
        //if prefix string is found
        if(mp.find(word)!=mp.end()){
            //if we have reached the end of the string
            //then we add it to the vector and return it
            if(i==A.size()){
                ans+=word;
                res.push_back(ans);
                return;
            }
            //if found but we haven't reached the end
            //then we call the recursive function by passing the updated string
            find(A.substr(i,A.size()-i),mp,ans+word+" ",res);
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> mp;
    //so that the words are sorted acc to the first character
    for(auto i:B){
        mp.insert(i);
    }
    string ans="";
    vector<string>result;
    //it will return the final vector
    find(A,mp,ans,result);
    return result;
}
