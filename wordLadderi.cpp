'''
/*

Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains an array of strings, C.
Output Format:

Return an integer representing the minimum number of steps required to change string A to string B.
Constraints:

1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5e3
Example :

Input 1:
    A = "hit"
    B = "cog"
    C = ["hot", "dot", "dog", "lot", "log"]

Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"

*/
'''

CODE

int Solution::solve(string A, string B, vector<string> &C) {
     unordered_set<string> wordSet; // will contain all the words from dict
    bool isPresent = true; // checks if endword(B) is there in dict
    
    for(auto word: C){
        if(B.compare(word) == 0) isPresent = true;
        wordSet.insert(word);
    }
    if(!isPresent) return 0; // end word is not there in dict
    
    queue<string> q; // for BFS graph traversal
    q.push(A);
    int depth = 0;
    
    while(!q.empty()){
        depth+=1;
        int N = q.size(); // no. of ele in current level of graph
        while(N--){
            string curr = q.front(); q.pop();
            // replace all letters in curr word and check these condt
            for(int i = 0; i<curr.size(); i++){
                string temp = curr;
                for(char c = 'a'; c<='z'; c++){
                    temp[i] = c;
                    // if curr and new temp word(with a letter replaced) are same
                    // then continue and do not add duplicate into queue
                    if(curr.compare(temp) == 0) continue; 
                    // it is established that temp is diff from curr
                    // now if temp = B(end word) return depth+1
                    // as this endword is obviously coming in the next level from 
                    // where we are now
                    if(temp.compare(B) == 0) return depth+1;
                    // if temp word is also present in wordSet, then insert into q
                    // and delete it from wordSet
                    if(wordSet.find(temp) != wordSet.end()){
                        q.push(temp); wordSet.erase(temp);
                    }
                }
                
            }
        }
    }
}
